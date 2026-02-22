#include "sata.hpp"

namespace KRN::DRV
{


SataHDD::SataHDD(): 
present_(false), 
sector_size_(512), 
sectors_(0), 
cache_(nullptr),
sign_1(0),
sign_2(0){
    ;
}

SataHDD::~SataHDD(){
    if (cache_) delete[] cache_;
}

u8 SataHDD::isPresent() const{
    return present_;
}// Port I/O helpers (x86/x86_64)

static inline void outl(u16 port, u32 val){
    asm volatile ("outl %0, %w1" : : "a"(val), "Nd"(port));
}

static inline u32 inl(u16 port){
    u32 val;
    asm volatile ("inl %w1, %0" : "=a"(val) : "Nd"(port));
    return val;
}

// Read 32-bit from PCI config space using CONFIG_ADDRESS (0xCF8) / CONFIG_DATA (0xCFC)
static u32 pciConfigRead32(u8 bus, u8 device, u8 func, u8 offset){
    u32 address = 0x80000000u
        | ((u32)bus << 16)
        | ((u32)device << 11)
        | ((u32)func << 8)
        | (offset & 0xFC);
    outl(0xCF8, address);
    return inl(0xCFC);
}

// Probe PCI bus for AHCI-capable controller and return MMIO base (BAR5) or 0 on not found.
static u32 probe_ahci_mmio(){
    for (u8 bus = 0; bus < 255; ++bus) {
        for (u8 dev = 0; dev < 32; ++dev) {
            for (u8 fn = 0; fn < 8; ++fn) {
                u32 v = pciConfigRead32(bus, dev, fn, 0x00);
                u16 vendor = v & 0xFFFFu;
                if (vendor == 0xFFFFu) continue;
                u32 cls = pciConfigRead32(bus, dev, fn, 0x08);
                u8 baseClass = (cls >> 24) & 0xFFu;
                u8 subClass = (cls >> 16) & 0xFFu;
                u8 progIf = (cls >> 8) & 0xFFu;
                // AHCI: base class 0x01 (mass storage), subClass 0x06 (SATA), prog-if 0x01 (AHCI)
                if (baseClass == 0x01 && subClass == 0x06 && (progIf == 0x01 || progIf == 0x00)) {
                    // Read BAR5 at offset 0x24
                    u32 bar5 = pciConfigRead32(bus, dev, fn, 0x24);
                    // If BAR is memory mapped, mask low bits
                    u32 mmio = bar5 & 0xFFFFFFF0u;
                    if (mmio) return mmio;
                }
                // if not multifunction, break fn loop after fn0
                if (fn == 0) {
                    u32 hdr = pciConfigRead32(bus, dev, fn, 0x0C);
                    // header type bit 7 indicates multifunction
                    if (((hdr >> 16) & 0x0080u) == 0) break;
                }
            }
        }
    }
    return 0;
}

void SataHDD::init(){
    // Probe PCI for AHCI controller and record MMIO base
    u32 mmio = probe_ahci_mmio();
    if (mmio != 0) {
    if (present_) {
        // Read implemented ports (PI) from HBA memory
        auto readReg = [&](u32 off)->u32 {
            volatile u32* addr = reinterpret_cast<volatile u32*>((uintptr_t)mmio_base_ + off);
            return *addr;
        };
        port_implemented_mask_ = readReg(0x0C);
        // enumerate ports
        port_count_ = 0;
        for (u32 i = 0; i < 32; ++i) {
            if ((port_implemented_mask_ >> i) & 1u) {
                // read PxSSTS at offset 0x100 + i*0x80 + 0x28
                u32 pbase = 0x100 + i * 0x80;
                u32 ssts = readReg(pbase + 0x28);
                u8 det = ssts & 0x0Fu;
                u8 ipm = (ssts >> 8) & 0x0Fu;
                // DET == 3 and IPM == 1 indicates device present and active
                if (det == 3 && ipm == 1) {
                    port_count_++;
                }
            }
        }
        // init per-port pointers
        for (int i=0;i<32;++i) port_cmdlist_[i] = nullptr;
    }
    if (present_) {
        // TODO: perform hardware read via AHCI using mmio_base_
    }
    } else {
        present_ = false;
    }
}// Basic register access helpers for AHCI MMIO

inline volatile u32* abar_ptr(u32 mmio_base, u32 offset){
    return reinterpret_cast<volatile u32*>((uintptr_t)mmio_base + offset);
}

void SataHDD::setupPort(u32 port_index)
{
    if (!present_){
        sign_1 = (char )0xFF;
        return;
    }
    if (port_index >= 32){
        sign_1 = (char )0xFF;
        return;
    }
    if (((port_implemented_mask_ >> port_index) & 1u) == 0){
        sign_1 = (char )0xFF;
        return;
    }
    // allocate command list (1K) and fis receive area (256)
    const size_t CL_SIZE = 1024;
    const size_t FB_SIZE = 256;
    void* cl = nullptr;
    void* fb = nullptr;
    try {
        cl = new u8[CL_SIZE];
        fb = new u8[FB_SIZE];
    } catch(...) {
        if (cl) delete[] reinterpret_cast<u8*>(cl);
        if (fb) delete[] reinterpret_cast<u8*>(fb);
        sign_1 = (char )0xFF;
        return ;
    }
    // zero
    ::memset(cl, 0, CL_SIZE);
    ::memset(fb, 0, FB_SIZE);

    // write to PxCLB and PxFB (lower 32-bit)
    u32 pbase = 0x100 + port_index * 0x80;
    *abar_ptr(mmio_base_, pbase + 0x00) = (u32)(uintptr_t)cl;
    *abar_ptr(mmio_base_, pbase + 0x08) = (u32)(uintptr_t)fb;

    port_cmdlist_[port_index] = cl;
    return ;
}

void SataHDD::stopPort(u32 port_index){
    if (!present_){
        sign_1 = (char )0xFF;
        return ;
    }
    u32 pbase = 0x100 + port_index * 0x80;
    volatile u32* pxcmd = abar_ptr(mmio_base_, pbase + 0x18);
    // clear ST and FRE
    u32 cmd = *pxcmd;
    cmd &= ~0x1u;    // ST
    cmd &= ~0x10u;   // FRE
    *pxcmd = cmd;
    // wait for CR cleared
    for (int i=0;i<1000000;++i) {
        u32 c = *pxcmd;
        if ((c & 0x8000u) == 0) return ; // CR cleared
    }
    sign_1 = (char )0xFF;
    return ;
}

void SataHDD::startPort(u32 port_index)
{
    if (!present_) {
        sign_1 = (char )0xFF;
        return ;
    }
    u32 pbase = 0x100 + port_index * 0x80;
    volatile u32* pxcmd = abar_ptr(mmio_base_, pbase + 0x18);
    // set FRE then ST
    u32 cmd = *pxcmd;
    cmd |= 0x10u; // FRE
    *pxcmd = cmd;
    cmd |= 0x1u; // ST
    *pxcmd = cmd;
    // optionally wait for FR/CR bits
    return ;
}

void SataHDD::submitCommand(u32 port_index, u32 slot)
{
    if (!present_) {
        sign_1 = (char )0xFF;
        return ;
    }
    if (port_index >= 32 || slot >= 32) {
        sign_1 = (char )0xFF;
        return ;
    }
    u32 pbase = 0x100 + port_index * 0x80;
    volatile u32* pxci = abar_ptr(mmio_base_, pbase + 0x38);
    // set command issue bit
    *pxci = (1u << slot);
    // wait for completion
    for (int i=0;i<1000000;++i) {
        u32 v = *pxci;
        if ((v & (1u << slot)) == 0) return ; // command completed
    }
    sign_1 = (char )0xFF;
    return ;
}
//        return false;
//    }
//
//    if (!cache_) return false;
//    size_t offset = (size_t)lba * sector_size_;
//    if (offset + bytes > (size_t)sectors_ * sector_size_) return false;
//    ::memcpy(buffer, cache_ + offset, bytes);
//    return true;
//}

void SataHDD::writeLBA(
    u64 lba, 
    u32 count, 
    const void* buffer
){
    if (!buffer){
        return ;
    }
    size_t bytes = (size_t)count * sector_size_;

    if (present_){
        // TODO: perform hardware write via AHCI using mmio_base_
        sign_1 = (char )0xFF;
        return ;
    }

    if (!cache_){
        sign_1 = (char )0xFF;
        return ;
    }
    size_t offset = (size_t)lba * sector_size_;
    if (offset + bytes > (size_t)sectors_ * sector_size_){
        sign_1 = (char )0xFF;
        return ;
    }
    ::memcpy(cache_ + offset, buffer, bytes);
    return ;
}

void SataHDD::allocateFallback(
    u64 sectors, 
    u32 sector_size
){
    if (cache_) delete[] cache_;
    if (sectors == 0 || sector_size == 0){
        sign_1 = (char )0xFF;
        return ;
    }
    // allocate fallback cache using operator new[] which maps to kernel allocator
    size_t total = (size_t)sectors * sector_size;
    try {
        cache_ = new u8[total];
    } catch (...) {
        cache_ = nullptr;
        sectors_ = 0;
        sector_size_ = 0;
        sign_1 = (char )0xFF;
        return ;
    }
    ::memset(cache_, 0, total);
    sectors_ = sectors;
    sector_size_ = sector_size;
    present_ = false; // fallback only
    return ;
}

u32 SataHDD::sectorSize() const { 
    return sector_size_; 
}
u64 SataHDD::sectorsCount() const { 
    return sectors_; 
}
u32 SataHDD::mmioBase() const { 
    return mmio_base_; 
}
    
} // namespace KRN::DRV::SATAHDD