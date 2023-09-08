#ifndef MATRIX_H
#define MATRIX_H

#define ROW_MAX 3
#define COL_MAX 3

/*
@brief: Print matrix
@in: matrix - pointer to matrix (to the first element of the matrix)
@in: row - number of rows in the matrix
@in: col - number of columns in the matrix
@out: none
*/
void PrintMatrix_SinglePointer(const int* matrix, int row, int col);

/*
@brief: Print matrix
@in: matrix - pointer to 1-D array of the matrix
@in: row - number of rows in the matrix
@out: none
*/
void PrintMatrix_PointerToArray(const int (*matrix)[COL_MAX], int row);

/*
@brief: Print matrix
@in: matrix - pointer to 1-D array of the matrix
@in: row - number of rows in the matrix
@out: none
*/
void PrintMatrix_PointerToArraySingleLoop(const int (*matrix)[COL_MAX], int row);

/*
NOTE: works in case x == y == z.
@brief: Print 3-D array
@in: cube - pointer to a single element of 3-D array
@in: x - represents the number of 2-D arrays
@in: y - represents the number of rows in single 2-D array
@in: z - represents the number of colomns in single 2-D array
@out: none
*/
void PrintCube_SinglePointer(const int* cube, int x, int y, int z);

#endif /* MATRIX_H */

