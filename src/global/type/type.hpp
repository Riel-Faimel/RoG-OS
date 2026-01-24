#pragma once
#define NULL_PTR 0

typedef __signed__ char s8;
typedef unsigned char u8;

typedef __signed__ short s16;
typedef unsigned short u16;

typedef __signed__ int s32;
typedef unsigned int u32;

typedef __signed__ long long s64;
typedef unsigned long long u64;

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
#endif
#ifdef x86_64
#ifndef _SIZE_T
#define _SIZE_T
typedef __SIZE_TYPE__ size_t;
#endif
#endif


typedef u8 __bitwise lu8;
typedef u8 __bitwise bu8;
typedef u16 __bitwise lu16;
typedef u16 __bitwise bu16;
typedef u32 __bitwise lu32;
typedef u32 __bitwise bu32;
typedef u64 __bitwise lu64;
typedef u64 __bitwise bu64;

typedef unsigned char BYTE;
typedef const char * STXT;
