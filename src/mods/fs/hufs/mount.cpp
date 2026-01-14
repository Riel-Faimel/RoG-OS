#include "mount.hpp"

namespace KRN::FS::HUFS
{
    using KRN::LAS::las;
    using KRN::LAS::init_pkg;
    void ld(){
        ;
    };

    void mount(){
        las.fs_rgt_1<HUFS >(init_pkg);
    };
} // namespace KRN::FS::HUFS