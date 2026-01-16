#include "kmalloc.hpp"
static class {
private:
    unsigned char bits_map[KMALLOC_BITS_MAP_SIZE];
    unsigned char pool[KMALLOC_BITS_MAP_SIZE * KMALLOC_BLOCK_SIZE * 8];
public:
    void *kmalloc_get(size_t size){
        /* ... */;
        return nullptr;
    };
    void kmalloc_back(void *ptr){
        if (!ptr) return;
        /* ... */;
    };
} kmalloc __attribute__((section(".kmalloc")));

void *operator new(size_t size){
    return kmalloc.kmalloc_get(size);
}

void operator delete(void *ptr){
    kmalloc.kmalloc_back(ptr);
}