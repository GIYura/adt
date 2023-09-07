#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define BUFFER_SIZE 100

/* define a struct with buffer inside */
typedef struct
{
    char data[BUFFER_SIZE];
} Buffer_t;

/*
NOTE: NEVER DO THIS
@brief: Return address of the local variable
@in: none
@out: char* - address of the local buffer
*/
char* LocalBuffer(void);

/*
@brief: Return pre-defined string
@in: none
@out: char* - address of the string
*/
char* StringLiteral(void);

/*
@brief: Modify global buffer
@in: none
@out: char* - address of the global buffer
*/
char* GlobalBuffer(void);

/*
@brief: Return statically allocated buffer
@in: none
@out: char* - address of statically allocated buffer
*/
char* StaticBuffer(void);

/*
NOTE: this can lead to memory leak, because
the function allocates memory and the caller 
should free it, but this is not guarantee.

@brief: Return dynamically allocated buffer
@in: none
@out: char* - address of dynamically allocated buffer
*/
char* DynamicBuffer(void);

/*
NOTE: this is the best solution.
@brief: Modify dynamically allocated by the caller buffer
@in: buffer - dynamically allocated by the caller buffer
@in: size - size of the buffer
@out: none
*/
void ModifyDynamicBuffer(char* buffer, int bufferSize);

/*
@brief: Modify wrapped in the struct buffer
@in: buffer - pointer to the struct
@in: size - size of the buffer
@out: none
*/
void ModifyWrappedBuffer(Buffer_t* buffer, int bufferSize);

/*
@brief: Return wrapped in the struct buffer
@in: size - size of the buffer
@out: Buffer_t createed object
*/
Buffer_t WrappedBuffer(int bufferSize);

#endif /* FUNCTIONS_H */

