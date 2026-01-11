#include "../struc/main.hpp"

namespace KRN::LAS {
    
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
    typedef _re_pdata (*aux_reg)(void *, fs_basic_info );

    _re_pdata reg_false = static_cast<_re_pdata>(0b10101010101010100000000000000000);

    struct for_create_fs{
        ;
    };

    struct for_transmit_sche_info2fs{
        ;
    };

    struct for_transmit_fs_info2sche{
        ;
    };

    constexpr _re_pdata t_code = static_cast<_re_pdata>(0b00000000000000001010101010101010);
    constexpr aux_reg ex_ = [](void *ptr, fs_basic_info info_init) -> _re_pdata{
        return t_code;
    };
    constexpr for_transmit_sche_info2fs test;
    template<typename T>
    concept FS_accept = requires(T fs) {
        fs.fs_register(test, ex_);
        fs.init();
        fs.read();
        fs.write();
        fs.fs_leave();
        fs.Basic_info.name;
        fs.Basic_info.total_size;
        fs.Basic_info.block_size;
        fs.Basic_info.root_info_block;
    };

    class file_scheduler {
    // basic components
    public:
#pragma pack(push, 1)
        struct storage
        {
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
                    unsigned char ip_address[4];// 4 bytes
                    unsigned short port;// 2 bytes
                    unsigned int speed;
                    unsigned int how_many_pkg_lost_per_100;
                    char protocol;// TCP/UDP
                    char re[5];//up is 24 bytes
                } net_device;

                struct {
                    unsigned int null[6];
                } null_device;
            };

                long long int func_ptr;//8 btyes for device func
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
         * not mem either swap just disk */

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
        struct IO_func
        {
            void init(); //qwq
            void read();
            void write();
            char *dir();
        };

        struct scheduler_operate_list
        {
            IO_func page[256]; //full memory page : ! fixed size !
        };
    // property
        unsigned search_fs_info_strc();
    public:
        int all_space_size;
        int mem_size;
    // method
    public:
        int read(char* route); //deal by filename
        int write();
        int creat(); //deal by device and blocks(pages)

        //void wait_for();

        template<FS_accept T>
        void fs_rgt_1(T *fs, for_create_fs fs_init) {
            this -> aux_reg_data = static_cast<_re_pdata >(0b10101010);
            fs -> T(fs_init);
            fs -> fs_register(aux_reg_data, fs_rgt_2);
        }

        aux_reg fs_rgt_2 = [](void *ptr, fs_basic_info info_init) -> _re_pdata{
            file_scheduler *la_this = static_cast<file_scheduler *>(ptr);
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
            static_cast<IO_func *>(info_init.self) -> init();
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

}