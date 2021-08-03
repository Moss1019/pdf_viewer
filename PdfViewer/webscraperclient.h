#ifndef WEBSCRAPERCLIENT_H
#define WEBSCRAPERCLIENT_H

#include "tcpsocket.h"

class WebScraperClient
{
private:
    TcpSocket *socket = nullptr;
public:
    WebScraperClient();

    ~WebScraperClient();


};

#endif // WEBSCRAPERCLIENT_H
