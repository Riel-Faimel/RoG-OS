#pragma once
#include "../../global/type/type.hpp"
#define KMALLOC_BLOCK_SIZE 16
#define KMALLOC_BITS_MAP_SIZE 512

void *operator new(size_t size);
void operator delete(void *ptr);