#include "App.h"

int app_initialize(app_data **data)
{
	printf("Initialize app\n");
	*data = (app_data *)malloc(sizeof(app_data));

	(*data)->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if ((*data)->sockfd < 0)
		return -1;

	(*data)->hostent = gethostbyname("rkp.intecelektro.de");

	memset(&((*data)->adress), 0, sizeof((*data)->adress));
	(*data)->adress.sin_family = AF_INET;
	//(*data)->adress.sin_addr.s_addr = inet_addr((*data)->hostent->h_addr_list[0]);
	(*data)->adress.sin_addr.s_addr = inet_addr("10.250.0.10");
	(*data)->adress.sin_port = htons(30000);

	if (connect((*data)->sockfd, (struct sockaddr*)&(*data)->adress, sizeof((*data)->adress)) < 0)
		printf("ERROR connecting\n");

	const char get_request_msg[] = "GET /api/user/10 HTTP/1.1\r\n\r\n";
	write((*data)->sockfd,get_request_msg,strlen(get_request_msg));

	char content[1000];
	memset(content,0,sizeof(content));

	read((*data)->sockfd,content,sizeof(content));

	close((*data)->sockfd);

	content[sizeof(content)-1] = 0;
	printf(content);
	printf("\n");

	return 0;
}
int app_run(app_data *data)
{
	printf("Run app\n");
	return 0;
}