#pragma once
#include <global/type/type.hpp>
#include <las/las.hpp>
#include <global/window.hpp>
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
namespace KRN::FS::HUFS{
    using KRN::LAS::for_transmit_sche_info2fs;
    using KRN::LAS::fs_basic_info;
    using KRN::LAS::aux_reg;
    using KRN::LAS::fs_create_signal;

    class HUFS{
public:
        struct vector_table;
        
        struct vector{
            lu64 f_id;
            union {
                struct {
                    lu64 blocks_start;
                    lu64 blocks_end;
                } file;
                struct {
                    lu64 start;/*MAX_BLOCK*/
                    vector_table *sub_folder_vector_table;
                } folder;
            };
            lu64 data;
        };

        struct vector_table{
            vector_table *next_list;
            vector v[];
        };

        struct tree2id_map_item{
            lu64 url_string;
            lu64 id;
        };

        struct tree2id_map{
            tree2id_map *next_map;
            tree2id_map_item map[];
        };

        struct root_info_block{
            lu64 fs_magic;
            lu64 block_size = 4096; //4096 for default
            lu64 total_blocks;
            lu64 device_size;
        //256 bytes
            lu64 t;//delete
            lu64 root_vector_table;
        };
    
private:
        root_info_block root_info_block;
        
public:
        HUFS(fs_create_signal init_pkg);
        ~HUFS();

        struct {
            const char *name = "HUFS";
            const char *descript = "A simple file system for continue file storage";
            unsigned total_blocks;
            unsigned block_size;
            int root_info_block;
        } Basic_info;
        
        
        static void read(void *obj, WIN *win_buff, size_t win_size);
        static void write(void *obj, WIN *win_buff, size_t win_size);
        static char exist(void *obj, STXT path);
        static void creat(void *obj, STXT path);
        static void del(void *obj, STXT path);
        static void open(void *obj, STXT path, WIN *win_mode);
        static void close(void *obj, WIN *win_mode);
        static void move(void *obj, STXT from, STXT to, WIN *win_mode);
        static void mkdir(void *obj, STXT path);
        static void deldir(void *obj, STXT path);
        static void cmdinter(void *obj, STXT cmd, STXT params);

        void fs_register(for_transmit_sche_info2fs init_input, aux_reg fs_rgt_2);
        void init();
        void format();
        void show_dir() const;
        void show_tree() const;
    };

    extern KRN::LAS::Ftab hufs_ftab;
}