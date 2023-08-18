#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/* Stack */
typedef struct
{
    int top;
    int* buffer;
    int size;
} Stack_t;

/* @brief   Init Stack
 * @param   stack: handle
 * @param   buffer: buffer to store data
 * @param   size: the size of the buffer
 * @return  none
 */
void StackInit(Stack_t* stack, int* buffer, int size);

/* @brief   Insert an item in the stack
 * @param   stack: handle
 * @param   value: to be stored
 * @return  true - stored successfully; false - otherwise
 */
bool StackPush(Stack_t* stack, int value);

/* @brief   Retrieve an item from the stack
 * @param   stack: handle
 * @param   value: retrieved
 * @return  true - retrieved successfully; false - otherwise
 */
bool StackPop(Stack_t* stack, int* value);

#endif /* STACK_H */

