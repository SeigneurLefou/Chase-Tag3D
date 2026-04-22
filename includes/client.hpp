#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "utils.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
# include "utils.hpp"

#define PORT 8080
#define BUFFER_SIZE 1024

class GameClient {
public:
    GameClient();
    ~GameClient();

    bool    connectToServer(const string ip);
    void    disconnect();
    bool    sendInput(const string message);
    int     receiveUpdate(char* buffer, size_t size);
	bool	is_connected();
    
private:
    int     _socket_fd;
    bool    _is_connected;
};

#endif
