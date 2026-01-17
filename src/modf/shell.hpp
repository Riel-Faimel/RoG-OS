#include "modifier.hpp"
#include <modf/window.hpp>
#include <las/las.hpp>
#pragma once

namespace KRN::MODF
{
    class Modf::Shell{
    public:
        Window<1024 * 1024> shell_space;
        Shell(STXT win_path);
        ~Shell();
        void main_loop();
    };

    extern Modf::Shell root_shell;
} // namespace KRN::MODF
