#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <sstream>

#include <iostream>

#include "memoryoutputstream.h"

void serialize(MemoryOutputStream &stream, unsigned data)
{
    std::stringstream buf;
    buf << data;
    std::string bufString = buf.str();
    stream.write(bufString.c_str(), buf.str().length());
}

#endif // SERIALIZER_H
