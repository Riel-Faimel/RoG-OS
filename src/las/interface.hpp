#ifndef KRN_LAS_INTERFACE
#define KRN_LAS_INTERFACE
#pragma once

#include <global/type/type.hpp>
#include <global/window.hpp>
namespace KRN::LAS {
    #ifdef __CHECK_ENDIAN__
    #define __las_reg __las_reg
    #else
    #define __las_reg
    #endif

    using _re_pdata = unsigned __las_reg;
    struct fs_basic_info{
        _re_pdata test_1;
        _re_pdata test_2;
        char name[6];
        char descript[16];
        unsigned total_size;
        unsigned block_size;
        unsigned root_info_block;
        void *self;
    };
    struct for_transmit_sche_info2fs {
        unsigned block_size;
        unsigned total_block;
        _re_pdata t1;
    };
/**
 * use for create file system
 */
    struct for_transmit_fs_info2sche {
        ;
    };
    typedef _re_pdata (*aux_reg)(void *, fs_basic_info );
    struct fs_create_signal {
        unsigned block_size;
        unsigned total_block;
    };

    class StorageDevice{
    public:
        virtual void fs_register(fs_create_signal fs_init, aux_reg fs_rgt_2) = 0;
        virtual void init() = 0;
    };

    class DevDrv : public StorageDevice {
    public:         
        virtual void read(unsigned lba, void *buffer, size_t size) = 0;
        virtual void write(unsigned lba, void *buffer, size_t size) = 0;
    };

    class DevPart : public StorageDevice {
    public:
        virtual void read(unsigned lba, void *buffer, size_t size) = 0;
        virtual void write(unsigned lba, void *buffer, size_t size) = 0;
    };

    class FS : public StorageDevice {
    public:    
        virtual void read(void *obj, WIN *win_buff, size_t win_size) = 0;
        virtual void write(void *obj, WIN *win_buff, size_t win_size) = 0;
        virtual char exist(void *obj, STXT path) = 0;
        virtual void creat(void *obj, STXT path) = 0;
        virtual void del(void *obj, STXT path) = 0;
        virtual void open(void *obj, STXT path, WIN *win_mode) = 0;
        virtual void close(void *obj, WIN *win_mode) = 0;
        virtual void move(void *obj, STXT from, STXT to, WIN *win_mode) = 0;
        virtual void mkdir(void *obj, STXT path, WIN *win_mode) = 0;
        virtual void deldir(void *obj, STXT path, WIN *win_mode) = 0;
        //virtual void wait_for() = 0;
        virtual void cmdinter(void *obj, STXT cmd, STXT params) = 0;
    };
} // namespace KRN::LAS

#endif