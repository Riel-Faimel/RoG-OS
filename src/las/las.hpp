//#include "../global/main.hpp"
#include <libs/kernel_memory_allocate/kmalloc.hpp>
#include <global/type/type.hpp>
#include <modf/modifier.hpp>
#include <modf/window.hpp>

#pragma once

namespace KRN::LAS {
    using KRN::Window;

/**
 * >>> Linear Address Space <<<
 * 
 * ====
 * LAS:
 * 
 * a storage space compare all storage device.
 * 
 * |————|———————|—————————|
 * ^Mem:  ^A:    ^B:
 * 
 * 1:
 * 
 * URL: A:/...(file path)
 * A: -(device_table)-> device_func_list
 * call function of File System A:
 * 
 * 2:
 * 
 * URL: V:/...(Local VFS)
 * path2device_table -> device_func_list
 * ...
 * 
 * 3:
 * 
 * URL: A:/>CMD
 * transmit CMD into device_cmd
 * 
 * Also:
 * 
 * You can join some device like A: B: ..
 * into a Virtual device V:
 * Infact, We don't care about if it is a 
 * physic device but just check if it can
 * satisfy basic function list. If V: can use
 * A: B: and so on then you can say it's VFS.
 * 
 * but LVFS is designed for UNIX-like path, so 
 * you need to point NAME://path or / for default LVFS
 * 
 * ====
 * REG:
 * 
 * Way to regist a file system into LAS
 * 
 * CMD -> search for (fs name).mod
 * ld and get basic_func_list
 * call template: 
 * KRN::LAS::file_scheduler::fs_rgt_1(this, fs_init)
 * 
 * LAS::fs_rgt_1() -> FS::fs_register() ->
 * LAS::fs_rgt_2() -> FS::init()
 * three handshakes
 * 
 * And the data:
 * (from mount signal)fs_create_signal init_pkg ->
 * (from sche){
 *      for_transmit_sche_info2fs, 
 *      aux_reg fs_rgt_2
 * } ->
 * (from fs)for_transmit_fs2sche_info
 * 
 * 
 * ====
 * BIND:
 * 
 * Every URL will first mapped by "bind_table", if there 
 * is a bind item, then it will be mapped, then it will not
 * goto bind_table(to avoied circle). bind_table item :
 * 
 * "from"go"to"
 * 
 * go canbe -p then recursion all subdir.
 * But, I mean, if you want such virtualized access, 
 * why not use LVFS?
 */
    
    #define fs_ready 0b11
    #define fs_busy 0b10
    #define fs_uninit 0b01
    #define fs_lost 0b00

    #ifdef __CHECK_ENDIAN__
    #define __las_reg __las_reg
    #else
    #define __las_reg
    #endif
    typedef unsigned __las_reg _re_pdata;
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
    struct fs_create_signal {
        unsigned block_size;
        unsigned total_block;
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
    extern _re_pdata reg_false;

//compress test
    constexpr _re_pdata t_code = static_cast<_re_pdata>(0b00000000000000001010101010101010);
    constexpr aux_reg ex_ = [](void *ptr, fs_basic_info info_init) -> _re_pdata{
        return t_code;
    };
    constexpr for_transmit_sche_info2fs test = {
        (unsigned )512,
        (unsigned )4096,
        t_code
    };
    constexpr STXT test_path = "A:/folder/file";
    template<typename T>
    concept FS_accept = requires(T fs, const Window<256>& test_win) {
        fs.fs_register(test, ex_);
        fs.init();
        fs.read(test_path, test_win);
        fs.write(test_path, test_win);
        fs.exist(test_path);
        fs.creat(test_path);
        fs.del(test_path);
        fs.open(test_path, test_win);
        fs.close(test_path, test_win);
        fs.move(test_path, test_path, test_win);
        fs.mkdir(test_path);
        fs.deldir(test_path);
        fs.cmdinter(test_path);

        fs.Basic_info.name;
        fs.Basic_info.total_blocks;
        fs.Basic_info.block_size;
    };
//test end

    class file_scheduler {
    // basic components
    public:
#pragma pack(push, 1)
        struct storage {
            int device_id; //4bytes
            char file_system_name[6]; //6

            char specific_descript[16]; //16
            unsigned char capacity[5]; //size of storage //5byte // 2^(5*8)MB ~ 1 PB
            //under is 1byte
            unsigned char status: 2; //ready? busy? broke? ... //2bites
            unsigned char is_memory: 1;
            unsigned char is_local: 1;
            unsigned char is_swap: 1;
            unsigned char is_net_disk: 1;
            unsigned char extra_sign: 2;//all for 32 bytes
            //under is 24 bytes for union
            union {
                struct {
                    unsigned int address_range;
                    unsigned int OS_used;
                    unsigned int cache_size;
                    unsigned int re[3];//24 bytes
                } bit_device;

