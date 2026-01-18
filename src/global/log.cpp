#include "log.hpp"

LOG_SIGN SYS_STATUS;

void sys_warning(
    STXT warnning_msg,
    enum LOG_SIGN sign
){
    if (sign == SYS_ERROR){
        SYS_STATUS = SYS_ERROR;
    }
    
    ;
};