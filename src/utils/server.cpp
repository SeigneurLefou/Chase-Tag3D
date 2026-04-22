#include "server.hpp"

GameServer::GameServer()
{
    _server_fd = -1;
    _is_running = false;
    memset(_client_fds, 0, sizeof(_client_fds));
}

GameServer::~GameServer()
{
    stop();
}

bool GameServer::init()
{
    struct sockaddr_in  addr;
    int                 opt = 1;

    _server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_server_fd < 0)
    {
        perror("socket");
        return (false);
    }

    setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(_server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        return (false);
    }

    if (listen(_server_fd, MAX_CLIENT) < 0)
    {
        perror("listen");
        return (false);
    }

    _is_running = true;
    return (true);
}

void GameServer::_handle_new_connection()
{
    struct sockaddr_in  client_addr;
    socklen_t           client_len = sizeof(client_addr);
    int                 new_client;

    new_client = accept(_server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (new_client < 0)
    {
        perror("accept");
        return;
    }

    for (int i = 0; i < MAX_CLIENT; i++)
    {
        if (_client_fds[i] == 0)
        {
            _client_fds[i] = new_client;
            cout << "Client connected : fd=" << new_client << endl;
            return;
        }
    }
    close(new_client);
}

void GameServer::_handle_client_data(int index)
{
    char    buffer[BUFFER_SIZE];
    int     sock = _client_fds[index];
    ssize_t n;

    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sock, buffer, BUFFER_SIZE - 1, 0);

    if (n <= 0)
    {
        if (n == 0)
            cout << "Client " << sock << " deconnected." << endl;
        else
            perror("recv");
        
        close(sock);
        _client_fds[index] = 0;
    }
    else
    {
        cout << "Receive from " << sock << " : " << buffer << endl;
        send(sock, "OK", 3, 0);
    }
}

void GameServer::run_network()
{
    fd_set  readfds;
    int     max_fd;

    while (_is_running)
    {
        FD_ZERO(&readfds);
        FD_SET(_server_fd, &readfds);
        max_fd = _server_fd;

        for (int i = 0; i < MAX_CLIENT; i++)
        {
            if (_client_fds[i] > 0)
            {
                FD_SET(_client_fds[i], &readfds);
                if (_client_fds[i] > max_fd)
                    max_fd = _client_fds[i];
            }
        }

        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) < 0)
        {
            perror("select");
            break;
        }

        if (FD_ISSET(_server_fd, &readfds))
        {
            _handle_new_connection();
        }

        for (int i = 0; i < MAX_CLIENT; i++)
        {
            if (_client_fds[i] > 0 && FD_ISSET(_client_fds[i], &readfds))
            {
                _handle_client_data(i);
            }
        }
    }
}

void GameServer::stop()
{
    _is_running = false;
    if (_server_fd != -1)
    {
        close(_server_fd);
        _server_fd = -1;
    }
    for (int i = 0; i < MAX_CLIENT; i++)
    {
        if (_client_fds[i] > 0)
        {
            close(_client_fds[i]);
            _client_fds[i] = 0;
        }
    }
}