                struct {
                    unsigned int block_size;
                    unsigned int total_blocks;
                    unsigned int broken_blocks;
                    unsigned int read_speed;
                    unsigned int write_speed;
                    unsigned int re;//all for 24 bytes
                } block_device;

                struct {
                    unsigned int speed;
                    unsigned int how_many_pkg_lost_per_100;
                    unsigned char ip_address[4];// 4 bytes
                    unsigned short port;// 2 bytes
                    char protocol;// TCP/UDP
                    char re[5];//up is 24 bytes
                } net_device;

                struct {
                    unsigned int null[6];
                } null_device;
            };

                void *func_ptr;//8 btyes for device func
/* func_ptr oint at the func list of 
 * one device. here we appoint:
 * each device has func list and in under form:
 * struct func_list{
 *     init();
 *     read();
 *     write();
 *     ioctl();
 *     status();
 *     tree();
 *     line();
 *     throw();
 * }
 * func_ptr point at the head
 * when using, we'll just return func_ptr:movement_ptr
 * then, process'll just goto there and ignore file_scheduler
 * 
 * this is for out of sync I/O func
 * 
 * */
        };// up is 32 bytes
#pragma pack(pop)
/* is mem also swap then to be cache for disk
 * is mem but not swap just mem
 * not mem but swap is true swap
 * not mem either swap just disk 
 */
        class file_space {
        public:
            storage header;
            storage devices[127]; //items of hardware once with storage capacity
            file_space();
        };
        file_space CFS; 
/**
 * connect file space 
 * all for 128*32=4096 B : ! one page !
 */
        static _re_pdata aux_reg_data;
    private:
        struct IO_func {
            void init();
            void read();
            void write();
            char *dir();
        };

        struct scheduler_operate_list {
            IO_func page[256]; //full memory page : ! fixed size !
        };
    // property
        unsigned search_fs_info_strc();
    public:
        int all_space_size;
        int mem_size;
    // method
    public:
        char exist(STXT path);
        void create(STXT path); //deal by device and blocks(pages)
        void del(STXT path);

        template<unsigned N>
        void open(STXT path, Window<N> win);
        template<unsigned N>
        void close(STXT path, Window<N> win);
        template<unsigned N>
        void read(STXT path, Window<N> win); //deal by filename
        template<unsigned N>
        void write(STXT path, Window<N> win);
        template<unsigned N>
        void move(STXT from, STXT to, Window<N> win);
        
        void mkdir(STXT path);
        void deldir(STXT path);

        //void wait_for();

        template<FS_accept T>
        void fs_rgt_1(fs_create_signal fs_init) {
            this -> aux_reg_data = static_cast<_re_pdata >(0b10101010);
            T *fs = new T(fs_init);
            for_transmit_sche_info2fs las2fs = {
                fs_init.block_size,
                fs_init.total_block,
                aux_reg_data
            };
            fs -> fs_register(las2fs, fs_rgt_2);
/**
 * now other file system has been registed
 * so, i can call init
 * 
 * by the way,
 * this function just as template and 
 * come ture in mount.cpp, mount.cpp(
 * or other thing) will call it when 
 * file system has been dynamic linked
 */
            fs -> init();
        }

        aux_reg fs_rgt_2 = [](void *ptr, fs_basic_info info_init) -> _re_pdata{
            file_scheduler *la_this = static_cast<file_scheduler *>(ptr);
            //this
            if(info_init.test_1 != la_this -> aux_reg_data) return reg_false;
            unsigned fs_info_strc_id = la_this -> search_fs_info_strc();
            la_this -> CFS.devices[fs_info_strc_id] = {
                //.device_id = ,
                .file_system_name = {
                    static_cast<fs_basic_info >(info_init).name[0],
                    static_cast<fs_basic_info >(info_init).name[1],
                    static_cast<fs_basic_info >(info_init).name[2],
                    static_cast<fs_basic_info >(info_init).name[3],
                    static_cast<fs_basic_info >(info_init).name[4],
                    static_cast<fs_basic_info >(info_init).name[5],
                }
            };
            return info_init.test_2;
        };

        int register_device(
            char file_system[6], 
            char specific_descript[16], 
            unsigned char capacity[5], 
            unsigned char is_memory, 
            unsigned char is_local, 
            unsigned char is_swap, 
            unsigned char extra_capacity_bite, 
            unsigned char is_net_disk, 
            unsigned char extra_sign){};
    private:
        // func templates or called decorators
        void embellish() {
            ;
        };

    };
    
    extern file_scheduler las;
}