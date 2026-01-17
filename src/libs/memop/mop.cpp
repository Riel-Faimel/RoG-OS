#include "mop.hpp"

extern "C" {

void *memcpy(void *dest, const void *src, size_t n){
    if(dest == NULL_PTR || src == NULL_PTR || n == 0){
        return dest;
    }
    
    char *d = static_cast<char *>(dest);
    const char *s = static_cast<const char *>(src);

    return dest;
};

}