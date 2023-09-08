#include <stdio.h>
#include "matrix.h"

void PrintMatrix_SinglePointer(const int* matrix, int row, int col)
{
    printf("Single Pointer\n");

    const int* pAddr;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
#if 0
            pAddr = (matrix + i * col) + j;
            printf("%d ", *pAddr);
#else
            printf("%d ", *((matrix + i * col) + j));
#endif
        }
        printf("\n");
    }
    printf("\n");
}

void PrintMatrix_PointerToArray(const int (*matrix)[COL_MAX], int row)
{
    printf("Pointer to array\n");

    const int* pAddr;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < COL_MAX; j++)
        {
#if 1
            pAddr = *(matrix + i) + j;
            printf("%d ", *pAddr);
#else
            printf("%d ", *(*(matrix + i) + j));
#endif
        }   
        printf("\n");
    }
    printf("\n");
}

void PrintMatrix_PointerToArraySingleLoop(const int (*matrix)[COL_MAX], int row)
{
    printf("Single Loop\n");
    const int* p;

    for (p = &matrix[0][0]; p < &matrix[COL_MAX - 1][row - 1]; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");
}

void PrintCube_SinglePointer(const int* cube, int x, int y, int z)
{
    printf("3-D array\n");
    
    const int* addr;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                addr = ((cube + i * x * y) + j * z) + k;
                printf("%d ", *addr);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");    
}

