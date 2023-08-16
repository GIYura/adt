#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>
#include <stdbool.h>

/* Circular buffer containing any generic type*/
/* For best practice, this struct should not be used directly outside the module */
typedef struct
{
    /* Index of head of buffer */
    uint16_t start;

    /* Index of next available space */
    uint16_t end;

    /* Size of each buffer element in bytes */
    uint16_t typeSize;

    /* bool to denote behavior when
       buffer is full and a new element is added
       true - buffer will drop oldest element
       false - buffer will discard new element
     */
    bool overwrite;

    /* Memory allocated for buffer data storage and associated length */
    uint8_t* data;
    uint16_t dataLength;
} Buffer_t;

/* @brief   Creates a generic buffer struct
 * @param   buffer,    buffer handle
 * @param   data,      pre-allocated array to store the buffer data
 * @param   length     length of the pre-allocated data array in bytes.
 *                     Must by sufficient to store N+1 elements, where N is the desired capacity of the Buffer
 * @param   typeSize,  size of each buffer element (ie. sizeof(float) to create a Buffer of floats)
 * @parm    overwrite, true to drop oldest element when full, false to discard new element when full
 */
void Buffer_Create(Buffer* const buffer, void* const data, uint16_t length, uint16_t typeSize, bool overwrite);

uint16_t Buffer_Capacity(const Buffer* const buffer);

void Buffer_Clear(Buffer* const buffer);

/*@brief    Returns the number of elements in the buffer
 */
uint16_t Buffer_Count(const Buffer* const buffer);

/*@brief    Places a new element in the buffer
 *          If the buffer is full, either the oldest
 *          item or new item is discarded, depending
 *          on the value of the 'overwrite' field
 *@parm     buffer, buffer handle
 *@parm     data, pointer to element (of typeSize) to put into the buffer
 *@parm     size, size of data (should always be equal to typeSize)
 *@return   true if the data was added to the buffer, false otherwise
 */
bool Buffer_Put(Buffer* const buffer, const void* const data, uint16_t size);
bool Buffer_PutFloat(Buffer* const buffer, float data);
bool Buffer_PutUInt32(Buffer* const buffer, uint32_t data);
bool Buffer_PutUInt16(Buffer* const buffer, uint16_t data);
bool Buffer_PutUInt8(Buffer* const buffer, uint8_t data);
bool Buffer_PutInt32(Buffer* const buffer, int32_t data);
bool Buffer_PutInt16(Buffer* const buffer, int16_t data);
bool Buffer_PutInt8(Buffer* const buffer, int8_t data);

/*@brief    Retrieves the element at the head of the buffer
 *@parm     buffer, buffer handle
 *@parm     data, memory area (of typeSize) to store retrieved buffer element
 *@parm     size, size of data (should always be equal to typeSize)
 *@return   true if the item was retrieved; false if the buffer was empty
 */
bool Buffer_Get(Buffer* const buffer, void* const data, uint16_t size);

/*@brief    Peeks at the element at the head of the buffer without removing it
 *@parm     buffer, buffer handle
 *@parm     data, memory area (of typeSize) to store retrieved buffer element
 *@parm     size, size of data (should always be equal to typeSize)
 *@return   true if the item was retrieved; false if the buffer was empty
 */
bool Buffer_Peek(const Buffer* const buffer, void* const data, uint16_t size);

bool Buffer_IsEmpty(const Buffer* const buffer);

bool Buffer_IsFull(const Buffer* const buffer);

/*@brief    Retrieves the element at the head of the buffer
 *@parm     buffer, input buffer handle
 *@parm     array, output array
 *@parm     size, size of output array in bytes
 *@return   true if the conversion was successful; false otherwise
 */
bool Buffer_ToArray(const Buffer* const buffer, void* const array, uint16_t size);

#endif /* BUFFER_H */



