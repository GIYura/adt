#include "buffer.h"
#include <stdio.h>

#define BUFFER_SIZE 10

static int m_buffer[BUFFER_SIZE];

void BufferInit(void)
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        m_buffer[i] = i;
    }
}

void BufferPrint(void)
{
    printf("Buffer size: %d items\n", BUFFER_SIZE);
    printf("Buffer: ");
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%d ", m_buffer[i]);
    }
    printf("\n");
}

