#include "client.h"

int main(int argc, char **argv)
{
    int		sock;
    char	buffer[1024];
	char	*user_message;

	if (argc > 0)
		user_message = argv[1];
	else
		user_message = "nothing...";
	sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in	addr = { .sin_family = AF_INET, .sin_port = htons(4269), .sin_addr.s_addr = inet_addr("127.0.0.1") };
    connect(sock, (void*)&addr, sizeof(addr));
    send(sock, user_message, strlen(user_message) + 1, 0);
    recv(sock, buffer, 1024, 0);
    printf("Reçu : %s\n", buffer);
    close(sock);
}
