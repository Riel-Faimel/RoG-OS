#include <mods/drv/x86_64/basic/io.hpp>
#include <global/log.hpp>
#include <global/log.hpp>


namespace KRN::DRV {
    class IDE_DISK{
    public:
        enum Chan{
            MASTER_C = 0x1F0,
            SLAVE_C = 0x170
        };
        enum Dev{
            MASTER = 0xE0,
            SLAVE = 0xF0
        };
        IDE_DISK() = delete;
        IDE_DISK(Chan chan, Dev dev);
        ~IDE_DISK();

        void check();

        void read(unsigned short *buf, unsigned LBA, unsigned char count, bool no_print = true);

        void write(unsigned short *buf, unsigned LBA, unsigned char count, bool no_print = true);
    };
}