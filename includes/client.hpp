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

class Client {
public:
	Client();
	~Client();

	SDL_Window		*window;
	SDL_Renderer	*renderer;
	bool			key_table[SDL_SCANCODE_COUNT];
	bool			connectToServer(const string ip);
	void			disconnect();
	bool			sendInput();
	int				receiveUpdate(char* buffer, size_t size);
	bool			is_connected();
	int				key_hook();
	
private:
	int				_socket_fd;
	bool			_is_connected;
};

#endif
