#pragma once
#include <global/type/type.hpp>

extern "C"{

void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
unsigned __aeabi_uidiv(unsigned numerator, unsigned denumerator);

};