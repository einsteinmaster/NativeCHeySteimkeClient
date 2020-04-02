#ifndef _APP_H_
#define _APP_H_
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct
{
	int sockfd;
	struct hostent *hostent;
	struct sockaddr_in adress;
} app_data;

int app_initialize(app_data **data);
int app_run(app_data *data);

#endif