/*
TEST src-0
*/
#include "tree.h"
#include <stdio.h>

static Tree_t* m_tree;

int main(int argc, char* argv[])
{
    m_tree = NodeCreate(10);
    NodeInsertLeft(m_tree, 20);
    NodeInsertRight(m_tree, 30);
    
    printf("Tree in order: ");
    NodeTraversal(m_tree, IN_ORDER);
    printf("\nTree pre order: ");
    NodeTraversal(m_tree, PRE_ORDER);
    printf("\nTree post order: ");
    NodeTraversal(m_tree, POST_ORDER);

    return 0;
}
