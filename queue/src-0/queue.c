#include "queue.h"
#include <assert.h>

static bool QueueIsEmpty(Queue_t* q);
static bool QueueIsFull(Queue_t* q);

void QueueInit(Queue_t* q, int* buffer, int capacity)
{
    assert(capacity);

    q->buffer = buffer;
    q->capacity = capacity;
    q->front = 0;
    q->rear = capacity - 1;
    q->counter = 0;
}

bool QueueEnqueue(Queue_t* q, int data)
{
    if (QueueIsFull(q))
        return false;
#if 0
    if (q->rear == q->capacity - 1)
        q->rear = -1;
#endif
    q->rear = (q->rear + 1) % q->capacity;
    q->buffer[q->rear] = data;
    ++q->counter;
    return true;
}

bool QueueDequeue(Queue_t* q, int* data)
{
    if (QueueIsEmpty(q))
        return false;

    *data = q->buffer[q->front];
#if 0    
    if (q->front == q->capacity)
        q->front = 0;
#endif

    q->front = (q->front + 1) % q->capacity;
    --q->counter;
    return true;
}

int QueueCapacity(Queue_t* q)
{
    return q->counter;
}

static bool QueueIsEmpty(Queue_t* q)
{
    return(q->counter == 0) ? true : false;
}

static bool QueueIsFull(Queue_t* q)
{
    return (q->counter == q->capacity) ? true : false;
}

