/*
TEST src-0

1. Create 2 lists:
    1.1 m_list1 is a pointer to list 1
    1.2 m_list2 is a pointer to list 2

2. Fill list with loop indexes in 2 ways:
    2.1 Keep head at the end of the list;
    2.2 Keep head at the beginning of the list.

3. Print list content

4. Wrong put. Demo how wrong put works
*/
#include "list.h"
#include <stdio.h>

static Node_t* m_list1;
static Node_t* m_list2;
static Node_t* m_list3;

int main(int argc, char* argv[])
{
    m_list1 = NodeCreate(1);
    m_list2 = NodeCreate(1);
    m_list3 = NodeCreate(1);

    for (int i = 2; i <= 5; i++)
    {
        /* head at the end */
        NodeInsertFront(&m_list1, i);
    
        /* head at the beginning */
        NodeInsertBack(&m_list2, i);
    }
    printf("Head at the end.\n");
    printf("List capacity: %d\n", NodeCount(m_list1));
    NodePrint(m_list1);
    
    printf("Head at the beginning:\n");
    printf("List capacity: %d\n", NodeCount(m_list2));
    NodePrint(m_list2);

    printf("Wrong Put: 10, 20, 30\n");
    printf("List capacity: %d\n", NodeCount(m_list3));
    NodeInsertFrontWrong(m_list3, 10);
    NodeInsertFrontWrong(m_list3, 20);
    NodeInsertFrontWrong(m_list3, 30);

    NodePrint(m_list3);
    
    int value = 10;
    printf("Search value %d in list1\n", value);
    if (NodeSearch(m_list1, value))
    {
        printf("Value %d found in list1\n", value);
    }
    else
    {
        printf("Value %d NOT found in list1\n", value);
    }

    return 0;
}
