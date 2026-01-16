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

void *operator new(size_t size);
void operator delete(void *ptr);