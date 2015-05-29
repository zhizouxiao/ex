
#ifndef _SOCKET_H
#define _SOCKET_H

#include <pthread.h>

typedef struct st_dev_info{
	int	link_num;
	pthread_t	tid;
	struct sockaddr_in	client;
	socklen_t	length;
	struct st_dev_info *prior;
	struct st_dev_info *next;
}st_dev_info;
#endif

