#define fs_ready 0b11
#define fs_busy 0b10
#define fs_uninit 0b01
#define fs_lost 0b00

class file_scheduler {
// basic components
public:
    #pragma pack(push, 1)
    struct storage
    {
        int device_id; //4bytes
        char file_system[6]; //6
        
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

    

    class file_space
    {
    public:
        storage header;
        storage devices[127]; //items of hardware once with storage capacity

        storage make_header() {
        struct storage head = {};
        head.device_id = 0;
        list_strcpy(head.file_system, "all");
        list_strcpy(head.specific_descript, "all");

        head.capacity[0] = 0;
        head.capacity[1] = 0;
        head.capacity[2] = 0;
        head.capacity[3] = 0;
        head.capacity[4] = 0;

        head.status = fs_ready;
        head.is_memory = 0b0;
        head.is_local = 0b1;
        head.is_swap = 0b0;
        head.is_net_disk = 0b0;
        head.extra_sign = 0b0;

        return head;
        };

        int init_scheduler() {

            this->header = make_header();// make file_space.header struct

            //wait_for(); //wait for at least boot device. and also maybe others
            //I think this should not in init()
        
            scheduler_operate_list I_O_list = {};

            return 1;
        };
    };// all for 128*32=4096 B : ! one page !

private:
    struct IO_func
    {
        short jump_to_IO_func[16];
        short func_code[4080];// all for one page(4kB)
    };
    
    struct scheduler_operate_list
    {
        IO_func page[256]; //full memory page : ! fixed size !
    };
// property
public:
    int all_space_size;
    int mem_size;
// method
public:
    int read(char* route); //deal by filename
    int write();
    int creat(); //deal by device and blocks(pages)

    //void wait_for();

    
    file_space CFS; // connect file space


    int register_device(char file_system[6], 
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

file_scheduler scheduler;
