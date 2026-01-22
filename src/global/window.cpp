#include "window.hpp"

WIN::WIN():
sign(0){
    modf_ptr->regist_window(this);
};

void WIN::set_mode(MODE target){
    modf_ptr->deal_mode(this);
}

WIN::~WIN(){
    modf_ptr->clear_window(this);
}

WIN::operator void *(){
    return static_cast<void *>(reinterpret_cast<long long *>(this) + 3);
}