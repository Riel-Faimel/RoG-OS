#pragma once
#define NULL_PTR 0

typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;

typedef __signed__ long __s64;
typedef unsigned long __u64;

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


typedef __u8 __bitwise __le8;
typedef __u8 __bitwise __be8;
typedef __u16 __bitwise __le16;
typedef __u16 __bitwise __be16;
typedef __u32 __bitwise __le32;
typedef __u32 __bitwise __be32;
typedef __u64 __bitwise __le64;
typedef __u64 __bitwise __be64;

typedef unsigned char BYTE;
typedef const char * STXT;
