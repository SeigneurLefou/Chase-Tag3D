#include "client.hpp"

Client::Client()
{
	_socket_fd = -1;
	_is_connected = false;

	memset(key_table, 0, SDL_SCANCODE_COUNT * sizeof(bool));
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("SDL_Init : %s", SDL_GetError());
		return ;
	}
	window = SDL_CreateWindow(
		"Window", 100, 100, 0
	);
	if (!window)
	{
		SDL_Log("SDL_CreateWindow : %s", SDL_GetError());
		return ;
	}
	renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer)
	{
		SDL_Log("SDL_CreateRenderer : %s", SDL_GetError());
		return ;
	}
}

Client::~Client()
{
	disconnect();
}

bool	Client::connectToServer(const string ip)
{
	struct sockaddr_in	addr;

	_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_socket_fd < 0)
	{
		perror("socket");
		return (FAILURE);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(ip.c_str());

	if (connect(_socket_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
	{
		perror("connect");
		close(_socket_fd);
		return (FAILURE);
	}

	_is_connected = true;
	return (SUCCESS);
}

void	Client::disconnect()
{
	if (_is_connected)
	{
		close(_socket_fd);
		_is_connected = false;
	}
}

bool	Client::is_connected()
{
	return (_is_connected);
}

bool Client::sendInput()
{
	char	user_input[BUFFER_SIZE];

	memcpy(user_input, key_table, SDL_SCANCODE_COUNT * sizeof(bool));
	if (send(_socket_fd, user_input, SDL_SCANCODE_COUNT * sizeof(bool), 0) < 0)
	{
		perror("send");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	Client::receiveUpdate(char* buffer, size_t size)
{
	memset(buffer, 0, size);
	int bytes = recv(_socket_fd, buffer, size - 1, 0);
	if (bytes <= 0 && _is_connected)
		perror("recv");
	return bytes;
}

int	Client::key_hook()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
            _is_connected = false;
		if (event.type == SDL_EVENT_KEY_DOWN)
			key_table[event.key.scancode] = true;
		if (event.type == SDL_EVENT_KEY_UP)
			key_table[event.key.scancode] = false;
	}
	return (0);
}
