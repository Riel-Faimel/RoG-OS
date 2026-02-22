#include "las.hpp"

namespace KRN::LAS {

    fs_create_signal init_pkg ;
    _re_pdata reg_false = static_cast<_re_pdata>(0b10101010101010100000000000000000);

    LAspace::LAspace(): header{
            .device_id = 0,
            .name = {'\0', '\0', '\0', '\0'},
            .specific_descript = NULL_PTR,
            .capacity = {0, 0, 0, 0, 0, 0},
            .file_system_name = {
                's', 'e', 'l', 'f',
                '\0', '\0', '\0', '\0', 
                '\0'
            },
            .status = dv_ready,
            .use_m_bytes = 0b1,
            .is_memory = 0b0,
            .is_swap = 0b0,
            .is_local = 0b1,
            .has_fs = 0b1,
            .extra_sign = 0b00,
            .null_device = {
                .null = {0, 0, 0, 0}
            },
            .this_ptr = NULL_PTR,
            .func_ptr = NULL_PTR
        }/* make file_space.header struct */{
    
        //wait_for(); //wait for at least boot device. and also maybe others
        //I think this should not in init()
    
        scheduler_operate_list I_O_list = {};
    }

    unsigned int KRN::LAS::LAspace::get_bind_table_space(){
        ;
    }
    unsigned int LAspace::search_fs_info_strc() {
        unsigned id = 0;
        return id;
    };

    KRN::LAS::_re_pdata LAspace::aux_reg_data;

    char LAspace::exist(STXT path){
        ;
    }
    void LAspace::create(STXT path){
        ;
    }
    void LAspace::del(STXT path){
        ;
    }
    void LAspace::open(STXT path, WIN *win_mode, LAS_Mode fm){
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
        }//set mode for win_mode
/**
 * |==============================>
 * |   name   |   path/LBA        |
 * |   A:     | /folder/file      |
 * |   A:     | lba_from>>lba_to  |
 * |   A:     | command>params    |
 * | /folder/file                 |
 * ^i point at path chars
 */
        char d_buffer[8]; //device part, max 8 bytes
        char buffer1[64]; //lba or command, max 64 bytes
        char i = 0; //index for input path
        STXT path_to = path;

        unsigned device_i = 0;
        void *func_ptr = NULL_PTR;

        for(char *c = const_cast<char *>(path);*c;c++){
            if(i >= 8) break; //device name max 8 bytes
            if(*c == ':'){
                d_buffer[i] = '\0';
                for(
                    storage *s = devices; 
                    device_i < 127 && strcmp((const char *)s[device_i].name, d_buffer); 
                    device_i++
                );
                goto SEND_LABEL;
            }
            d_buffer[i] = *c;
            i++;
        }
        device_i = default_lvfs;
        i = 0;
/**
 * now device has been found and turned into device_i
 * next is to analyse if '>>' in path or '>'
 * '>' means command interface
 * '>>' means lba read/write
 * neither means normal open
 */

SEND_LABEL:
        func_ptr = devices[device_i].func_ptr;
        path_to = const_cast<STXT>(path) + i;
        //now skip device part

        unsigned j = get_bind_table_space();
        bind_table[j].id = win_mode->id;
        bind_table[j].device_id = devices[device_i].device_id;

        for(char *c = const_cast<char *>(path)+i+1;*c || i < 64;c++){
            if(*c == '>'){
                if(*(c + 1) == '>'){
                    goto LBA_LABEL;
                }
                buffer1[i] = '\0';
                STXT buffer2 = c + 1;
                static_cast<Ftab *>(func_ptr) 
                -> 
                cmdinter(
                    devices[device_i].this_ptr, 
                    buffer1, 
                    buffer2
                );//FS.cmdinter()
            }
            buffer1[i] = *c;
            i++;
        }
        if(!devices[device_i].has_fs){
            sys_warning("LAS open: no file system found", SYS_FAILED);
            return;
        }
        //so now is normal open
        static_cast<Ftab *>(func_ptr)
        ->
        open(
            devices[device_i].this_ptr, 
            path_to, 
            win_mode
        );//FS.open(STXT path_to)
        return;
LBA_LABEL:
        static_cast<Dtab *>(func_ptr)
        //->read_lba(
        //    static_cast<unsigned>(atoi(buffer1)), 
        //    (void *)(*win_mode), 
        //    (size_t)(*win_mode)
        //)
        ;//FS.read_lba()
        return;
    };

    void LAspace::close(WIN *win_mode){
        ;
    }

    void LAspace::read(WIN *win_buff, size_t win_size){
        ;
    }

    void LAspace::write(WIN *win_buff, size_t win_size){
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
