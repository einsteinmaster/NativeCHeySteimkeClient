#ifndef _APP_H_
#define _APP_H_

typedef struct{
	int code;
} app_data;

int app_initialize(app_data **data);
int app_run(app_data *data);

#endif