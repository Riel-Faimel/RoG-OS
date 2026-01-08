#include "fs.hpp"

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