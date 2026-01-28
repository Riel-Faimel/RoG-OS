#include "mop.hpp"

extern "C" {

void *memcpy(void *dest, const void *src, size_t n){
    if(dest == NULL_PTR || src == NULL_PTR || n == 0){
        return dest;
    }
    
    char *d = static_cast<char *>(dest);
    const char *s = static_cast<const char *>(src);

    while(n--){
        *d++ = *s++;
    }

    return dest;
}
void *memset(void *s, int c, size_t n){
    ;
}
int strcmp(const char *s1, const char *s2){
    while(*s1 && (*s1 == *s2)){
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}
unsigned __aeabi_uidiv(unsigned numerator, unsigned denumerator){
    ;
}

}