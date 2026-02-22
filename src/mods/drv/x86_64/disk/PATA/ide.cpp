#include "ide.hpp"

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
    private:
        Chan chan;
        Dev dev;
    public:
        IDE_DISK() = delete;
        IDE_DISK(Chan chan, Dev dev):chan(chan), dev(dev){}
        ~IDE_DISK(){};

        void check(){
            for(int i = 0; i < 100000; i++) volatile int x = 0;
            
            unsigned char status = inb(chan + 7);
            
            if (status & 0x80) {
                kprint("BSY");
            } else if (status & 0x40) {
                kprint("DRDY");
            } else if (status & 0x20) {
                kprint("DF");
            } else if (status & 0x10) {
                kprint("DSC");
            } else if (status & 0x08) {
                kprint("DRQ");
            } else if (status & 0x04) {
                kprint("CORR");
            } else if (status & 0x02) {
                kprint("IDX");
            } else if (status & 0x01) {
                kprint("ERR");
            } else {
                kprint("IDLE");
            }
            kprint("======");
        }

        void read(unsigned short *buf, unsigned LBA, unsigned char count, bool no_print = true){
            unsigned char status = inb(chan + 7);
            if(status & 0x80){
                qps("Not Ready\n");
                qpl(status);
                qps("\n");
                while ((inb(chan + 7) & 0x80));    
            }
            outb(count, chan + 2);
            outb(LBA & 0xFF, chan + 3);
            outb((LBA >> 8) & 0xFF, chan + 4);
            outb((LBA >> 16) & 0xFF, chan + 5);
            outb(dev | ((LBA >> 24) & 0x0F), chan + 6);
            outb(0x20, chan + 7);

            for(unsigned char fan = 0;fan < count;fan++){
                unsigned i = 0;
                while (!(inb(chan + 7) & 0x08)){
                    i++;
                    if(i > 10000){
                        kprint("Time out");
                        break;
                    }
                };
                for(unsigned int i = 0;i < 256;i++){
                    buf[i + fan * 256] = inw(chan);
                }
            }
            if(no_print)return ;
            qps("Read Done\n");
        }

        void write(unsigned short *buf, unsigned LBA, unsigned char count, bool no_print = true){
            unsigned char status = inb(chan + 7);
            if(status & 0x80){
                qps("Not Ready\n");
                qpl(status);
                qps("\n");
                while ((inb(chan + 7) & 0x80));        
            }
            outb(count, chan + 2);
            outb(LBA & 0xFF, chan + 3);
            outb((LBA >> 8) & 0xFF, chan + 4);
            outb((LBA >> 16) & 0xFF, chan + 5);
            outb(dev | ((LBA >> 24) & 0x0F), chan + 6);
            outb(0x30, chan + 7);

            for(unsigned char fan = 0;fan < count;fan++){
                unsigned i = 0;
                while (!(inb(chan + 7) & 0x08)){
                    i++;
                    if(i > 10000){
                        kprint("Time out");
                        break;
                    }
                };
                for(unsigned int i = 0;i < 256;i++){
                    outw(buf[i + fan * 256], chan);
                }
            }
            if(no_print)return ;
            qps("Write Done\n");
        }
    };
}