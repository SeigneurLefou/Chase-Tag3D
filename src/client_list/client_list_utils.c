#include "client_list.h"

t_client_node	*new_client_node(int fd, struct sockaddr socket_addr, socklen_t socket_len)
{
	t_client_node	*client_node;

	client_node = malloc(sizeof(t_client_node);
	client_node->fd = fd;
	client_node->socket_addr = socket_addr;
	client_node->socket_len = socket_len;
	client_node->previous = NULL;
	client_node->next = NULL;
	return (client_node);
}

bool	push_client(t_client_node *cl_list, t_client_node *new)
{
	t_client_node *cpy_cl_list;

	cpy_cl_list = cl_list;
	while (cpy_cl_list->next)
		cpy_cl_list = cpy_cl_list->next;
	new->prev = cpy_cl_list;
	cpy_cl_list->next = new;
	return (0);
}

bool	shift_client(t_client_node *cl_list, t_client_node *new)
{
	t_client_node *cpy_cl_list;

	cpy_cl_list = cl_list;
	while (cpy_cl_list->prev)
		cpy_cl_list = cpy_cl_list->prev;
	new->next = cpy_cl_list;
	cpy_cl_list->prev = new;
	return (0);
}

bool	shift_client(t_client_node *cl_list, t_client_node *new)
{
	t_client_node *cpy_cl_list;

	cpy_cl_list = cl_list;
	while (cpy_cl_list->prev)
		cpy_cl_list = cpy_cl_list->prev;
	new->next = cpy_cl_list;
	cpy_cl_list->prev = new;
	return (0);
}
