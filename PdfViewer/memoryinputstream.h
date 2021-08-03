#ifndef MEMORYINPUTSTREAM_H
#define MEMORYINPUTSTREAM_H

class MemoryInputStream
{
private:
    char *m_buffer;

    unsigned m_head;

    unsigned m_capacity;

public:
    MemoryInputStream(char *buffer, int byteCount);

    MemoryInputStream(const char *buffer, int byteCount);

    ~MemoryInputStream();

    unsigned getRemainingSize() const;

    void read(void *data, unsigned byteCount);

    void read(int &data);

    void read(unsigned &data);
};


#endif // MEMORYINPUTSTREAM_H
