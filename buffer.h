#ifndef _DSH_BUFFER_H
#define _DSH_BUFFER_H

#include "types.h"
#include "utils.h"

typedef struct Buffer
{
  USize length;
  USize position;
  void *data;
} Buffer;

#define buffer_static(data) { sizeof(data), 0, (data) }

CAPI_BEGIN

Buffer buffer_wrap(void *data, USize size);

Buffer *buffer_create(USize capacity);

void buffer_delete(Buffer *buffer);

void buffer_flip(Buffer *buffer);

Bool buffer_write(Buffer *buffer, const void *data, USize size);

Bool buffer_write_byte(Buffer *buffer, Byte value);

Bool buffer_write_short(Buffer *buffer, Short value);

Bool buffer_write_int(Buffer *buffer, Int value);

Bool buffer_write_long(Buffer *buffer, Long value);

Bool buffer_write_boolean(Buffer *buffer, Boolean value);

Bool buffer_read(Buffer *buffer, void *data, USize size);

Bool buffer_read_byte(Buffer *buffer, Byte *value);

Bool buffer_read_short(Buffer *buffer, Short *value);

Bool buffer_read_int(Buffer *buffer, Int *value);

Bool buffer_read_long(Buffer *buffer, Long *value);

Bool buffer_read_boolean(Buffer *buffer, Boolean *value);

CAPI_END

#endif

