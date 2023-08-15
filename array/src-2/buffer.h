#ifndef BUFFER_H
#define BUFFER_H

/*
@brief: Init buffer with indexes
@in: buffer - pointer to the buffer
@in: size - buffer size
@out: none
*/
void BufferInit(int* const buffer, int const size);

/*
@brief: Print buffer content
@in: buffer - pointer to the buffer
@in: size - buffer size
@out: none
*/
void BufferPrint(const int* const buffer, int const size);

#endif /* BUFFER_H */
