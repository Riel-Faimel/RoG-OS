#include "init.hpp"

static KRN::MM::MMgr mm;
static KRN::LAS::LAspace las;


void _start(){
    using KRN::MODF::root_shell_ptr;
    using KRN::MM::MMgr_ptr;
    using KRN::LAS::LAS_ptr;

    if(!MMgr_ptr){
        MMgr_ptr = &mm;
    }
    if(!LAS_ptr){
        LAS_ptr = &las;
    }

    static Modf::Shell root_shell("A:/System/tmp/root_shell.win");
    if(!root_shell_ptr){
        root_shell_ptr = &root_shell;
    }
    
    root_shell_ptr->main_loop();
}