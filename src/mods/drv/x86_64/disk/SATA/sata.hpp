#pragma once
#include <global/main.hpp>
#include <libs/memop/mop.hpp>

namespace KRN::DRV
{


class SataHDD {
public:
    SataHDD();
    ~SataHDD();

    // Initialize driver (probe hardware). Returns true on success (driver loaded).
    void init();

    // Whether a real device was found and is usable.
    u8 isPresent() const;

    // Identify device (fill geometry). Returns false if no device.
    void identify();

    // Read/Write LBA sectors. `count` is number of sectors.
    void readLBA(u64 lba, u32 count, void* buffer);
    void writeLBA(u64 lba, u32 count, const void* buffer);

    // Fallback in-memory cache allocator for testing without hardware.
    void allocateFallback(u64 sectors, u32 sector_size = 512);

    // Start/stop port command engine and allocate per-port resources
    void setupPort(u32 port_index);
    void startPort(u32 port_index);
    void stopPort(u32 port_index);

    // Submit a command by slot; higher-level code must populate CL/CT structures.
    void submitCommand(u32 port_index, u32 slot);

    u32 sectorSize() const;
    u64 sectorsCount() const;
    // MMIO base for AHCI registers (if detected)
    u32 mmioBase() const;

private:
    void* port_cmdlist_[32];
    u8* cache_; // optional fallback storage
    u64 sectors_;
    u32 sector_size_;
    u32 mmio_base_;
    u32 port_implemented_mask_;
    u8 present_;
    u8 port_count_;
    // per-port command list virtual pointers (simple storage)
    u8 sign_1;
    u8 sign_2;
};

    
} // namespace KRN::DRV::SATAHDD