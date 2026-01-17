#pragma once
#include <modf/modifier.hpp>

//namespace KRN::MODF
//{
//    class Modf;
//    extern Modf modf;
//} // namespace KRN::MODF
//

namespace KRN
{
    class KRN::MODF::Modf;
    extern KRN::MODF::Modf modf;
    enum class MODE {
        NO = -1,
        READ = 0,
        R_W = 1,
        WRITE = 2
    };
    
    template<unsigned N>
    class Window{
    private:
        unsigned id;
        unsigned buffer_size;
        MODE mode;
        unsigned char sign;
    public:
        BYTE buffer[N];

        Window():
        buffer_size(N),
        sign(0){
            modf.regist_window<N>(mode, id);
        }
        ~Window(){
            modf.clear_window(id);
        }

        inline BYTE operator[](unsigned offset){
            return buffer[offset];
        }
        inline const BYTE operator[](unsigned offset)const{
            return buffer[offset];
        };
        
        void set_mode(MODE target){
            modf.deal_mode<N>(this->mode, target, id);
        }
    };
    
} // namespace KRN

