#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>
#include <stdbool.h>

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
void NodeInsertBack(Node_t** head, int value);
void NodeInsertFront(Node_t** head, int value);

/*
* @brief: This function is wrong.
*/
void NodeInsertFrontWrong(Node_t* head, int value);

bool NodeSearch(Node_t* head, int value);
int NodeCount(Node_t* head);

#endif /* LINKED_LIST_H */

