#include "buffer.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int* buff = BufferInit(10);
    
    if (buff)
    {
        BufferPrint(buff, 10);
        free(buff);
    }
    
    return 0;
}
