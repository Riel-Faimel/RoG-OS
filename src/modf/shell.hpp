#include "modifier.hpp"
#include <global/window.hpp>
#include <las/las.hpp>
#pragma once

namespace KRN::MODF
{
    using KRN::LAS::LAS_ptr;
    class Modf::Shell{
    public:
        char is_running;
        Window<1024 * 1024> shell_space;
        Shell(STXT win_path){
            shell_space.set_mode(MODE::R_W);
            LAS_ptr->create(win_path);
            LAS_ptr->open(win_path, &shell_space);
            ;
        };
        ~Shell() = default;

        STXT environ_act(STXT cmd);
        void main_loop();
    };

    extern Modf::Shell *root_shell_ptr;
} // namespace KRN::MODF
