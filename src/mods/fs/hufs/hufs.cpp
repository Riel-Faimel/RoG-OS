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

    void HUFS::open(STXT path, void *win_buff, size_t win_size){
        ;
    }
    void HUFS::close(STXT path, void *win_buff, size_t win_size){
        ;
    }
    void HUFS::read(STXT path, void *win_buff, size_t win_size){
        return;
    }
    void HUFS::write(STXT path, void *win_buff, size_t win_size){
        return;
    }
    void HUFS::move(STXT from, STXT to, void *win_buff, size_t win_size){
        ;
    }

    void HUFS::cmdinter(STXT command){
        ;
    }

    void hufs_read(void *obj, STXT path, void *win_buff, size_t win_size){
        static_cast<HUFS *>(obj) -> read(path, win_buff, win_size);
    };
    void hufs_write(void *obj, STXT path, void *win_buff, size_t win_size){
        static_cast<HUFS *>(obj) -> write(path, win_buff, win_size);
    };
    char hufs_exist(void *obj, STXT path){
        static_cast<HUFS *>(obj) -> exist(path);
    };
    void hufs_creat(void *obj, STXT path){
        static_cast<HUFS *>(obj) -> creat(path);
    };
    void hufs_del(void *obj, STXT path){
        static_cast<HUFS *>(obj) -> del(path);
    };
    void hufs_open(void *obj, STXT path, void *win_buff, size_t win_size){
        static_cast<HUFS *>(obj) -> open(path, win_buff, win_size);
    };
    void hufs_close(void *obj, STXT path, void *win_buff, size_t win_size){
        static_cast<HUFS *>(obj) -> close(path, win_buff, win_size);
    };
    void hufs_move(void *obj, STXT from, STXT to, void *win_buff, size_t win_size){
        static_cast<HUFS *>(obj) -> move(from, to, win_buff, win_size);
    };
    void hufs_mkdir(void *obj, STXT path){
        static_cast<HUFS *>(obj) -> mkdir(path);
    };
    void hufs_deldir(void *obj, STXT path){
        static_cast<HUFS *>(obj) -> deldir(path);
    };
    void hufs_cmdinter(void *obj, STXT cmd){
        static_cast<HUFS *>(obj) -> cmdinter(cmd);
    };
    KRN::LAS::Ftab hufs_ftab = {
        &hufs_read,
        &hufs_write,
        &hufs_exist,
        &hufs_creat,
        &hufs_del,
        &hufs_open,
        &hufs_close,
        &hufs_move,
        &hufs_mkdir,
        &hufs_deldir,
    };
}