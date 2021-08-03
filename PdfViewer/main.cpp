
#include <string>
#include <iostream>

#include "sockaddress.h"
#include "tcpsocket.h"
#include "memoryinputstream.h"
#include "memoryoutputstream.h"

#include "serializer.h"

int main()
{
    SockAddress address("192.168.1.100", 8080);
    TcpSocket client(address);
    MemoryOutputStream memOut;
    serialize(memOut, 59);
    client.sendData(memOut);
    return 0;
}
