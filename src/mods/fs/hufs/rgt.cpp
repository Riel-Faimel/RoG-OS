#include "rgt.hpp"

namespace KRN::LAS
{
    struct fs_create_signal {
        unsigned block_size;
        unsigned total_block;
    };
} // namespace KRN::LAS


namespace KRN::FS::HUFS
{
    using KRN::LAS::las;
    using KRN::LAS::fs_create_signal;

    void ld(){
        ;
    };

    void rgt(unsigned block_size, unsigned total_blocks){
        fs_create_signal init_pkg = new fs_create_signal{
            ,
        };
        las.fs_rgt_1<HUFS >(init_pkg);
    };
} // namespace KRN::FS::HUFS