/*
TEST src-2
*/
#include "buffer.h"

#define BUFFER_SIZE 15

static int m_buffer[BUFFER_SIZE];

int main(int argc, char* argv[])
{
    int buffSize = sizeof(m_buffer) / sizeof(m_buffer[0]);

    /* fille buffer with loop indexes */
    BufferInit(m_buffer, buffSize);

    /* print buffer content */
    BufferPrint(m_buffer, buffSize);

    return 0;
}
