#pragma once
#include <modf/modifier.hpp>

namespace KRN
{
    namespace MODF
    {
        class Modf;
        extern Modf* modf_ptr;
    } // namespace MODF
    namespace LAS
    {
        class LAspace;
    } // namespace LAS
} // namespace KRN

using KRN::MODF::modf_ptr;
using KRN::MODF::Modf;

enum class MODE : int{
    NO = -1,
    READ = 0,
    R_W = 1,
    WRITE = 2
};

#pragma pack(push, 8)
class WIN{
public:
    unsigned id;
    MODE mode; //int * 2 = 8bytes
    unsigned long long sign; // all for 8 + 8 = 16bytes
    WIN();
    ~WIN();
    void set_mode(MODE target);
    operator void *();
};
#pragma pop

#pragma pack(push, 8)
template<unsigned N>
class Window : public WIN {
public:
    size_t buffer_size; // above for 16 + 8 = 24bytes
    BYTE buffer[N];
    friend class KRN::MODF::Modf;
    friend class KRN::LAS::LAspace;
    Window():
    WIN(),
    buffer_size(N){
        ;
    }
    ~Window(){
        ;
    }
    inline BYTE &operator[](unsigned offset){
        return buffer[offset];
    }
    inline const BYTE &operator[](unsigned offset)const{
        return buffer[offset];
    };
};
#pragma pop
