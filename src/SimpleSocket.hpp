#ifndef SIMPLESOCKET_HPP
#define SIMPLESOCKET_HPP

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdexcept>

namespace serv
{

class SimpleSocket
{
private:
    int sock;
    struct sockaddr_in address;
    int connection;

public:
    SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
    
    virtual int connect_to_network() = 0;

    int get_sock();
    int get_connection();
    struct sockaddr_in get_address();
};


}

#endif