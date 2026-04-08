#include "server.h"

int main()
{
	int					socket_fd;
	int					client_fd;
	ssize_t				recv_size;
	char				buffer[1024];
	// struct sockaddr		*cl_address;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0)
	{
		perror(NULL);
		return (1);
	}
	struct sockaddr_in	addr = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = INADDR_ANY,
		.sin_port = htons(4269)
	};
	if (bind(socket_fd, (struct sockaddr*)&addr, sizeof(addr)))
	{
		perror(NULL);
		return (1);
	}
	listen(socket_fd, 3);
	client_fd = accept(socket_fd, NULL, NULL);
	while (1)
	{
		recv_size = recv(client_fd, buffer, 1024, 0);
		printf("recv size [%ld]\n", recv_size);
			perror("recv");
		printf("Reçu : %s\n", buffer);
		bzero(buffer, 1024);
		send(client_fd, "OK", 3, 0);
	}
	close(client_fd);
	close(socket_fd);
}
