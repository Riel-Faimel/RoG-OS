#ifndef KMALLOC
#define KMALLOC
#pragma once
#include <global/type/type.hpp>
#include <global/main.hpp>
#define KMALLOC_BLOCK_SIZE 32
#define KMALLOC_BITS_MAP_SIZE 128

void *operator new(size_t size);
void operator delete(void *ptr);
void *operator new[](size_t size);
void operator delete[](void *ptr);

#endif