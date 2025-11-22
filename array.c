#ifndef _MUCH_ARRAY_C
#define _MUCH_ARRAY_C

#include "array.h"
#include <stdlib.h>

typedef struct ArrayInfo
{
  USize length;
  void *data;
} ArrayInfo;

CAPI_BEGIN

Bool __much_array_resize(void **array, USize type_size, USize length)
{
  ArrayInfo *info;
  if (!array || !type_size || !length) return FALSE;
  if ((info = *array))
  {
    if ((--info)->length == length) return TRUE;
    if (info->data != info + 1) return FALSE;
  }
  if (!(info = realloc(info, sizeof(*info) + type_size * length))) return FALSE;
  *array = info->data = info + 1;
  return TRUE;
}

void *__much_array_create(USize type_size, USize length)
{
  void *array = NULL;
  __much_array_resize(&array, type_size, length);
  return array;
}

USize array_length(void *array)
{
  ArrayInfo *info = array;
  return info-- && info->data == info + 1 ? info->length : 0;
}

void array_delete(void *array)
{
  ArrayInfo *info = array;
  if (info-- && info->data == info + 1) free(info);
}

CAPI_END

#endif

