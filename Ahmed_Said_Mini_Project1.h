/*
 * Ahmed_Said_Mini_Project1.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Ahmed Said
 */

#ifndef AHMED_SAID_MINI_PROJECT1_H_
#define AHMED_SAID_MINI_PROJECT1_H_
enum{
	OFF, ON
};
typedef enum{
	False, True
}bool;
struct vehicleStates{
	char engineState;
	char AC_state;
	int speed;
	float roomTemperature;
	char engineControllerState;
	float engineTemperature;
};
void open_handler(void);
void sensor_handler(void);
void traffic_light_handler(void);
void room_temperature_handler(void);
void engine_temperature_handler();
void display(void);

#endif /* AHMED_SAID_MINI_PROJECT1_H_ */
