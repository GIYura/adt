/*
TEST src-0

1. Create CB without overwrite
    1.1 Fill CD with indexes, once CB full, discard new items;
    1.2 Retrive items from CB and print them.

2. Create CB with overwrite
    2.1 Fill CB with indexes, once CB full, overwrite oldest items;
    2.2 Retrieve items fromr CB and print them.
*/

#include <stdio.h>
#include "buffer.h"

#define BUFFER_SIZE 10

static Buffer_t m_bufferOverwriteOff;
static Buffer_t m_bufferOverwriteOn;

static int m_dataBuffer[BUFFER_SIZE + 1];

int main(int argc, char* argv[])
{
    /* create buffer without overwrite */
    printf("Overwrite OFF\n");
    BufferCreate(&m_bufferOverwriteOff, m_dataBuffer, sizeof(m_dataBuffer), sizeof(int), false);

    /* fill buffer with indexes */
    for (int i = 0; i < 100; i++)
    {
        if (!BufferPut(&m_bufferOverwriteOff, &i, sizeof(int)))
        {
            printf("Buffer is full\n");
            break;
        }
    }

    printf("Buffer: ");

    /* retrieve data from buffer and print */
    for (int i = 0; i < 100; i++)
    {
        int data;
        if (!BufferGet(&m_bufferOverwriteOff, &data, sizeof(int)))
        {
            printf("\nBuffer is empty\n");
            break;
        }
        printf("%d ", data);
    }
    printf("\n");

    /* create buffer with overwrite */
    printf("Overwrite ON\n");
    BufferCreate(&m_bufferOverwriteOn, m_dataBuffer, sizeof(m_dataBuffer), sizeof(int), true);

    /* fill buffer with indexes */
    for (int i = 0; i < 14; i++)
    {
        BufferPut(&m_bufferOverwriteOn, &i, sizeof(int));
    }

    printf("Buffer: ");

    /* retrieve data from buffer and print */
    for (int i = 0; i < 100; i++)
    {
        int data;
        if (!BufferGet(&m_bufferOverwriteOn, &data, sizeof(int)))
        {
            printf("\nBuffer is empty\n");
            break;
        }
        printf("%d ", data);
    }
    return 0;
}

