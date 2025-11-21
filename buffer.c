#ifndef _DSH_BUFFER_C
#define _DSH_BUFFER_C

#include "buffer.h"
#include <stdlib.h>
#include <string.h>

CAPI_BEGIN

Buffer buffer_wrap(void *data, USize size)
{
  Buffer buffer = { 0 };
  buffer.length = size;
  buffer.data = data;
  return buffer;
}

Buffer *buffer_create(USize capacity)
{
  Buffer *buffer = NULL;
  if (capacity && (buffer = malloc(sizeof(*buffer) + capacity)))
  {
    buffer->length = capacity;
    buffer->position = 0;
    buffer->data = (void*)(buffer + 1);
  }
  return buffer;
}

void buffer_delete(Buffer *buffer)
{
  if (buffer) free(buffer);
}

void buffer_flip(Buffer *buffer)
{
  if (buffer)
  {
    buffer->length = buffer->position;
    buffer->position = 0;
  }
}

Bool buffer_write(Buffer *buffer, const void *data, USize size)
{
  if (!buffer || buffer->length - buffer->position < size) return FALSE;
  memcpy(buffer->data + buffer->position, data, size);
  buffer->position += size;
  return TRUE;
}

Bool buffer_write_byte(Buffer *buffer, Byte value)
{
  return buffer_write(buffer, &value, sizeof(value));
}

Bool buffer_write_short(Buffer *buffer, Short value)
{
  return buffer_write(buffer, &value, sizeof(value));
}

Bool buffer_write_int(Buffer *buffer, Int value)
{
  return buffer_write(buffer, &value, sizeof(value));
}

Bool buffer_write_long(Buffer *buffer, Long value)
{
  return buffer_write(buffer, &value, sizeof(value));
}

Bool buffer_write_boolean(Buffer *buffer, Boolean value)
{
  return buffer_write(buffer, &value, sizeof(value));
}

Bool buffer_read(Buffer *buffer, void *data, USize size)
{
  if (!buffer || buffer->length - buffer->position < size) return FALSE;
  memcpy(data, buffer->data + buffer->position, size);
  buffer->position += size;
  return TRUE;
}

Bool buffer_read_byte(Buffer *buffer, Byte *value)
{
  return buffer_read(buffer, value, sizeof(*value));
}

Bool buffer_read_short(Buffer *buffer, Short *value)
{
  return buffer_read(buffer, value, sizeof(*value));
}

Bool buffer_read_int(Buffer *buffer, Int *value)
{
  return buffer_read(buffer, value, sizeof(*value));
}

Bool buffer_read_long(Buffer *buffer, Long *value)
{
  return buffer_read(buffer, value, sizeof(*value));
}

Bool buffer_read_boolean(Buffer *buffer, Boolean *value)
{
  return buffer_read(buffer, value, sizeof(*value));
}

CAPI_END

#endif

