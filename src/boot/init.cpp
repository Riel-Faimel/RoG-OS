#include "init.hpp"

static KRN::MM::MMgr mm;
static KRN::LAS::LAspace las;

Window<1024> kprint_window;
WIN *k_win = &kprint_window;
static void *k_buffer = (void *)(*k_win);
static size_t k_buf_size = kprint_window.buffer_size;
static STXT kprint_path = "A:/System/tmp/sys.log";
void kprint_init(){
    kprint_window.set_mode(MODE::WRITE);
    KRN::LAS::LAS_ptr -> open(kprint_path, k_win, KRN::LAS::LAspace::File_Mode::WR__);
}
void kprint(STXT warning_msg){
    for(unsigned char i = 0;warning_msg[i];i++){
        static_cast<char *>(k_buffer)[i] = warning_msg[i];
    }
    KRN::LAS::LAS_ptr -> write(kprint_path, k_buffer, k_buf_size);
}

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
    };
    root_shell_ptr->main_loop();
}