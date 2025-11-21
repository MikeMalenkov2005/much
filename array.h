#ifndef _MUCH_ARRAY_H
#define _MUCH_ARRAY_H

#include "types.h"
#include <stdlib.h>

#define array_length(array) \
  (((const USize*)((const Byte*)(array) - 16))[0])

#define array_create(T, length) \
  ((T*)((Byte*)&(*(USize*)calloc( \
        1, (length) * sizeof(T) + 16) = (length)) + 16))

#define array_delete(array) \
  (free((Byte*)(array) - 16))

#endif

