#include "kmalloc.hpp"

void *operator new(size_t size){
    return kmalloc.kmalloc_get(size);
}

void operator delete(void *ptr){
    kmalloc.kmalloc_back(ptr);
}