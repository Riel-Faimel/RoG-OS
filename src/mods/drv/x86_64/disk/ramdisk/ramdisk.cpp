#include "ramdisk.hpp"

namespace KRN::DRV
{
RamDisk::RamDisk(size_t size) {
    ;
}
RamDisk::~RamDisk() {
    ;
}
void RamDisk::read(size_t offset, void* buffer, size_t size) {
    memcpy(buffer, static_cast<char*>(data) + offset, size);
}
void RamDisk::write(size_t offset, const void* buffer, size_t size) {
    memcpy(static_cast<char*>(data) + offset, buffer, size);
}
size_t RamDisk::getSize() const {
    return 512 * 1024 * 1024; // 512 MB
}
}