#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>

/*
Node struct
*/
typedef struct node
{
    int value;
    struct node* next;
} Node_t;

Node_t* NodeCreate(int value);
void NodeDelete(Node_t* node);
void NodePrint(Node_t* head);
void NodePutFront(Node_t** head, int value);
void NodePutBack(Node_t** head, int value);
void NodeSearch(Node_t* head, int* value);

#endif /* LINKED_LIST_H */

