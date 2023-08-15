#include "buffer.h"
#include <stdio.h>
#include <assert.h>

void BufferInit(int* const buffer, int const size)
{
    assert(size > 0);

    for (int i = 0; i < size; i++)
    {
        buffer[i] = i;
    }
}

void BufferPrint(const int* const buffer, int const size)
{
    assert(size > 0);

    printf("Buffer size: %d items\n", size);
    printf("Buffer: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

