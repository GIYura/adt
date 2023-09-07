#include <string.h>
#include <stdlib.h>

#include "functions.h"

char g_Message[BUFFER_SIZE] = "HELLO";

char* LocalBuffer(void)
{
/*
NOTE: generate warning due to returning address of local variable
*/
    char message[] = "Local Buffer";
    return message;
}

char* StringLiteral(void)
{
    char* message = "Return String Literal";
    return message;
}

char* GlobalBuffer(void)
{
    strncpy(g_Message, "Modify Global Buffer", BUFFER_SIZE);
    return g_Message;
}

char* StaticBuffer(void)
{
    static char message[BUFFER_SIZE];
    strncpy(message, "Return Static buffer", BUFFER_SIZE);
    return message;
}

char* DynamicBuffer(void)
{
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    strncpy(buffer, "Return dynamically allocated buffer", BUFFER_SIZE);
    return buffer;
}

void ModifyDynamicBuffer(char* buffer, int bufferSize)
{
    strncpy(buffer, "Modify dynamically allocated buffer", bufferSize);
}

void ModifyWrappedBuffer(Buffer_t* buffer, int bufferSize)
{
    strncpy(buffer->data, "Modify Wrapped buffer", bufferSize);
}

Buffer_t WrappedBuffer(int bufferSize)
{
    Buffer_t buffer;

    strncpy(buffer.data, "Return Wrapped buffer", bufferSize);
    return buffer;
}

