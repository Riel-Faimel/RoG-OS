#include <global/main.hpp>
namespace KRN::DRV{
    class VGA{
    public:
        VGA(){}
        ~VGA() = default;

        void full(unsigned char data, unsigned char attr = 0x1F);

        void clear();

        void push();

        void print(const char *str, unsigned char attr = 0x1F);
    };
}

void kprint (STXT warning_msg);