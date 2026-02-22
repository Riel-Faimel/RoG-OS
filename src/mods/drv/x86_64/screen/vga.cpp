#include "vga.hpp"
namespace KRN::DRV {
    class VGA{
    #define LINE_SIZE 80
    #define LINE_NUM 25
        unsigned short * buffer = (unsigned short *)0x000B8000;
        static constexpr unsigned int size = 0xBFFFF - 0xB8000;
        unsigned line = 0;
    public:
        VGA(){}
        ~VGA() = default;

        void full(unsigned char data, unsigned char attr = 0x1F){
            for (unsigned i = 0;i < LINE_SIZE * LINE_NUM;i++){
                buffer[i] = attr << 8 | data;
            }
        }

        void clear(){
            full(' ', 0x1F);
        }

        void push(){
            unsigned i = 0;
            for(;i < LINE_NUM - 1;i++){
                for(unsigned j = 0;j < LINE_SIZE;j++){
                    buffer[LINE_SIZE * i + j] = buffer[LINE_SIZE * (i + 1) + j];
                }
            }
            for(unsigned j = 0;j < LINE_SIZE;j++){
                buffer[LINE_SIZE * i + j] = 0x1F00 | ' ';
            }
        }

        void print(const char *str, unsigned char attr = 0x1F){
            unsigned len = 0;
            for(;str[len];len++);
            line += len / LINE_SIZE + 1;
            if(line >= LINE_NUM - 1){
                for(unsigned i = 0;i < line - (LINE_NUM - 1);i++){
                    push();
                    line--;
                }
            }
            for(unsigned i = 0;i < len;i++){
                buffer[(line - 1) * LINE_SIZE + i] = attr << 8 | str[i];
            };
        }

    private:
    //debug
        void pt(const char *str, unsigned offset = 0){
            for(unsigned i = 0;str[i];i++){
                buffer[offset + i] = 0x1F00 | str[i];
            }
        }
    };
}