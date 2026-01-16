#include "rgt.hpp"

namespace KRN::FS::HUFS
{
    using KRN::LAS::las;
    using KRN::LAS::fs_create_signal;

    void ld(){
        ;
    };

    void rgt(unsigned block_size, unsigned total_blocks){
        fs_create_signal *init_pkg = new fs_create_signal{
            block_size,
            total_blocks
        };
        las.fs_rgt_1<HUFS >(*init_pkg);
    };
} // namespace KRN::FS::HUFS