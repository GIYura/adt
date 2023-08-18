/*
TEST src-0

1. Create 2 lists:
    1.1 m_list1 is a pointer to list 1
    1.2 m_list2 is a pointer to list 2

2. Fill list with loop indexes in 2 ways:
    2.1 Keep head at the end of the list;
    2.2 Keep head at the beginning of the list.

3. Print list content
*/
#include "list.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    Node_t* m_list1 = NodeCreate(1);
    Node_t* m_list2 = NodeCreate(1);

    for (int i = 2; i <= 5; i++)
    {
        /* head at the end */
        NodePutBack(&m_list1, i);
    
        /* head at the beginning */
        NodePutFront(&m_list2, i);
    }
    printf("Head at the end:\n");
    NodePrint(m_list1);
    
    printf("Head at the beginning:\n");
    NodePrint(m_list2);

    return 0;
}
