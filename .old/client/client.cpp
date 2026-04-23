#include "client.hpp"

GameClient::GameClient() : _socket_fd(-1), _is_connected(false) {}

GameClient::~GameClient()
{
    disconnect();
}

bool	GameClient::connectToServer(const string ip)
{
    struct sockaddr_in	addr;

    _socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket_fd < 0) {
        perror("socket");
        return false;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(ip.c_str());

    if (connect(_socket_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(_socket_fd);
        return false;
    }

    _is_connected = true;
    return true;
}

void	GameClient::disconnect()
{
    if (_is_connected)
	{
        close(_socket_fd);
        _is_connected = false;
    }
}

bool	GameClient::is_connected()
{
	return (_is_connected);
}

bool GameClient::sendInput(const string message)
{
    if (send(_socket_fd, message.c_str(), message.length() + 1, 0) < 0)
	{
        perror("send");
        return false;
    }
    return true;
}

int	GameClient::receiveUpdate(char* buffer, size_t size)
{
    memset(buffer, 0, size);
    int bytes = recv(_socket_fd, buffer, size - 1, 0);
    if (bytes <= 0 && _is_connected)
        perror("recv");
    return bytes;
}
