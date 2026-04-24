#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include "utils.hpp"

class GameServer
{
public:
	GameServer();
	~GameServer();

	bool	init();
	void	run_network();
	void	stop();

private:
	int		_server_fd;
	int		_client_fds[MAX_CLIENT];
	bool	_is_running;

	void	_handle_new_connection();
	void	_handle_client_data(int index);
};
#endif
