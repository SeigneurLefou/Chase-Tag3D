#ifndef CLIENT_LIST_H
# define CLIENT_LIST_H

# include <stdio.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <string.h>

typedef struct s_client_node
{
	int						fd;
	struct sockaddr			socket_addr;
	socklen_t				socket_len;
	struct s_client_list	*prev;
	struct s_client_list	*next;
}			t_client_node;

#endif
