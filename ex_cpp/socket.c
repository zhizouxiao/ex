
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#include "./socket.h"

void *dev_pthread( void *p ){
	st_dev_info *dev_info_p = p;

	while( 1 ){
		ssize_t length;
		char buffer[100];
		fd_set rfd;
		struct timeval timeout;

		FD_ZERO( &rfd );

		timeout.tv_sec = 300;
		timeout.tv_usec = 0;

		FD_SET( dev_info_p -> link_num, &rfd );
		int select_value = select( dev_info_p -> link_num + 1, &rfd, 0, 0, NULL );
		if( select_value == 0 ){
		//if( !select( dev_info_p -> link_num + 1, &rfd, 0, 0, &timeout ) ){
			printf( "timeout close link\n" );
			close( dev_info_p -> link_num );
			dev_info_p -> next -> prior = dev_info_p -> prior;
			dev_info_p -> prior -> next = dev_info_p -> next;
			free( dev_info_p );
			pthread_exit( NULL );
		}
		printf( "select value %d erron %d\n", select_value, errno );
		if( FD_ISSET( dev_info_p -> link_num, &rfd ) ){
			bzero( buffer, sizeof( buffer ) );
			length = recv( dev_info_p -> link_num, buffer, sizeof( buffer ), 0 );
			if( length < 0 ){
				printf( "server recv data failed %d\n", errno );
			}
			else if( !length ){
				printf( "client unlink addr %s, port %d\n", inet_ntoa( dev_info_p -> client.sin_addr ), dev_info_p -> client.sin_port );
				close( dev_info_p -> link_num );
				dev_info_p -> next -> prior = dev_info_p -> prior;
				dev_info_p -> prior -> next = dev_info_p -> next;
				free( dev_info_p );
				pthread_exit( NULL );
			}
			else{
				printf( "server recv data is : %s\n", buffer );
				if( send( dev_info_p -> link_num, buffer, length, 0 ) < 0 ){
					printf( "server send failed\n" );
				}
			}
		}
	}
}

int main( int argc, char **argv ){
	st_dev_info	*head_dev_info, *end_dev_info, *dev_info_p;

	struct sockaddr_in server_addr;
	bzero( &server_addr, sizeof(server_addr ) );
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htons( INADDR_ANY );
	server_addr.sin_port = htons( 8080 );

	head_dev_info = ( st_dev_info * )malloc( sizeof( st_dev_info ) );
	end_dev_info = ( st_dev_info * )malloc( sizeof( st_dev_info ) );
	end_dev_info -> prior = head_dev_info;
	end_dev_info -> next = head_dev_info;
	head_dev_info -> prior = end_dev_info;
	head_dev_info -> next = end_dev_info;
	

//	if( pthread_create( &dev_info_p -> tid, NULL, recycle_pthread, ( void * )dev_info_p ) ){//recycle timeout pthread
//		printf( "create recycle pthread error\n" );
//		return -1;
//	}

	int server_socket = socket( PF_INET, SOCK_STREAM, 0 );
	if( server_socket < 0 ){
		printf( "socket creat failed!\n" );
	}
	else{
		int opt = 1;
		setsockopt( server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof( opt ) );
	}
	if( bind( server_socket, ( struct sockaddr * )&server_addr, sizeof( server_addr ) ) ){
		printf( "sever bind port: %d failed\n", 8080 );
		exit( 1 );
	}

	if( listen( server_socket, 20 ) ){
		printf( "server listen failed\n" );
		exit( 1 );
	}

	while( 1 ){
		dev_info_p = ( st_dev_info * )malloc( sizeof( st_dev_info ) );
		if( !dev_info_p ){
			printf( "malloc error\n" );
			exit( 1 );
		}
		dev_info_p -> next = head_dev_info -> next;
		dev_info_p -> prior = head_dev_info;
		head_dev_info -> next -> prior = dev_info_p;
		head_dev_info -> next = dev_info_p;
		dev_info_p -> length = sizeof( dev_info_p -> client );
		dev_info_p -> link_num = accept( server_socket, ( struct sockaddr * )&dev_info_p -> client, &dev_info_p -> length );

		if( dev_info_p -> link_num < 0 ){
			printf( "server accept data failed\n" );
			exit( 1 );
		}
		else{
			printf( "client link addr %s, port %d\n", inet_ntoa( dev_info_p -> client.sin_addr ), dev_info_p -> client.sin_port );
			if( pthread_create( &dev_info_p -> tid, NULL, dev_pthread, ( void * )dev_info_p ) ){
				printf( "Create thread error\n" );
				return -1;
			}
			dev_info_p = head_dev_info;
			int i;
			for( i = 0; dev_info_p -> next != end_dev_info; i ++ ){
				dev_info_p = dev_info_p -> next;
			}
			printf( "link count %d\n", i );
		}
	}
}
