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

    template<unsigned N>
    void HUFS::open(STXT path, Window<N> win){
        if(win.mode == MODE::NO){
            win.mode = MODE::NO;
        }else{
            win.mode = MODE::READ;
        };
    }
    template<unsigned N>
    void HUFS::close(STXT path, Window<N> win){
        ;
    }
    template<unsigned N>
    void HUFS::read(STXT path, Window<N> win){
        if(win.mode == MODE::READ || win.mode == MODE::R_W){
            return;
        }
        return;
    }
    template<unsigned N>
    void HUFS::write(STXT path, Window<N> win){
        if(win.mode == MODE::WRITE || win.mode == MODE::R_W){
            return;
        }
        return;
    }
    template<unsigned N>
    void HUFS::move(STXT from, STXT to, Window<N> win){
        ;
    }

    void HUFS::cmdinter(STXT command){
        ;
    }
}