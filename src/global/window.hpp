#pragma once
#include <modf/modifier.hpp>

namespace KRN::MODF
{
    class Modf;
    extern Modf* modf_ptr;
} // namespace KRN::MODF

using KRN::MODF::modf_ptr;
using KRN::MODF::Modf;

enum class MODE : int{
    NO = -1,
    READ = 0,
    R_W = 1,
    WRITE = 2
};

template<unsigned N>
class Window{
private:
    unsigned id;
    unsigned buffer_size;
    MODE mode;
    unsigned char sign;
    friend class KRN::MODF::Modf;
public:
    BYTE buffer[N];
    Window():
    buffer_size(N),
    sign(0){
        modf_ptr->template regist_window<N>(this);
    }
    ~Window(){
        modf_ptr->clear_window(id);
    }
    inline BYTE &operator[](unsigned offset){
        return buffer[offset];
    }
    inline const BYTE &operator[](unsigned offset)const{
        return buffer[offset];
    };
    
    void set_mode(MODE target){
        modf_ptr->template deal_mode<N>(this);
    }
};
