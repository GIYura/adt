#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/*
Queue
*/
typedef struct
{
    int front;
    int rear;
    int* buffer;
    int capacity;
    int counter;
} Queue_t;

void QueueInit(Queue_t* q, int* buffer, int size);
bool QueueEnqueue(Queue_t* q, int data);
bool QueueDequeue(Queue_t* q, int* data);
int QueueCapacity(Queue_t* q);

#endif /* QUEUE_H */

