#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/* Queue */
typedef struct
{
    int front;
    int rear;
    int* buffer;
    int capacity;
    int counter;
} Queue_t;

/* @brief   Init Queue
 * @param   q: handle
 * @param   buffer: buffer to store data
 * @param   size: the size of the buffer
 * @return  none
 */
void QueueInit(Queue_t* q, int* buffer, int size);

/* @brief   Put an item in the queue
 * @param   q: handle
 * @param   data: stored
 * @return  true - put successfully; false - otherwise
 */
bool QueueEnqueue(Queue_t* q, int data);

/* @brief   Retrieve an item from the queue
 * @param   stack: handle
 * @param   data: retrieved
 * @return  true - retrieved successfully; false - otherwise
 */
bool QueueDequeue(Queue_t* q, int* data);

/* @brief   Return capacity of the queue
 * @param   q: handle
 * @return  int: q capacity
 */
int QueueCapacity(Queue_t* q);

#endif /* QUEUE_H */

