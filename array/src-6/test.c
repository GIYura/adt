#include <stdio.h>

int main(int argc, char* argv[])
{
    int buffer[] = { 33, 22, 11 };
    int data[] = { 55, 66, 77 };

/*
NOTES:
1. Имя массива - это базовый адрес, который является адресом
первого элемента массива.

2. Имя массива нельзя присвоить другому массиву:
    buffer = data; // illigal;

3. Массив != указатель
    sizeof(buffer); // размер всего массива в байтах (3 * 4) = 12
    sizeof(p);      // размер указателя в байтах (8 байтов) 64 бит архитектура

4. buffer[i] эквивалентно *(buffer + i).

5. buffer + 1 - это следующий элемент в массиве.
Пример: предположим что базовый адрес массива = 0х1000 и 64-bit
тогда адрес следующего элемента вызичляется:
- 0х1000 + 1 * sizeof(element type) = 0x1000 + 1 * 4 = 0x1004.

6. Адрес массива совпадает с базовым адресом, а значит и с 
адресом первого элемента, но контекст разный.

- &buffer - это адрес всего массива, т.е. 
&buffer + 1 - это адрес следующего элемента за всем массивом.

Пример: предположим что базовый адрес массива = 0х1000 и массив 
содержит 3 элемента типа int, тогда &buffer + 1 будет равно:
- 0x1000 + 1 = 0x1000 + 3 * 4 = 0x100C

7. Операция взятия адреса & - это выход из коробки, 
операция разименования адреса * - это вход в коробку.


*/
    printf("address buffer: %p\n", buffer); 
    printf("address &buffer: %p\n", &buffer); 
    printf("address &buffer[0]: %p\n", &buffer[0]); 
    int (*pBuffer)[3] = &buffer;
    printf("address (*pBuffer)[3]: %p\n", pBuffer);
    int* p = buffer;
    printf("address p: %p\n", p);
    p = data;
    printf("address p: %p\n", p);

    printf("size of buffer: %ld in bytes\n", sizeof(buffer));
    printf("number of items in buffer: %ld\n", sizeof(buffer)/sizeof(buffer[0]));
    printf("size of pointer: %ld\n", sizeof(p));
    printf("size of int: %ld\n", sizeof(int));

    printf("address buffer + 1: %p\n", buffer + 1);
    printf("address &buffer + 1: %p\n", &buffer + 1);
    printf("address pBuffer + 1: %p\n", pBuffer + 1);

    printf("\n%d\n", **pBuffer);

#if 0
    printf("value *buffer: %d\n", *buffer);
    printf("value *buffer + 1: %d\n", *buffer + 1);
    printf("value *(buffer + 1): %d\n", *(buffer + 1));

    printf("%d\n", buffer[0]);
    printf("%d\n", buffer[1]);
    printf("%d\n\n", buffer[2]);

    
    printf("%d\n", *(buffer + 0));
    printf("%d\n", *(buffer + 1));
    printf("%d\n\n", *(buffer + 2));

    int* pB = buffer;

    printf("%d\n", *pB);
    printf("%d\n", *pB++);
    printf("%d\n\n", *pB++);
#endif

#if 0
    for (int i = 0; i < 3; i++)
    {
        printf("address buffer[%d]: %p\n", i, (buffer + i));
    }
    
    for (int* pB = &buffer[0]; pB <= &buffer[2]; pB++)
    {
        printf("%d ", *pB);
    }
    printf("\n");
#endif

    return 0;
}
