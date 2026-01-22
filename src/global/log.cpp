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