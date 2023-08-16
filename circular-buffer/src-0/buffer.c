#include "assertion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"
#include "SerialConsole.h"
#define LOG_LEVEL        LOG_LEVEL_BASIC

static uint16_t NextIndex(const Buffer* const buffer, uint16_t index)
{
    return (index + buffer->typeSize) % buffer->dataLength;
}

void Buffer_Create(Buffer* buffer, void* const data, uint16_t length, uint16_t typeSize, bool overwrite)
{
    ASSERT(buffer != NULL && data != NULL && length >= typeSize * 2);

    buffer->dataLength = length;
    buffer->data = data;
    buffer->typeSize = typeSize;
    buffer->start = 0;
    buffer->end = 0;
    buffer->overwrite = overwrite;
}

uint16_t Buffer_Capacity(const Buffer* const buffer)
{
    return (buffer->dataLength - buffer->typeSize) / buffer->typeSize;
}

void Buffer_Clear(Buffer* const buffer)
{
    buffer->start = 0;
    buffer->end = 0;
}

uint16_t Buffer_Count(const Buffer* const buffer)
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

bool Buffer_Put(Buffer* const buffer, const void* const data, uint16_t size)
{
    ASSERT(buffer->data != NULL && data != NULL);
    ASSERT(size == buffer->typeSize);

    if (Buffer_IsFull(buffer) )
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

bool Buffer_PutFloat(Buffer* const buffer, float data)
{
    ASSERT(buffer->typeSize == sizeof(float));
    return Buffer_Put(buffer, (void*)&data, sizeof(float));
}

bool Buffer_PutUInt32(Buffer* const buffer, uint32_t data)
{
    ASSERT(buffer->typeSize == sizeof(uint32_t));
    return Buffer_Put(buffer, (void*)&data, sizeof(uint32_t));
}

bool Buffer_PutUInt16(Buffer* const buffer, uint16_t data)
{
    ASSERT(buffer->typeSize == sizeof(uint16_t));
    return Buffer_Put(buffer, (void*)&data, sizeof(uint16_t));
}

bool Buffer_PutUInt8(Buffer* const buffer, uint8_t data)
{
    ASSERT(buffer->typeSize == sizeof(uint8_t));
    return Buffer_Put(buffer, (void*)&data, sizeof(uint8_t));
}

bool Buffer_PutInt32(Buffer* const buffer, int32_t data)
{
    ASSERT(buffer->typeSize == sizeof(int32_t));
    return Buffer_Put(buffer, (void*)&data, sizeof(int32_t));
}

bool Buffer_PutInt16(Buffer* const buffer, int16_t data)
{
    ASSERT(buffer->typeSize == sizeof(int16_t));
    return Buffer_Put(buffer, (void*)&data, sizeof(int16_t));
}

bool Buffer_PutInt8(Buffer* const buffer, int8_t data)
{
    ASSERT(buffer->typeSize == sizeof(int8_t));
    return Buffer_Put(buffer, (void*)&data, sizeof(int8_t));
}

bool Buffer_IsEmpty(const Buffer* const buffer)
{
    ASSERT(buffer->data != NULL);
    return buffer->end == buffer->start;
}

bool Buffer_IsFull(const Buffer* const buffer)
{
    ASSERT(buffer->data != NULL);
    return NextIndex(buffer, buffer->end) == buffer->start;
}

bool Buffer_Get(Buffer* const buffer, void* data, uint16_t size)
{
    ASSERT(data != NULL);
    ASSERT(buffer->data != NULL);
    ASSERT(size == buffer->typeSize);

    if (Buffer_IsEmpty(buffer) )
    {
        return false;
    }

    memcpy(data, &(buffer->data[buffer->start]), buffer->typeSize);
    buffer->start = NextIndex(buffer, buffer->start);
    return true;
}

bool Buffer_Peek(const Buffer* const buffer, void* const data, uint16_t size)
{
    ASSERT(data != NULL);
    ASSERT(buffer->data != NULL);
    ASSERT(size == buffer->typeSize);

    if (Buffer_IsEmpty(buffer) )
    {
        return false;
    }

    memcpy(data, &(buffer->data[buffer->start]), buffer->typeSize);
    return true;
}

bool Buffer_ToArray(const Buffer* const buffer, void* const array, uint16_t size)
{
    ASSERT(buffer->data != NULL);
    ASSERT(array != NULL);
    ASSERT(size >= Buffer_Count(buffer) );

    if (Buffer_IsEmpty(buffer) )
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


