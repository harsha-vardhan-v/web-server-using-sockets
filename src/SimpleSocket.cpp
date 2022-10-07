#include "SimpleSocket.hpp"


//Default constructor
serv::SimpleSocket::SimpleSocket (int domain, int service, int protocol, int port, u_long interface)
{
    // Define address struct
    address.sin_family = domain;
    address.sin_port = htons(port);     //Converts the bytes of port to be compatible with the network
    address.sin_addr.s_addr = htonl(interface);

    // Create the socket file descriptor  
    if ((sock = socket(domain, service, protocol)) == -1) {
        throw std::invalid_argument("Invalid arguments for socket");
    }

    // Bind the socket to network / connect to a server
    try {
        connection = connect_to_network();
    } catch (std::exception_ptr *eptr) {
        throw;
    }
}


//Getter functions
int serv::SimpleSocket::get_sock ()
{
    return sock;
}

int serv::SimpleSocket::get_connection ()
{
    return connection;
}

struct sockaddr_in serv::SimpleSocket::get_address ()
{
    return address;
}