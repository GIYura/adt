/*
TEST src-0

1. Create a queue;
2. Fill the queue with loop indexes;
3. Retrieve 1 item from the queue;
4. Put the same item multiplied by 10 to the queue;
5 Retrive all the items from the queue and print them.
*/
#include "queue.h"
#include <stdio.h>

#define QUEUE_SIZE 5

static Queue_t m_q;
static int m_queue[QUEUE_SIZE];

int main(int argc, char* argv[])
{
    QueueInit(&m_q, m_queue, QUEUE_SIZE);
    
    for (int i = 0; i < 10; i++)
    {
        if (!QueueEnqueue(&m_q, i + 1))
        {
            printf("Queue is full\n");
            break;
        }
    }
    printf("Queue capacity: %d\n", QueueCapacity(&m_q));
    printf("Queue: ");

    int value;
    QueueDequeue(&m_q, &value);

    value = value * 10;
    QueueEnqueue(&m_q, value);

    for (int i = 0; i < 10; i++)
    {
        int data;
        if (!QueueDequeue(&m_q, &data))
        {
            printf("\nQueue is empty\n");
            break;
        }
        printf("%d ", data);
    }
    printf("\n");

    return 0;
}

