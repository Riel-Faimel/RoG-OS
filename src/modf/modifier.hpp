#pragma once
#include <global/log.hpp>

namespace KRN
{
    enum class MODE;
} // namespace KRN


namespace KRN::MODF
{
    class Modf {
public:
        Modf();
        ~Modf();
        
        template<unsigned N>
        void regist_window(enum MODE (&mode), unsigned (&id));
        template<unsigned N>
        void deal_mode(enum MODE (&mode), enum MODE target, unsigned id);

        void clear_window(unsigned id);
        
        class Shell;
    };

    extern Modf modf;
} // namespace KRN::MODF

#include "window.hpp"