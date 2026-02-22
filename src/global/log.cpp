#include "log.hpp"

LOG_SIGN SYS_STATUS;

void sys_warning(
    STXT warning_msg,
    enum LOG_SIGN sign
){
    if (sign < SYS_STATUS){
        SYS_STATUS = sign;
    }
    
    kprint(warning_msg);
};

#ifdef QEMU 

inline void qpb(unsigned char val){
    const char *hex_digits = "0123456789ABCDEF";
    char hex_str[2];
    hex_str[0] = hex_digits[(val >> 4) & 0x0F];
    hex_str[1] = hex_digits[val & 0x0F];
    for(int i = 0;i < 2;i++){
        outb(hex_str[i], 0x3F8);
    }
}

inline void qpw(unsigned short val){
    const char *hex_digits = "0123456789ABCDEF";
    char hex_str[4];
    hex_str[0] = hex_digits[(val >> 12) & 0x0F];
    hex_str[1] = hex_digits[(val >> 8) & 0x0F];
    hex_str[2] = hex_digits[(val >> 4) & 0x0F];
    hex_str[3] = hex_digits[val & 0x0F];
    for(int i = 0;i < 4;i++){
        outb(hex_str[i], 0x3F8);
    }
}

inline void qpl(unsigned val){
    const char *hex_digits = "0123456789ABCDEF";
    char hex_str[8];
    hex_str[0] = hex_digits[(val >> 28) & 0x0F];
    hex_str[1] = hex_digits[(val >> 24) & 0x0F];
    hex_str[2] = hex_digits[(val >> 20) & 0x0F];
    hex_str[3] = hex_digits[(val >> 16) & 0x0F];
    hex_str[4] = hex_digits[(val >> 12) & 0x0F];
    hex_str[5] = hex_digits[(val >> 8) & 0x0F];
    hex_str[6] = hex_digits[(val >> 4) & 0x0F];
    hex_str[7] = hex_digits[val & 0x0F];
    for(int i = 0;i < 8;i++){
        outb(hex_str[i], 0x3F8);
    }
}

inline void qps(const char *val){
    for(int i = 0;val[i];i++){
        outb(val[i], 0x3F8);
    }
}

#else 
void qps(const char *val){}
void qpb(unsigned char val){}
void qpw(unsigned short val){}
void qpl(unsigned val){}
#endif