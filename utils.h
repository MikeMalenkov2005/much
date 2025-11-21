#ifndef _MUCH_UTILS_H
#define _MUCH_UTILS_H

#define STMT(S) do { S } while (0);

#define _STRING(S) #S
#define STRING(S) _STRING(S)

#define _GLUE(A, B) A ## B
#define GLUE(A, B) _GLUE(A, B)

#define ARRLEN(array) (sizeof(array) / sizeof(*array))

#define PTR2INT(ptr)  ((char*)(ptr) - (char*)0)
#define INT2PTR(val)  ((void*)((char*)0 + (val)))

#define MAX(A, B) ((A) < (B) ? (B) : (A))
#define MIN(A, B) ((A) > (B) ? (B) : (A))
#define ABS(X) MAX((X), -(X))

#define MEMBER(T, M)  (((T*)0)->M)
#define OFFSET(T, M)  PTR2INT(&MEMBER(T, M))

#ifdef __cplusplus
#define CAPI_BEGIN  extern "C" {
#define CAPI_END    }
#define CAPI        extern "C"
#else
#define CAPI_BEGIN
#define CAPI_END
#define CAPI
#endif

#endif

