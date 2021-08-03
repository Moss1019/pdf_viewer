#include "memoryinputstream.h"

#include <memory>
#include <cstring>

#include <iostream>

MemoryInputStream::MemoryInputStream(char *buffer, int byteCount)
    :m_head(0), m_capacity(byteCount)
{
    m_buffer = reinterpret_cast<char *>(std::malloc(byteCount));
    std::memcpy(m_buffer, buffer, byteCount);
}

MemoryInputStream::MemoryInputStream(const char *buffer, int byteCount)
    : m_head(0), m_capacity(byteCount)
{
    m_buffer = reinterpret_cast<char *>(std::malloc(byteCount));
    std::memcpy(m_buffer, buffer, byteCount);
}

MemoryInputStream::~MemoryInputStream()
{
    if (m_buffer != nullptr)
    {
        std::free(m_buffer);
        m_buffer = nullptr;
    }
}

unsigned MemoryInputStream::getRemainingSize() const
{
    return m_capacity - m_head;
}

void MemoryInputStream::read(void *data, unsigned byteCount)
{
    std::memcpy(data, m_buffer + m_head, byteCount);
    m_head += byteCount;
}

void MemoryInputStream::read(int &data)
{
    read(&data, sizeof(int));
}

void MemoryInputStream::read(unsigned &data)
{
    read(&data, sizeof(unsigned));
}
