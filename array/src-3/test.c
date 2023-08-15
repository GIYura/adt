/*
TETS src-3
*/
#include "buffer.h"

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(int argc, char* argv[])
{
    int* pBuff = (int*)malloc(sizeof(int) * BUFFER_SIZE);
    
    if (!pBuff)
    {
        printf("Can't allocate memory\n");
        return -1;
    }

    BufferInit(pBuff, BUFFER_SIZE);
    
    BufferPrint(pBuff, BUFFER_SIZE);

    free(pBuff);
    
    return 0;
}
