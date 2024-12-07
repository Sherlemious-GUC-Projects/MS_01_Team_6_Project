#pragma once

#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct
{
    char buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void buffer_init(CircularBuffer *cb);

bool buffer_is_empty(CircularBuffer *cb);

bool buffer_is_full(CircularBuffer *cb);

void buffer_write(CircularBuffer *cb, char c);

char buffer_read(CircularBuffer *cb);