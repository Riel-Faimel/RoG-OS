#include "kmalloc.hpp"
namespace KRN::MM
{
    class MMgr;

    extern MMgr *MMgr_ptr __attribute__((weak)) = NULL_PTR;
    void *allocate(unsigned size, unsigned alignment = 8) __attribute__((weak));
} // namespace KRN::MM

static class KMA{
private:
    typedef char Block_Array[KMALLOC_BLOCK_SIZE / 8];
    typedef Block_Array (*Block);
    typedef char MagicBlock[KMALLOC_BLOCK_SIZE / 8 * 2];
    MagicBlock spblk = {0};
    unsigned char pool_1[KMALLOC_BITS_MAP_SIZE * KMALLOC_BLOCK_SIZE * 8] = {0};
    unsigned char pool_2[KMALLOC_BITS_MAP_SIZE * KMALLOC_BLOCK_SIZE * 8] = {0};
    unsigned char pool_3[KMALLOC_BITS_MAP_SIZE * KMALLOC_BLOCK_SIZE * 8] = {0};
    unsigned char pool_4[KMALLOC_BITS_MAP_SIZE * KMALLOC_BLOCK_SIZE * 8] = {0};
    unsigned char pool_5[KMALLOC_BITS_MAP_SIZE * KMALLOC_BLOCK_SIZE * 8] = {0};
    unsigned char pool_6[KMALLOC_BITS_MAP_SIZE * KMALLOC_BLOCK_SIZE * 8] = {0};
    unsigned char pool_7[KMALLOC_BITS_MAP_SIZE * KMALLOC_BLOCK_SIZE * 8] = {0};
    unsigned char pool_8[KMALLOC_BITS_MAP_SIZE * KMALLOC_BLOCK_SIZE * 8] = {0};
public:
    KMA(){
        *(unsigned long  *)&spblk = 0x4B4D4143;
        //4B4DD4143 "KMAC"
        spblk[4] = 0b11111111;
        //status of 8 pools
        spblk[5];
    }
    ~KMA(){};
    /*inline */;
    void *kmalloc_get(size_t size){
        size_t needed = (size + KMALLOC_BLOCK_SIZE - 1) / KMALLOC_BLOCK_SIZE;
        if(*(unsigned long  *)&spblk != 0x4B4D4143){
            SYS_STATUS = SYS_ERROR;
            return NULL_PTR;
        }
        unsigned char *pool = NULL_PTR;
        if(spblk[4] & 0b10000000 == 0b10000000){
            pool = pool_1;
        }else if(spblk[4] & 0b01000000 == 0b01000000){
            pool = pool_2;
        }else if(spblk[4] & 0b00100000 == 0b00100000){
            pool = pool_3;
        }else if(spblk[4] & 0b00010000 == 0b00010000){
            pool = pool_4;
        }else if(spblk[4] & 0b00001000 == 0b00001000){
            pool = pool_5;
        }else if(spblk[4] & 0b00000100 == 0b00000100){
            pool = pool_6;
        }else if(spblk[4] & 0b00000010 == 0b00000010){
            pool = pool_7;
        }else if(spblk[4] & 0b00000001 == 0b00000001){
            pool = pool_8;
        }; 
        if(!pool){
            SYS_STATUS = SYS_ERROR;
            return nullptr;
        }
    };
    void kmalloc_back(void *ptr){
        if (!ptr) return;
        /* ... */;
    };
} kmalloc __attribute__((section(".kmalloc")));

void *operator new(size_t size){
    if(KRN::MM::MMgr_ptr && SYS_STATUS){
        return KRN::MM::allocate((unsigned )size);
    };
    return kmalloc.kmalloc_get(size);
}

void operator delete(void *ptr){
    kmalloc.kmalloc_back(ptr);
}

void *operator new[](size_t size){
    if(KRN::MM::MMgr_ptr && SYS_STATUS){
        return KRN::MM::allocate((unsigned )size);
    };
    return kmalloc.kmalloc_get(size);
}

void operator delete[](void *ptr){
    kmalloc.kmalloc_back(ptr);
}