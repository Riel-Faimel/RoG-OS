#pragma once
#include <global/log.hpp>
#include <global/window.hpp>

class WIN;
template<unsigned N>
class Window;

namespace KRN::MODF
{
    class Modf {
public:
        Modf();
        ~Modf();
        
        void regist_window(WIN *win_mode);
        void deal_mode(WIN *win_mode);
        void clear_window(WIN *win_mode);

        class Connecter; 
/**
 * for connect file and analsys .ccl
 * .ccl: connect config list.
 * 
 */
        class Shell;
    };

    extern Modf* modf_ptr;
} // namespace KRN::MODF