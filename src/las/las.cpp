#include "las.hpp"

namespace KRN::LAS {

    fs_create_signal init_pkg ;
    _re_pdata reg_false = static_cast<_re_pdata>(0b10101010101010100000000000000000);

    LAspace::file_space::file_space(): header(
        {
            .device_id = 0,
            .file_system_name = {'a', 'l', 'l', '\0'},
            .specific_descript = {
                'a', 'l', 'l', '\0', 
                '\0', '\0', '\0', '\0', 
                '\0', '\0', '\0', '\0', 
                '\0', '\0', '\0', '\0'
            },
            .capacity = {0, 0, 0, 0, 0},
            .status = fs_ready,
            .is_memory = 0b0,
            .is_local = 0b1,
            .is_swap = 0b0,
            .is_net_disk = 0b0,
            .extra_sign = 0b0,
            .null_device = {
                .null = {0, 0, 0, 0, 0, 0}
            },
            .func_ptr = 0
        }
    )/* make file_space.header struct */{
    
        //wait_for(); //wait for at least boot device. and also maybe others
        //I think this should not in init()
    
        scheduler_operate_list I_O_list = {};
    }

    unsigned int KRN::LAS::LAspace::search_fs_info_strc() {
        unsigned id = 0;
        return id;
    };

    KRN::LAS::_re_pdata KRN::LAS::LAspace::aux_reg_data;

    char LAspace::exist(STXT path){
        ;
    }
    void LAspace::create(STXT path){
        ;
    }
    void LAspace::del(STXT path){
        ;
    }
    void LAspace::open(STXT path, WIN *win_mode, File_Mode fm = R){
        switch (fm)
        {
        case R:
            win_mode->sign = 0b0001; //0b 0 append write read
            break;
        case W:
            win_mode->sign = 0b0010;
            break;
        case WR:
            win_mode->sign = 0b0011;
            break;
        case R__:
            win_mode->sign = 0b0101;
            break;
        case W__:
            win_mode->sign = 0b0110;
            break;
        case WR__:
            win_mode->sign = 0b0111;
            break;
        default:
            win_mode->sign = 0b0001;
            break;
            break;
        }
        char d_buffer[8];
        char buffer[256];
        STXT path_to = buffer;
        char i = 0;
        for(char *c = const_cast<char *>(path);*c != '\0';c++){
            if(*c == ':'){
                goto SEND_LABEL;
            }
            d_buffer[i] = *c;
            i++;
        }
        memcpy(d_buffer, default_lvfs, 8);
SEND_LABEL:
        i = 0;
        for(char *c = const_cast<char *>(path);c;c++){
            if(*c == '>'){
                ;//FS.cmdinter()
            }
            buffer[i] = *c;
            i++;
        }
        ;//FS.open(STXT path_to)
    };
    void LAspace::close(STXT path, WIN *win_mode){
        ;
    }
    void LAspace::read(STXT path, void *win_buff, size_t win_size){
        ;
    }
    void LAspace::write(STXT path, void *win_buff, size_t win_size){
        ;
    }
    void LAspace::move(STXT from, STXT to, WIN *win_mode){
        ;
    }
    void LAspace::mkdir(STXT path, WIN *win_mode){
        ;
    }
    void LAspace::deldir(STXT path, WIN *win_mode){
        ;
    }
    LAspace *LAS_ptr = NULL_PTR;
}
