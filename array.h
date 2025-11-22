#ifndef _MUCH_ARRAY_H
#define _MUCH_ARRAY_H

#include "types.h"
#include "utils.h"

CAPI_BEGIN

Bool __much_array_resize(void **array, USize type_size, USize length);

void *__much_array_create(USize type_size, USize length);

USize array_length(void *array);

void array_delete(void *array);

CAPI_END

#define array_create(T, length) \
  ((T*)__much_array_create(sizeof(T), (length)))

#define array_resize(array, length) \
  __much_array_resize((array), sizeof(**(array)), (length))

#endif

