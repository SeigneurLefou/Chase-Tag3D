#include "client.hpp"

int main(int argc, char **argv)
{
	int					socket_fd;
	char				buffer[1024];
	char				user_message[1024];
	int					bytes_recv;
	struct sockaddr_in	addr;
	std::string			ip_str;

	if (argc > 1)
		ip_str = argv[1];
	else
		ip_str = "127.0.0.1";
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0)
	{
		perror(NULL);
		return (1);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(ip_str.c_str());
	if (connect(socket_fd, (struct sockaddr*)&addr, sizeof(addr)))
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
		std::cout << "Reçu :" << buffer << std::endl;
		bzero(buffer, 1024);
		bzero(user_message, 1024);
	}
	close(socket_fd);
}
