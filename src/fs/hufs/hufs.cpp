#include "hufs.hpp"

namespace KRN::FS::HUFS{

    HUFS::HUFS(fs_create_signal init_pkg){
        vector_table vtable;
        tree2id_map map;
    }

    void HUFS::init(){
        ;
    };

    void HUFS::fs_register(for_transmit_sche_info2fs init_input, aux_reg fs_rgt_2){
        void *laself = this;//delete
        fs_basic_info basic_info;
        fs_rgt_2(laself, basic_info);
    }

}