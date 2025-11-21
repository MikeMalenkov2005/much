#ifndef _DSH_TYPES_H
#define _DSH_TYPES_H

/* Java/Kotlin style primitive typedefs */

#include <stddef.h>
#include <limits.h>

#if INT_MAX != 0x7FFFFFFFL
#error Int is expected to be 32-bit.
#endif

typedef char Char;

typedef signed char Byte;
typedef signed short Short;
typedef signed int Int;
#if LONG_MAX > INT_MAX || !defined(LLONG_MAX)
typedef signed long Long;
#else
typedef signed long long Long;
#endif

typedef unsigned char UByte;
typedef unsigned short UShort;
typedef unsigned int UInt;
#if LONG_MAX > INT_MAX || !defined(LLONG_MAX)
typedef unsigned long ULong;
#else
typedef unsigned long long ULong;
#endif

typedef size_t USize;
typedef ptrdiff_t SSize, PtrDiff;

typedef int Bool;

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
typedef char Boolean;
#elif __STDC_VERSION__ < 202410L
typedef _Bool Boolean;
#else
typedef bool Boolean;
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef void *Object;

#endif

