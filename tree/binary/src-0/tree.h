#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef enum
{
    IN_ORDER = 0,
    PRE_ORDER,
    POST_ORDER,
    TRAVERSAL_ORDER_COUNT
} TRAVERSAL_ORDER;

typedef struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
} Tree_t;

void NodeTraversal(Tree_t* root, TRAVERSAL_ORDER order);
Tree_t* NodeCreate(int data);
Tree_t* NodeInsertRight(Tree_t* root, int data);
Tree_t* NodeInsertLeft(Tree_t* root, int data);

#endif /* BINARY_TREE_H */

