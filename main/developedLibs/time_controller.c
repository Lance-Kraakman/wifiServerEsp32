#include "time_controller.h"
#include <time.h>

//could create a linked list of controller_states ?
typedef struct controller_states {
	uint8_t pin_number;
	uint8_t state;
	struct tm time_data;
} controller_states;

static controller_states controllerStateDataStruct;


void createState(uint8_t pin, uint8_t state, uint8_t day, uint8_t month, uint8_t year, uint8_t hour, uint8_t minute) {

	controllerStateDataStruct.time_data.tm_year = year;
	controllerStateDataStruct.time_data.tm_mon = month;
	controllerStateDataStruct.time_data.tm_mday = day;
	controllerStateDataStruct.time_data.tm_hour = hour;
	controllerStateDataStruct.time_data.tm_min = minute;
	controllerStateDataStruct.pin_number = pin;
	controllerStateDataStruct.state = state;

}

void setupControllerPin() {

}

void executeState() {

}










