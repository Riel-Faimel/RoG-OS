#include "ext4_info.hpp"

class ext4{
private:
    ext4_inode inode;
    ext4_inode_info inode_info;
public:
    ext4();
    ~ext4();

    void ext4_init();
};