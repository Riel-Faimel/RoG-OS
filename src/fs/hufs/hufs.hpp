#include "../../type/type.hpp"

#define Vector_buffer_size 

struct hufs_vector{
    __le64 f_id;
    union {
        struct {
            __le64 blocks_start;
            __le64 blocks_end;
        } file;
        struct {
            const __le64 start = MAX_BLOCK;
            hufs_vector_table *sub_folder_vector_table;
        } folder;
    };
    __le8 date;
    __le8 re;
    __le16 re;
    __le32 re;
};

struct hufs_vector_table{
    hufs_vector vector[HUFS_VECTOR_TABLE_SIZE];
    hufs_vector_table *next_list;
};

struct tree2id_map_item{
    __le64 url_string;
    __le64 id;
};

struct hufs_tree2id_map{
    tree2id_map_item map[HUFS_ID_MAP_SIZE];
    hufs_tree2id_map *next_map;
};

struct hufs_root_info_block{
    __le64 fs_magic;
    __le64 block_size = 4096; //4096 for default
    __le64 total_blocks;
    __le64 device_size;
//256 bytes
    __le64 ;
    __le64 root_vector_table;
};

class hufs{
private:
    hufs_root_info_block root_info_block;
    hufs_vector_table vector_table[Vector_buffer_size];
    ;
public:
    hufs();
    ~hufs();
    
    void hufs_init();
    void hufs_register(_re_pdata aux_reg_data, aux_reg fs_rgt_2);
    void hufs_format();
    void hufs_read();
    void hufs_write();
    void hufs_show_dir() const;
    void hufs_show_tree() const;
};