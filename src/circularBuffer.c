#include "../include/circularBuffer.h"

void buffer_init(CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

bool buffer_is_empty(CircularBuffer *cb)
{
    return cb->count == 0;
}

bool buffer_is_full(CircularBuffer *cb)
{
    return cb->count == BUFFER_SIZE;
}

void buffer_write(CircularBuffer *cb, char c)
{
    if (!buffer_is_full(cb))
    {
        cb->buffer[cb->head] = c;
        cb->head = (cb->head + 1) % BUFFER_SIZE;
        cb->count++;
    }
}

char buffer_read(CircularBuffer *cb)
{
    char c = '\0';
    if (!buffer_is_empty(cb))
    {
        c = cb->buffer[cb->tail];
        cb->tail = (cb->tail + 1) % BUFFER_SIZE;
        cb->count--;
    }
    return c;
}