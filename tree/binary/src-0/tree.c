#include "tree.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

static void InOrder(Tree_t* root);
static void PreOrder(Tree_t* root);
static void PostOrder(Tree_t* root);

void NodeTraversal(Tree_t* root, TRAVERSAL_ORDER order)
{
    switch(order)
    {
        case IN_ORDER:
            InOrder(root);
            printf("\n");
        break;

        case PRE_ORDER:
            PreOrder(root);
            printf("\n");
        break;

        case POST_ORDER:
            PostOrder(root);
            printf("\n");
        break;

        default: 
            assert(0);
            break;
    }
}

static void InOrder(Tree_t* root)
{
    if (root == NULL) 
        return;
    InOrder(root->left);
    printf("%d ->", root->data);
    InOrder(root->right);
}

static void PreOrder(Tree_t* root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

static void PostOrder(Tree_t* root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ->", root->data);
}

Tree_t* NodeCreate(int data)
{
    Tree_t* node = malloc(sizeof(Tree_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Tree_t* NodeInsertRight(Tree_t* root, int data)
{
    root->left = NodeCreate(data);
    return root->left;
}

Tree_t* NodeInsertLeft(Tree_t* root, int data)
{
    root->right = NodeCreate(data);
    return root->right;
}

