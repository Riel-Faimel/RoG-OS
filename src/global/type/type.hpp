#pragma once
#define NULL_PTR 0

using s8 = __signed__ char;
using u8 = unsigned char;

using s16 = __signed__ short;
using u16 = unsigned short;

using s32 = __signed__ int;
using u32 = unsigned int;

using s64 = __signed__ long long;
using u64 = unsigned long long;

#ifdef __CHECK_ENDIAN__
#define __bitwise __bitwise__
#else
#define __bitwise
#endif

#ifndef x86_64
#ifndef STM32
#define x86_64
#endif
#endif

#ifdef STM32
typedef unsigned size_t;

typedef unsigned long uintptr_t;
typedef long intptr_t;
#endif
#ifdef x86_64
#ifndef _SIZE_T
#define _SIZE_T
using size_t = __SIZE_TYPE__;

using uintptr_t = unsigned long long;
using intptr_t = long long;
#endif
#endif


using lu8 = u8 __bitwise;
using bu8 = u8 __bitwise;
using lu16 = u16 __bitwise;
using bu16 = u16 __bitwise;
using lu32 = u32 __bitwise;
using bu32 = u32 __bitwise;
using lu64 = u64 __bitwise;
using bu64 = u64 __bitwise;

using BYTE = unsigned char;
using STXT = const char *;
