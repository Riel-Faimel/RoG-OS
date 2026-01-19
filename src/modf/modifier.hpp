#pragma once
#include <global/log.hpp>
#include <global/window.hpp>

template<unsigned N>
class Window;

namespace KRN::MODF
{
    class Modf {
public:
        Modf();
        ~Modf();
        
        template<unsigned N>
        void regist_window(Window<N> *win){;}
        template<unsigned N>
        void deal_mode(Window<N> *win){;}

        void clear_window(unsigned id);
        
        class Shell;
    };

    extern Modf* modf_ptr;
} // namespace KRN::MODF