#include "las.hpp"

namespace KRN::LAS {

    fs_create_signal init_pkg ;
    _re_pdata reg_false = static_cast<_re_pdata>(0b10101010101010100000000000000000);
    
    template<unsigned int N> 
    void KRN::LAS::file_scheduler::open(STXT path, KRN::Window<N> win){};
    
    template<unsigned int N> 
    void KRN::LAS::file_scheduler::read(STXT path, KRN::Window<N> win){};
    
    template<unsigned int N> 
    void KRN::LAS::file_scheduler::write(STXT path, KRN::Window<N> win){};
    
    template<unsigned int N> 
    void KRN::LAS::file_scheduler::move(STXT from, STXT to, KRN::Window<N> win){};

    file_scheduler::file_space::file_space(): header(
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
    
        scheduler_operate_list I_O_list = {};;
    }

    unsigned int KRN::LAS::file_scheduler::search_fs_info_strc() {
        unsigned id = 0;
        return id;
    };

    KRN::LAS::_re_pdata KRN::LAS::file_scheduler::aux_reg_data;
    
    file_scheduler las;
}