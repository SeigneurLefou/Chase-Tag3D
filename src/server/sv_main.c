#include "server.h"

int main()
{
	int					socket_fd;
	int					client_fd;
	;

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
    char buf[1024];
    recv(client_fd, buf, 1024, 0);
    printf("Reçu : %s\n", buf);
    send(client_fd, "OK", 2, 0);
	close(client_fd);
	close(socket_fd);
}
