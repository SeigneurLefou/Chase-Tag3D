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
#include "player.hpp"

class Server
{
public:
	Server();
	~Server();

	bool	init();
	void	run_network(unordered_map<int, Player> &players, mutex &p_mutex);
	void	stop();

private:
	int		_server_fd;
	int		_client_fds[MAX_CLIENT];
	bool	_is_running;

	void	_handle_new_connection(unordered_map<int, Player> &players, mutex &p_mutex);
	void	_handle_client_data(int index, unordered_map<int, Player> &players, mutex &p_mutex);
};

#endif
