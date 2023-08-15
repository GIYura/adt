#ifndef BUFFER_H
#define BUFFER_H

/*
@brief: Init buffer with indexes
@in: size - buffer size
@out: int* - pointer to allocated memory
*/
int* BufferInit(int size);

/*
@brief: Print buffer content
@in: buffer - pointer to the buffer
@in: size - buffer size
@out: none
*/
void BufferPrint(const int* const buffer, int size);

#endif /* BUFFER_H */
