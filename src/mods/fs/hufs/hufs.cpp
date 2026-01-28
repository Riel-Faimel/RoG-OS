#include "hufs.hpp"

namespace KRN::FS::HUFS{

    HUFS::HUFS(fs_create_signal init_pkg){
        vector_table vtable;
        tree2id_map map;
    }

    void HUFS::fs_register(for_transmit_sche_info2fs init_input, aux_reg fs_rgt_2){
        void *laself = this;//delete
        fs_basic_info basic_info;
        fs_rgt_2(laself, basic_info);
    }

    void HUFS::init(){
        ;
    };

    void HUFS::open(void *obj, STXT path, WIN *win_mode){
        ;
    }
    void HUFS::close(void *obj, WIN *win_mode){
        ;
    }
    void HUFS::read(void *obj, WIN *win_buff, size_t win_size){
        return;
    }
    void HUFS::write(void *obj, WIN *win_buff, size_t win_size){
        return;
    }
    void HUFS::move(void *obj, STXT from, STXT to, WIN *win_mode){
        ;
    }

    void HUFS::cmdinter(void *obj, STXT command, STXT params){
        ;
    }

    KRN::LAS::Ftab hufs_ftab = {
        &HUFS::read,
        &HUFS::write,
        &HUFS::exist,
        &HUFS::creat,
        &HUFS::del,
        &HUFS::open,
        &HUFS::close,
        &HUFS::move,
        &HUFS::mkdir,
        &HUFS::deldir,
        &HUFS::cmdinter
    };
}