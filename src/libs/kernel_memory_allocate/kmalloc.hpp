#ifndef x86_64
#ifndef STM32
#define x86_64
#endif
#endif

#ifdef STM32
typedef unsigned size_t;
#endif
#ifdef x86_64
#ifndef _SIZE_T
#define _SIZE_T
typedef __SIZE_TYPE__ size_t;
#endif
#endif

#define KMALLOC_BLOCK_SIZE 16
#define KMALLOC_BITS_MAP_SIZE 512
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

void *operator new(size_t size);
void operator delete(void *ptr);