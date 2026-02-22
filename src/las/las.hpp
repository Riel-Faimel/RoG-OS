#ifndef LAS_LAS
#define LAS_LAS
#include "./interface.hpp"
#include <memalloc/memalloc.hpp>
#include <global/main.hpp>
#include <global/type/type.hpp>
#include <modf/modifier.hpp>
#include <global/window.hpp>
#include <libs/memop/mop.hpp>

#pragma once
namespace KRN::MM {
    class MMgr;
    extern MMgr *MMgr_ptr;
} // namespace KRN::MM

namespace KRN::LAS {

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
 * LAspace::fs_rgt_1(this, fs_init)
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
    
    #define dv_ready 0b11
    #define dv_busy 0b10
    #define dv_uninit 0b01
    #define dv_lost 0b00
    using KRN::MM::MMgr_ptr;
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
    constexpr STXT test_STXT = "A:/folder/file";
    constexpr void *test_ptr = NULL_PTR;
    constexpr size_t test_size_t = 0x01;
    template<typename T>
    concept FS_accept = requires(T fs) {
        fs.fs_register(test, ex_);
        fs.init();
        T::read(test_ptr, static_cast<WIN *>(test_ptr), test_size_t);
        T::write(test_ptr, static_cast<WIN *>(test_ptr), test_size_t);
        T::exist(test_ptr, test_STXT);
        T::creat(test_ptr, test_STXT);
        T::del(test_ptr, test_STXT);
        T::open(test_ptr, test_STXT, static_cast<WIN *>(test_ptr));
        T::close(test_ptr, static_cast<WIN *>(test_ptr));
        T::move(test_ptr, test_STXT, test_STXT, static_cast<WIN *>(test_ptr));
        T::mkdir(test_ptr, test_STXT);
        T::deldir(test_ptr, test_STXT);
        T::cmdinter(test_ptr, test_STXT, test_STXT);

        fs.Basic_info.name;
        fs.Basic_info.total_blocks;
        fs.Basic_info.block_size;
    };
//test end

    typedef void(* ReadLBA)(unsigned lba, void *buffer, size_t size);
    typedef void(* WriteLBA)(unsigned lba, void *buffer, size_t size);

    typedef void (*Read)(void *obj, WIN *win_buff, size_t win_size);
    typedef void (*Write)(void *obj, WIN *win_buff, size_t win_size);
    typedef char (*Exist)(void *obj, STXT path);
    typedef void (*Creat)(void *obj, STXT path);
    typedef void (*Del)(void *obj, STXT path);
    typedef void (*Open)(void *obj, STXT path, WIN *win_mode);
    typedef void (*Close)(void *obj, WIN *win_mode);
    typedef void (*Move)(void *obj, STXT from, STXT to, WIN *win_mode);
    typedef void (*Mkdir)(void *obj, STXT path);
    typedef void (*Deldir)(void *obj, STXT path);
    typedef void(*Cmdinter)(void *obj, STXT cmd, STXT params);

    struct Dtab{
        void *this_ptr;
        ReadLBA read_lba;
        WriteLBA write_lba;
    };

    struct Ftab{
        Read read;
        Write write;
        Exist exist;
        Creat creat;
        Del del;
        Open open;
        Close close;
        Move move;
        Mkdir mkdir;
        Deldir deldir;
        Cmdinter cmdinter;
    };
    
    class LAspace {
    // basic components
    public:
#pragma pack(push, 1)
        struct storage {
            unsigned int device_id; //4bytes
            char name[4]; //4bytes
            unsigned char *specific_descript; //up is 25bytes
            unsigned char capacity[6]; //size of storage //7byte // 2^(6*8)B ~ 256 TB or 2^(6*8)MB ~ 256 EB
            char file_system_name[9]; //9bytes
            //under is 1byte
            unsigned char status: 2; //ready? busy? broke? ... //2bites
            unsigned char use_m_bytes: 1;
            unsigned char is_memory: 1;
            unsigned char is_swap: 1;
            unsigned char is_local: 1;
            unsigned char has_fs: 1;
            unsigned char extra_sign: 2;//all for 32 bytes
            //under is 24 bytes for union
            union {
                struct {
                    unsigned int address_range;
                    unsigned int OS_used;
                    unsigned int cache_size;
                    unsigned int re[1];//24 bytes
                } bit_device;

                struct {
                    unsigned int block_size;
                    unsigned int total_blocks;
                    unsigned int speed;
                    unsigned int re;//all for 16 bytes
                } block_device;

                struct {
                    unsigned int speed;
                    unsigned int how_many_pkg_lost_per_100;
                    unsigned char ip_address[4];// 4 bytes
                    unsigned short port;// 2 bytes
                    char protocol;// TCP/UDP
                    char re[3];//up is 16 bytes
                } net_device;

                struct {
                    unsigned int null[4];//16 bytes
                } null_device;
            };
            StorageDevice *this_ptr;//8 btyes for device self
            void *func_ptr;//8 btyes for device func
/* func_ptr oint at the func list of 
 * one device. here we appoint:
 * each device has func list(see Ftab)
 * 
 * func_ptr point at the head
 * when using, we'll just return func_ptr:movement_ptr
 * then, process'll just goto there and ignore LAspace
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
        static _re_pdata aux_reg_data;

        LAspace();
    private:
        storage header;
        storage devices[127]; //items of hardware once with storage capacity
/**
 * connect file space 
 * all for 128*32=4096 B : ! one page !
 */
        struct{
            unsigned id;
            unsigned device_id;
        } bind_table[1024];
        unsigned get_bind_table_space();

        struct scheduler_operate_list {
            Ftab page[128]; //full memory page : ! fixed size !
        };
    // property
        unsigned search_fs_info_strc();
    public:
        int all_space_size;
        int mem_size;
    // method
        unsigned char default_lvfs;
        void set_default_lvfs();
    public:
        enum LAS_Mode {
            R,
            W,
            WR,
            R__,
            W__,
            WR__
        };

        char exist(STXT path);
        void create(STXT path); //deal by device and blocks(pages)
        void del(STXT path);
        void open(STXT path, WIN *win_mode, LAS_Mode fm = R);
        void close(WIN *win_mode);
        void read(WIN *win_mode, size_t win_size); //deal by filename
        void write(WIN *win_mode, size_t win_size);
        void move(STXT from, STXT to, WIN *win_mode);
        void mkdir(STXT path, WIN *win_mode);
        void deldir(STXT path, WIN *win_mode);
        //void wait_for();
/**
 * This layer should not deal with 
 * window *, it comes WIN * and void *
 * with size_t buffer_size
 */
        template<FS_accept T>
        void fs_rgt_1(fs_create_signal fs_init) {
            this -> aux_reg_data = static_cast<_re_pdata >(0b10101010);
            T *fs = static_cast<T *>(KRN::MM::MMgr_ptr->allocate(sizeof(T(fs_init))));
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
            LAspace *la_this = static_cast<LAspace *>(ptr);
            //this
            if(info_init.test_1 != la_this -> aux_reg_data) return reg_false;
            unsigned fs_info_strc_id = la_this -> search_fs_info_strc();
            la_this -> devices[fs_info_strc_id] = {
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
    
    extern LAspace *LAS_ptr;
}

void kprint(STXT warning_msg);
#endif