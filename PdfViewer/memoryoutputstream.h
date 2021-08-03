#ifndef MEMORYOUTPUTSTREAM_H
#define MEMORYOUTPUTSTREAM_H

class MemoryOutputStream
{
private:
    char *m_buffer;

    unsigned m_head;

    unsigned m_capacity;

    void reallocate(int newLength);

public:
    MemoryOutputStream();

    ~MemoryOutputStream();

    const char *getBufferPtr() const;

    int getLength() const;

    void write(const void *data, unsigned byteCount);

    void write(int data);

    void write(unsigned data);
};

#endif // MEMORYOUTPUTSTREAM_H
