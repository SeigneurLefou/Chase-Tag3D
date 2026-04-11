#include "server.h"

int main()
{
	int					server_fd, client_fds[MAX_CLIENT], new_client;
	int					max_fd;
	ssize_t				recv_size;
	char				buffer[BUFFER_SIZE];
	fd_set				readfds;
	int					sock;
	struct sockaddr_in	client_addr;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
	{
		perror(NULL);
		return (1);
	}
	struct sockaddr_in	addr = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = INADDR_ANY,
		.sin_port = htons(PORT)
	};
	if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)))
	{
		perror("bind");
		return (1);
	}
	if (listen(server_fd, MAX_CLIENT) < 0)
	{
		perror("listen");
		return (1);
	}
	memset(buffer, 0, BUFFER_SIZE);
	memset(client_fds, 0, MAX_CLIENT * sizeof(int));
	while (1)
	{
		FD_ZERO(&readfds);
		FD_SET(server_fd, &readfds);
		max_fd = server_fd;
		for (int i = 0; i < MAX_CLIENT; i++)
		{
			if (client_fds[i] > 0)
			{
				FD_SET(client_fds[i], &readfds);
				if (client_fds[i] > max_fd)
					max_fd = client_fds[i];
			}
		}
		if (select(max_fd + 1, &readfds, NULL, NULL, NULL) < 0)
		{
			perror("select");
			exit(1);
		}
		if (FD_ISSET(server_fd, &readfds))
		{
			socklen_t client_len = sizeof(client_addr);
			new_client = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
			if (new_client < 0)
			{
				perror("accept");
				continue;
			}
			for (int i = 0; i < MAX_CLIENT; i++)
			{
				if (client_fds[i] == 0)
				{
					client_fds[i] = new_client;
					printf("Nouveau client connecté (fd=%d, IP=%s, Port=%d)\n",
						   new_client,
						   inet_ntoa(client_addr.sin_addr),
						   ntohs(client_addr.sin_port));
					break;
				}
			}
		}
		for (int i = 0; i < MAX_CLIENT; i++)
		{
			sock = client_fds[i];
			if (sock > 0 && FD_ISSET(sock, &readfds)) {
				bzero(buffer, BUFFER_SIZE - 1);
				recv_size = recv(sock, buffer, BUFFER_SIZE - 1, 0);
				if (recv_size <= 0)
				{
					if (recv_size == 0)
						printf("Client %d déconnecté.\n", sock);
					else
						perror("recv");
					close(sock);
					client_fds[i] = 0;
				}
				else
				{
					printf("Reçu de %d : %s", sock, buffer);
					if (send(sock, "OK", 3, 0) < 0)
					{
						perror("send");
						close(sock);
						client_fds[i] = 0;
					}
				}
			}
		}
	}
	close(server_fd);
	for (int i = 0; i < MAX_CLIENT; i++)
		if (client_fds[i] > 0)
			close(client_fds[i]);
}
