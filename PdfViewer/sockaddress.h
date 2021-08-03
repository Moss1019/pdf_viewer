#ifndef SOCKADDRESS_H
#define SOCKADDRESS_H


#ifdef _WIN32
#include <WinSock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#endif

#include <string>

class SockAddress
{
private:
    sockaddr m_addr;

public:
    SockAddress(){}

    SockAddress(const std::string &ipAddress, unsigned short port);

    SockAddress(const sockaddr &remote);

    SockAddress(const SockAddress &other);

    const sockaddr *constAddress() const;

    unsigned addressLen() const;

    const std::string ipAddress();
};

#endif // SOCKADDRESS_H
