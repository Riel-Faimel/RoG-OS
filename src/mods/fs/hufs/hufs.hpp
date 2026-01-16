#include "../../../global/type/type.hpp"
#include "../../../las/las.hpp"
/**
 * >>> HUFS <<<
 * 
 * HUFS: 
 * 
 * (hufs designed for storage more'd like continue file)
 * 
 * URL: /folder_name/.../file_name
 * map to :
 * ID: /folder_id/.../file_id
 * point at:
 * / -> root_info_block (at A:)
 * root_info_block -> vector_table
 * file_id/folder_id (in vector_table) -> file_vector (if this id meaning file)
 * -> vector_table (if this id meaning folder)
 * 
 * ...
 * 
 * file_id -> vector (a struct, include start blocks and end blocks)
 * 
 * then give these blocks back to memory...
 */
namespace KRN::FS::HUFS {
    using KRN::LAS::for_transmit_sche_info2fs;
    using KRN::LAS::fs_basic_info;
    using KRN::LAS::aux_reg;
    using KRN::LAS::fs_create_signal;

    class HUFS{
        unsigned block_size; //bytes
        unsigned total_size;
public:
        struct vector_table;
        
        struct vector{
            __le64 f_id;
            union {
                struct {
                    __le64 blocks_start;
                    __le64 blocks_end;
                } file;
                struct {
                    __le64 start;/*MAX_BLOCK*/
                    vector_table *sub_folder_vector_table;
                } folder;
            };
            __le64 data;
        };

        struct vector_table{
            vector_table *next_list;
            vector v[];
        };

        struct tree2id_map_item{
            __le64 url_string;
            __le64 id;
        };

        struct tree2id_map{
            tree2id_map *next_map;
            tree2id_map_item map[];
        };

        struct root_info_block{
            __le64 fs_magic;
            __le64 block_size = 4096; //4096 for default
            __le64 total_blocks;
            __le64 device_size;
        //256 bytes
            __le64 t;//delete
            __le64 root_vector_table;
        };
    
private:
        root_info_block root_info_block;
        
public:
        HUFS(fs_create_signal init_pkg);
        ~HUFS();

        struct {
            int name;
            int total_blocks;
            int block_size;
            int root_info_block;
        } Basic_info;
        
        
        void fs_register(for_transmit_sche_info2fs init_input, aux_reg fs_rgt_2);
        void init();
        char exist(STXT path);
        void creat(STXT path);
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
        void format();
        void show_dir() const;
        void show_tree() const;
    };
}