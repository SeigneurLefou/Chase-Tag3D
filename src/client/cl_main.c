#include "client.h"

int main(int argc, char **argv)
{
    int		socket_fd;
	int		i;
    char	buffer[1024];
	char	*user_message;
	int		bytes_recv;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0)
	{
		perror(NULL);
		return (1);
	}
    struct sockaddr_in	addr = {
		.sin_family = AF_INET,
		.sin_port = htons(4269),
		.sin_addr.s_addr = inet_addr("127.0.0.1") };
	if (connect(socket_fd, (void*)&addr, sizeof(addr)))
	{
		perror("connect");
		close(socket_fd);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (argv[i])
			user_message = argv[i];
		else
			user_message = "nothing...";
		send(socket_fd, user_message, strlen(user_message) + 1, 0);
		bytes_recv = recv(socket_fd, buffer, 1024, 0);
		if (bytes_recv <= 0)
		{
			perror("recv");
			break;
		}
		printf("Reçu : %s\n", buffer);
		i++;
	}
    close(socket_fd);
}
