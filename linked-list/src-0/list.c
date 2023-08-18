#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void NodePrint(Node_t* head)
{
    Node_t* node = head;
    while (node != NULL)
    {
        printf("Node value: %d\r\n", node->value);
        node = node->next;
    }
}

void NodeInsertFrontWrong(Node_t* head, int value)
{
    Node_t* node = malloc(sizeof(Node_t));
    node->value = value;
    node->next = head;
    head = node;
}

void NodeInsertFront(Node_t** head, int value)
{
    Node_t* node = malloc(sizeof(Node_t));
    node->value = value;

    node->next = *head;
    *head = node;
}

void NodeInsertBack(Node_t* head, int value)
{
    Node_t* node = malloc(sizeof(Node_t));
    node->value = value;
    node->next = NULL;

    /* Best practice to use local variable. */
    Node_t* temp = head;

    /* find the last item in the list. 
    Last means, its 'next' points to NULL
    */
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

bool NodeSearch(Node_t* head, int value)
{
    Node_t* node = head;
    bool ret = false;

    while (node != NULL)
    {
        if (node->value == value)
        {
            ret = true;
            break;
        }
        node = node->next;
    }
    return ret;
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

int NodeCount(Node_t* head)
{
    int counter = 0;
    Node_t* node = head;
    while (node != NULL)
    {
        ++counter;
        node = node->next;
    }
    return counter;
}

