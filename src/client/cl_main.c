#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = { .sin_family = AF_INET, .sin_port = htons(4269), .sin_addr.s_addr = inet_addr("127.0.0.1") };
    connect(sock, (void*)&addr, sizeof(addr));
    send(sock, "Ping", 4, 0);
    char buf[1024];
    recv(sock, buf, 1024, 0);
    printf("Reçu : %s\n", buf);
    close(sock);
}
