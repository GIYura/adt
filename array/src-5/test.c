/*
TEST

This test shows 2 main methods passing 2-D array in a function
1. Passing single pointer;
2. Passing pointer to an array.
*/

#define CUBE_X  3
#define CUBE_Y  3
#define CUBE_Z  3

#define SINGLE_POINTER      0
#define ARRAY_POINTER       0
#define SINGLE_LOOP         0
#define CUBE                1

#include <stdio.h>
#include "matrix.h"

int main(int argc, char* argv[])
{
    int matrix[ROW_MAX][COL_MAX] = { {1,2,3}, {4,5,6}, {7,8,9} };
    
#if SINGLE_POINTER
    PrintMatrix_SinglePointer(&matrix[0][0], ROW_MAX, COL_MAX);

#elif ARRAY_POINTER
    PrintMatrix_PointerToArray(matrix, ROW_MAX);

#elif SINGLE_LOOP
    PrintMatrix_SinglePointerSingleLoop(matrix, ROW_MAX);

#elif CUBE

    int cube[CUBE_X][CUBE_Y][CUBE_Z] = 
                        {
                            {{11,12,13}, {14,15,16}, {17,18,19}},
                            {{21,22,23}, {24,25,26}, {27,28,29}},
                            {{31,32,33}, {34,35,36}, {37,38,39}},
                        };

    PrintCube_SinglePointer(&cube[0][0][0], CUBE_X, CUBE_Y, CUBE_Z);

#endif

    return 0;
}

