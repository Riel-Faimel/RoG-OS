#include "modifier.hpp"
#include <global/window.hpp>
#include <las/las.hpp>
#pragma once

namespace KRN::MODF
{
    using KRN::LAS::las;
    class Modf::Shell{
    public:
        Window<1024 * 1024> shell_space;
        Shell(STXT win_path){
            shell_space.set_mode(MODE::R_W);
            las.create(win_path);
            las.open(win_path, shell_space);
            ;
        };
        ~Shell() = default;
        void main_loop();
    };

    extern Modf::Shell root_shell;
} // namespace KRN::MODF
