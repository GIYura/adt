#include "stack.h"
#include <assert.h>

static bool StackIsFull(Stack_t* stack);
static bool StackIsEmpty(Stack_t* stack);

void StackInit(Stack_t* stack, int* buffer, int size)
{
    assert(size > 0);

    stack->top = -1;
    stack->size = size;
    stack->buffer = buffer;
}

bool StackPush(Stack_t* stack, int value)
{
    if (StackIsFull(stack))
        return false;

    stack->top = stack->top + 1;
    stack->buffer[stack->top] = value;
    return true;
}

bool StackPop(Stack_t* stack, int* value)
{
    if (StackIsEmpty(stack))
        return false;

    *value = stack->buffer[stack->top];
    stack->top = stack->top - 1;
    return true;
}

static bool StackIsFull(Stack_t* stack)
{
    return (stack->top == stack->size) ? true : false;
}

static bool StackIsEmpty(Stack_t* stack)
{
    return (stack->top == -1) ? true : false;
}

