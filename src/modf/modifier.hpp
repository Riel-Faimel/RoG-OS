#include "../global/main.hpp"
#include "../global/log.hpp"

namespace KRN
{
    template<unsigned N>
    class Window{
    private:
        enum MODE {
            NO,
            READ,
            R_W,
            WRITE
        };
        unsigned id;
        unsigned buffer_size;
        MODE mode;
        unsigned char sign;
    public:
        BYTE (&buffer)[N];

        Window(unsigned char (&buffer)[N]);
        ~Window();

        Window() = delete;
        
        BYTE operator[](unsigned);
        const BYTE operator[](unsigned)const;
        
        void set_mode(MODE target);
    };
    
} // namespace KRN


namespace KRN::MODF
{
    class Modf {
public:
        Modf();
        ~Modf();
        
        template<unsigned N>
        void regist_window(enum KRN::Window<N>::MODE (&mode), unsigned int (&id));
    };

    extern Modf modf;
} // namespace KRN::MODF
