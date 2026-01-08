#include "hufs.hpp"
#include "../../las/fs.hpp"

hufs::hufs(){
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
    };;
}

void hufs::hufs_init(){
    ;
};

void hufs::hufs_register(_re_pdata aux_reg_data, aux_reg fs_rgt_2){
    void *laself = ;
    fs_basic_info basic_info;
    fs_rgt_2(laself, basic_info);
}