#include "shell.hpp"


namespace KRN::MODF
{
    using KRN::LAS::las;

    Modf::Shell::Shell(STXT win_path){
        shell_space.set_mode(KRN::MODE::R_W);
        las.create(win_path);
        las.open(win_path, shell_space);
        ;
    }
    
    void Modf::Shell::main_loop(){
        char is_running = 1;
        while(is_running){
            ;
        };
    };
    Modf::Shell root_shell("A:/System/tmp/root_shell.win");
} // namespace KRN::MODF