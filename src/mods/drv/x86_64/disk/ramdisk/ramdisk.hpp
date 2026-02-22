#include <global/main.hpp>
#include <libs/memop/mop.hpp>

namespace KRN::DRV
{
class RamDisk {
public:
    RamDisk(size_t size);
    ~RamDisk();

    void read(size_t offset, void* buffer, size_t size);
    void write(size_t offset, const void* buffer, size_t size);

    size_t getSize() const;
private:
    char data[512 * 1024 * 1024]; // 512 MB ramdisk
};
}