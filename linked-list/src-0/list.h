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

/* @brief   Create a node
 * @param   value: default value of the node
 * @return  pointer to memory allocated for a node
 */
Node_t* NodeCreate(int value);

/* @brief   Delete a node
 * @param   node: to be deleted
 * @return  none
 */
void NodeDelete(Node_t* node);

/* @brief   Print the whole list starting at head
 * @param   head: pointer to the beginning of the list
 * @return  none
 */
void NodePrint(Node_t* head);

/* @brief   Insert an item in the list
 * @param   head: address of the head
 * @param   value: to be stored
 * @return  none
 */
void NodeInsertBack(Node_t* head, int value);

/* @brief   Insert an item in the list
 * @param   head: address of the head
 * @param   value: to be stored
 * @return  none
 */
void NodeInsertFront(Node_t** head, int value);

/*
* @brief: This function is wrong.
* It passes pointer to the head, in this way it is not
* possible to modify caller memory, in fact just local
* copy of the node.
* Golden rule:
* To modify caller memory, pass a pointer to that memory.
*/
void NodeInsertFrontWrong(Node_t* head, int value);

/* @brief   Search an item in the list
 * @param   head: start of the list
 * @param   value: key value
 * @return  true - found, false - otherwise
 */
bool NodeSearch(Node_t* head, int value);

/* @brief   Count number of items in the list
 * @param   head: address of the head
 * @return  count: stored number
 */
int NodeCount(Node_t* head);

#endif /* LINKED_LIST_H */

