#include "modifier.hpp"

namespace KRN::MODF
{
    Modf::Modf(){
        ;
    }

    Modf::~Modf(){
        ;
    }

    template<unsigned int N> 
    void regist_window(enum KRN::Window<N>::MODE (&mode), unsigned (&id)){
        ;
    }

    void clear_window(unsigned id){
        ;
    };
    Modf modf;
} // namespace KRN::MODF

namespace KRN
{
    using KRN::MODF::modf;

    template<unsigned N>
    Window<N>::Window():
    buffer_size(N),
    sign(0){
        modf.regist_window(mode, id);
    }

    template<unsigned N>
    Window<N>::~Window(){
        modf.clear_window(id);
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
