#include "modifier.hpp"

namespace KRN::MODF
{
    Modf::Modf(){
        ;
    };

    Modf::~Modf(){
        ;
    };

    template<unsigned int N> 
    void regist_window(enum KRN::Window<N>::MODE (&mode), unsigned int (&id)){
        ;
    };
    Modf modf;
} // namespace KRN::MODF

namespace KRN
{
    using KRN::MODF::modf;

    template<unsigned N>
    Window<N>::Window(unsigned char (&buffer_in)[N]):
    buffer(buffer_in), 
    buffer_size(N){
        modf.regist_window(mode, id);
    }
    
    template<unsigned N>
    BYTE Window<N>::operator[](unsigned offset){
        return buffer[offset];
    };
    
    template<unsigned N>
    void Window<N>::set_mode(MODE target){
        ;
    };
} // namespace KRN
