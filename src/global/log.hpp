#ifndef GLOBAL_LOG
#define GLOBAL_LOG
#pragma once
#include "./type/type.hpp"
enum LOG_SIGN{
    SYS_DIE = -1,
    SYS_ERROR = 0,
    SYS_FAILED = 1,
    SYS_WARNING = 2,
    SYS_TIP = 3,
    SYS_MSG = 4,
    SYS_PASS = 5
};

void sys_warning(
    STXT warnning_msg,
    enum LOG_SIGN sign
);

extern LOG_SIGN SYS_STATUS;

#endif