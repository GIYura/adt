/*
TEST src-0

1. Create a Stack
2. Fill with loop indexes
3. Retrieve data from Stack and print them.
*/
#include "stack.h"
#include <stdio.h>

#define BUFFER_SIZE 5

static int m_buffer[BUFFER_SIZE];
static Stack_t m_stack;

int main(int argc, char* argv[])
{
    StackInit(&m_stack, m_buffer, BUFFER_SIZE);

    for (int i = 0; i < 10; i++)
    {
        if (!StackPush(&m_stack, i))
        {
            printf("Stack is Full\n");
            break;
        }
    }

    printf("Stack: ");

    for (int i = 0; i < 10; i++)
    {
        int value;
        if (!StackPop(&m_stack, &value))
        {
            printf("\nStack is Empty\n");
            break;
        }
        else
        {
            printf("%d ", value);
        }
    }
    printf("\n");

    return 0;
}

