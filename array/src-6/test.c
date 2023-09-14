#include <stdio.h>

#define BUFFER_SIZE     3

static void PrintBuffer(const int* const buffer, const int buffSize);

/*
-----------------MAIN-------------------
*/
int main(int argc, char* argv[])
{
    int buffer[BUFFER_SIZE] = { 33, 22, 11 };
    int data[BUFFER_SIZE] = { 55, 66, 77 };

/* 
1. Address of the buffer is address of its fisrt element.
NOTE: output is the same.
*/
    printf("address of buffer: %p\n", buffer); 
    printf("address of &buffer: %p\n", &buffer); 
    printf("address of &buffer[0]: %p\n", &buffer[0]); 

/*
2. Pointer to an entire buffer.
NOTE: output is the same as step 1.
 */
    int (*pBuffer)[3] = &buffer;
    printf("address (*pBuffer)[3]: %p\n", pBuffer);

/*
3. Pointer to an array.
NOTE: pointer to an array is pointer to its first element.
*/
    int* pFirstElenemt = buffer;
    printf("address p: %p\n", pFirstElenemt);

/*
4. Pointer can be assigned to another buffer.
*/
    pFirstElenemt = data;
    printf("address p: %p\n", pFirstElenemt);

/*
5. Array name in not lvalue.
NOTE: array name can not be modified, it is not possible to assing
another array.
lvalue - known at compile time;
r-value - known at runtime.
*/
#if 0
    buffer = data; /* illigal */
#endif

/*
6. Array name is not the same as pointer.
NOTE: 
int buffer[]; - buffer is array of int
int* pBuffer: - pointer to an array of int.
*/
    printf("size of buffer: %ld in bytes\n", sizeof(buffer));
    printf("size of pointer: %ld in bytes\n", sizeof(pFirstElenemt));

/*
7. Iterate over array.
NOTE: address of the next array element:
(base address + 1 * sizeof type) = (0x1000 + 1 * 4) = 0x1004
(base address + 1 * number of elements in the buffer * size of type) = (0x1000 + 1 * 3 * 4) = 0x100C
*/
    printf("address buffer + 1: %p\n", buffer + 1);     /* address of the next element in buffer */
    printf("address &buffer + 1: %p\n", &buffer + 1);   /* address behind the whole buffer */
    printf("address pBuffer + 1: %p\n", pBuffer + 1);

/*
8. Acceess to the array element.
NOTE: 
*(buffer + 1) isn't the same as *buffer + 1

operation '++' isn't the same as '+ 1'.
'++'  - increment and assign (which is illgal, see point 5)
'+ 1' - increment address by 1.
*/
    printf("element [0]: %d\n", **pBuffer);        /* double asterisk provides access to the element over pointer to the whole array */
    printf("element behind buffer: %d\n", **(&buffer + 1));  /* NOTE: assess to the next element behind the whole buffer */

    /*  next 2 statement are equal */
    printf("element [1]: %d\n", buffer[1]);
    printf("element [1]: %d\n", *(buffer + 1));     /* increment address then dereference */
    
    printf("element [0]: %d\n", *buffer);
    printf("element [0] incremented by 1: %d\n", *buffer + 1); /* dereference first element then increment it */

/* NOTE: this is related to buffer name (base address only).
This is not valid to pointer to a buffer.
*/
#if 0
    printf("value %d\n", *buffer++);    /* illigal */
#else
    printf("%d\n", *pFirstElenemt++);   /* ligal  */
#endif

/*
9. Passing array to a function
NOTE: array decades to pointer.
*/
    int bufferSize = sizeof(buffer) / sizeof(buffer[0]);
    PrintBuffer(buffer, bufferSize);

/*
10. Print array using address.
NOTE: the following 'for' are equvivalent
*/
    printf("Buffer: ");
    for (int* pB = &buffer[0]; pB <= &buffer[BUFFER_SIZE - 1]; pB++)
    {
        printf("%d ", *pB);
    }
    
    printf("\nBuffer: ");
    for (int* pB = buffer; pB <= buffer + (BUFFER_SIZE - 1); pB++)
    {
            printf("%d ", *pB);
    }
    printf("\n");

/*
11. Array initialization
NOTE: array declared in main() function and has automatic class storage,
means that uninitialized array will be filled with data that already 
stored in memory.
*/
    int array1[5];
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");

/*
NOTE: if array partially initialized, compiler will fill the rest with '0'. 
*/
    int array2[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");

/*
NOTE: designated initalizer (C99).
Allow init specific element of an array (the rest is 0)
*/
    int array3[5] = {[2] = 222}; 
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array3[i]);
    }
    printf("\n");

/*
NOTE: array4 contains 5 elements (from index 0 - 4).
*/
    int array4[5] = {[1] = 111, [3] = 333, 444};
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array4[i]);
    }
    printf("\n");

/*
NOTE: even if array size if missed, compiler will allocate enough memory
to store all elements.
*/
    int array5[] = {[1] = 111, [3] = 333, 444};
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array5[i]);
    }
    printf("\n");
    printf("Number of elements in array: %ld\n", sizeof(array5) / sizeof(array5[0]));

    return 0;
}

static void PrintBuffer(const int* const buffer, const int buffSize)
{
    printf("Buffer: ");
    for (int i = 0; i < buffSize; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

