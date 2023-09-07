/*
TEST - 0
This file demonstrates 7 ways of returning an array from a function
*/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define LOCAL_ADDRESS           0
#define STRING_LITERAL          0
#define GLOBAL_BUFFER           0
#define STATIC_BUFFER           1
#define DYNAMIC_BUFFER          0
#define PREALLOCATED_BUFFER     0
#define MOD_WRAPPED_BUFFER      0
#define RET_WRAPPED_BUFFER      0

/*
-----------------MAIN--------------------
*/
int main(int argc, char* argv[])
{
/*
NOTE: NEVER DO THIS !!!
*/
#if LOCAL_ADDRESS
/*
NOTE: won't compile, array in C not modifiable lvalue
*/
#if 0
    char buffer[];
    buffer = LocalBuffer();
    printf("%s\n", buffer);
#endif

/*
NOTE: lead to Segmantation fault error.
pBuffer value is nil, on attempt dereference it, the error occurred.
*/
#if 0
    char* pBuffer;
    pBuffer = LocalBuffer();
    printf("%s\n", pBuffer);
#endif

#elif STRING_LITERAL
    char* str = StringLiteral();
    printf("%s\n", str);

#elif GLOBAL_BUFFER
    char* buffer = GlobalBuffer();
    printf("%s\n", buffer);

#elif STATIC_BUFFER
    char* buffer = StaticBuffer();
    printf("%s\n", buffer);

#elif DYNAMIC_BUFFER
    char* buffer = NULL;
    buffer = DynamicBuffer();
    if (buffer)
    {
        printf("%s\n", buffer);
        free(buffer);
    }

#elif PREALLOCATED_BUFFER
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (buffer)
    {
        ModifyDynamicBuffer(buffer, BUFFER_SIZE);
        printf("%s\n", buffer);
        free(buffer);
    }

#elif MOD_WRAPPED_BUFFER
    Buffer_t buffer;
    ModifyWrappedBuffer(&buffer, BUFFER_SIZE);
    printf("%s\n", buffer.data);

#elif RET_WRAPPED_BUFFER
    Buffer_t buffer;
    buffer = WrappedBuffer(BUFFER_SIZE);
    printf("%s\n", buffer.data);
#endif

    return 0;
}

