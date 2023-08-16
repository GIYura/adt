#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"

static uint16_t NextIndex(const Buffer_t* const buffer, uint16_t index)
{
    return (index + buffer->typeSize) % buffer->dataLength;
}

void BufferCreate(Buffer_t* buffer, void* const data, uint16_t length, uint16_t typeSize, bool overwrite)
{
    assert(buffer != NULL && data != NULL && length >= typeSize * 2);

    buffer->dataLength = length;
    buffer->data = data;
    buffer->typeSize = typeSize;
    buffer->start = 0;
    buffer->end = 0;
    buffer->overwrite = overwrite;
}

uint16_t BufferCapacity(const Buffer_t* const buffer)
{
    return (buffer->dataLength - buffer->typeSize) / buffer->typeSize;
}

void BufferClear(Buffer_t* const buffer)
{
    buffer->start = 0;
    buffer->end = 0;
}

uint16_t BufferCount(const Buffer_t* const buffer)
{
    uint16_t count;

    if (buffer->end >= buffer->start)
    {
        count = buffer->end - buffer->start;
    }
    else
    {
        count = buffer->dataLength - buffer->start + buffer->end;
    }

    return (count / buffer->typeSize);
}

bool BufferPut(Buffer_t* const buffer, const void* const data, uint16_t size)
{
    assert(buffer->data != NULL && data != NULL);
    assert(size == buffer->typeSize);

    if (BufferIsFull(buffer) )
    {
        if (!buffer->overwrite)
        {
            return false;
        }

        /* Buffer is full, drop oldest data */
        buffer->start = NextIndex(buffer, buffer->start);
    }
    memcpy(&(buffer->data[buffer->end]), data, buffer->typeSize);
    buffer->end = NextIndex(buffer, buffer->end);
    return true;
}

bool BufferPutFloat(Buffer_t* const buffer, float data)
{
    assert(buffer->typeSize == sizeof(float));
    return BufferPut(buffer, (void*)&data, sizeof(float));
}

bool BufferPutUInt32(Buffer_t* const buffer, uint32_t data)
{
    assert(buffer->typeSize == sizeof(uint32_t));
    return BufferPut(buffer, (void*)&data, sizeof(uint32_t));
}

bool BufferPutUInt16(Buffer_t* const buffer, uint16_t data)
{
    assert(buffer->typeSize == sizeof(uint16_t));
    return BufferPut(buffer, (void*)&data, sizeof(uint16_t));
}

bool BufferPutUInt8(Buffer_t* const buffer, uint8_t data)
{
    assert(buffer->typeSize == sizeof(uint8_t));
    return BufferPut(buffer, (void*)&data, sizeof(uint8_t));
}

bool BufferPutInt32(Buffer_t* const buffer, int32_t data)
{
    assert(buffer->typeSize == sizeof(int32_t));
    return BufferPut(buffer, (void*)&data, sizeof(int32_t));
}

bool BufferPutInt16(Buffer_t* const buffer, int16_t data)
{
    assert(buffer->typeSize == sizeof(int16_t));
    return BufferPut(buffer, (void*)&data, sizeof(int16_t));
}

bool BufferPutInt8(Buffer_t* const buffer, int8_t data)
{
    assert(buffer->typeSize == sizeof(int8_t));
    return BufferPut(buffer, (void*)&data, sizeof(int8_t));
}

bool BufferIsEmpty(const Buffer_t* const buffer)
{
    assert(buffer->data != NULL);
    return buffer->end == buffer->start;
}

bool BufferIsFull(const Buffer_t* const buffer)
{
    assert(buffer->data != NULL);
    return NextIndex(buffer, buffer->end) == buffer->start;
}

bool BufferGet(Buffer_t* const buffer, void* data, uint16_t size)
{
    assert(data != NULL);
    assert(buffer->data != NULL);
    assert(size == buffer->typeSize);

    if (BufferIsEmpty(buffer))
    {
        return false;
    }

    memcpy(data, &(buffer->data[buffer->start]), buffer->typeSize);
    buffer->start = NextIndex(buffer, buffer->start);
    return true;
}

bool BufferPeek(const Buffer_t* const buffer, void* const data, uint16_t size)
{
    assert(data != NULL);
    assert(buffer->data != NULL);
    assert(size == buffer->typeSize);

    if (BufferIsEmpty(buffer))
    {
        return false;
    }

    memcpy(data, &(buffer->data[buffer->start]), buffer->typeSize);
    return true;
}

bool BufferToArray(const Buffer_t* const buffer, void* const array, uint16_t size)
{
    assert(buffer->data != NULL);
    assert(array != NULL);
    assert(size >= BufferCount(buffer) );

    if (BufferIsEmpty(buffer))
    {
        return false;
    }

    uint16_t arrayIndex = 0;
    uint16_t bufferIndex = buffer->start;
    while (bufferIndex != buffer->end)
    {
        memcpy(&((uint8_t*)array)[arrayIndex * buffer->typeSize], &buffer->data[bufferIndex], buffer->typeSize);
        bufferIndex = NextIndex(buffer, bufferIndex);
        arrayIndex++;
    }
    return true;
}

