#include "client.h"

int main()
{
	int		socket_fd;
	char	buffer[1024];
	char	user_message[1024];
	int		bytes_recv;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0)
	{
		perror(NULL);
		return (1);
	}
	struct sockaddr_in	addr = {
		.sin_family = AF_INET,
		.sin_port = htons(PORT),
		.sin_addr.s_addr = inet_addr("127.0.0.1") };
	if (connect(socket_fd, (void*)&addr, sizeof(addr)))
	{
		perror("connect");
		close(socket_fd);
		return (1);
	}
	bzero(buffer, 1024);
	bzero(user_message, 1024);
	while (1)
	{
		fgets(user_message, 1024, stdin);
		if (send(socket_fd, user_message, strlen(user_message) + 1, 0) < 0)
		{
			perror("send");
			break;
		}
		bytes_recv = recv(socket_fd, buffer, 1023, 0);
		if (bytes_recv <= 0)
		{
			perror("recv");
			break;
		}
		printf("Reçu : %s\n", buffer);
		bzero(buffer, 1024);
		bzero(user_message, 1024);
	}
	close(socket_fd);
}
