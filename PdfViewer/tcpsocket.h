#ifndef TCPSOCKET_H
#define TCPSOCKET_H


#ifdef _WIN32
#include <WinSock2.h>
#else
#include <unistd.h>
#endif

#include <string>
#include <thread>

#include "types.h"
#include "sockaddress.h"
#include "memoryinputstream.h"
#include "memoryoutputstream.h"

class TcpSocket
{
private:
    socktype m_sock;

    bool m_inError = false;

    std::string m_errorMsg;

public:
    TcpSocket(const SockAddress &remote);

    TcpSocket(socktype sock);

    ~TcpSocket();

    bool inError() const;

    const std::string &errorMsg() const;

    int sendData(const MemoryOutputStream &stream);

    int receiveData(MemoryOutputStream &stream);
};

#endif // TCPSOCKET_H
