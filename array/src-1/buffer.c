#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>

static int m_bufferSize;

int* BufferInit(int size)
{
    int* pBuffer = (int*)malloc(sizeof(int) * size);
    if (!pBuffer)
    {
        printf("Can't allocate buffer of %d size\n", size);
        return NULL;
    }

    m_bufferSize = size;

    for (int i = 0; i < m_bufferSize; i++)
    {
        pBuffer[i] = i;
    }

    return pBuffer;
}

void BufferPrint(const int* const buffer, int size)
{
    printf("Buffer size: %d items\n", m_bufferSize);
    if (buffer)
    {
        printf("Buffer: ");
        for (int i = 0; i < m_bufferSize; i++)
        {
            printf("%d ", buffer[i]);
        }
        printf("\n");
    }
}

