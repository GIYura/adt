#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void NodePrint(Node_t* node)
{
    while (node != NULL)
    {
        printf("Node value: %d\r\n", node->value);
        node = node->next;
    }
}

void NodePutBack(Node_t** head, int value)
{
    Node_t* node = malloc(sizeof(Node_t));
    node->value = value;

    node->next = *head;
    *head = node;
}

void NodePutFront(Node_t** head, int value)
{
    Node_t* node = malloc(sizeof(Node_t));
    node->value = value;
    node->next = NULL;

    Node_t* temp = *head;
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = node;
}

void NodeSearch(Node_t* head, int* value)
{
/* TODO: */
}

Node_t* NodeCreate(int value)
{
    Node_t* node = malloc(sizeof(Node_t));

    if (node != NULL) 
    {
        node->value = value;
        node->next = NULL;
    }

    return node;
}

void NodeDelete(Node_t* node)
{
/* TODO: */
}

