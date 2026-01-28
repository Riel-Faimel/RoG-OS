#pragma once
#include <global/type/type.hpp>

extern "C"{

void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
int strcmp(const char *s1, const char *s2);
unsigned __aeabi_uidiv(unsigned numerator, unsigned denumerator);

};