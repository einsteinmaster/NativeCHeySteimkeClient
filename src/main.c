#include "App.h"

int main(void){
	app_data *app;
	app_initialize(&app);
	app_run(app);
	return 0;
}