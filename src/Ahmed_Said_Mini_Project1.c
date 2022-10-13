/*
 * Ahmed_Said_Mini_Project1.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Ahmed Said
 */
#include<stdio.h>
#include"Ahmed_Said_Mini_Project1.h"
#define WITH_ENGINE_TEMP_CONTROLLER 0
struct vehicleStates *ptr;
void open_handler(void)
{
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	char c;
	scanf(" %c", &c);
	switch(c){
	case'A':
	case'a':
		sensor_handler();
		break;
	case'B':
	case'b':
		printf("Turn off the vehicle engine\n\n");
		open_handler();
		break;
	case'C':
	case'c':
		printf("Quit the system\n");
		break;
	}
}
void sensor_handler(void)
{
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
#if WITH_ENGINE_TEMP_CONTROLLER == 1
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
#endif
	char c;
	scanf(" %c", &c);
	switch(c){
	case'A':
	case'a':
		open_handler();
		break;
	case'B':
	case'b':
		traffic_light_handler();
		display();
		sensor_handler();
		break;
	case'C':
	case'c':
		room_temperature_handler();
		display();
		sensor_handler();
		break;
#if WITH_ENGINE_TEMP_CONTROLLER == 1
	case'D':
	case'd':
		engine_temperature_handler();
		display();
		sensor_handler();
		break;
#endif
	}
}
void traffic_light_handler(void)
{
	printf("Enter the required color:\n");
	char color;
	scanf(" %c", &color);
	if((color == 'G') || (color == 'g'))
	{
		ptr->speed = 100;
	}
	else if((color == 'O') || (color == 'o'))
	{
		ptr->speed = 30;
	}
	else if((color == 'R') || (color == 'r'))
	{
		ptr->speed = 0;
	}
}
void room_temperature_handler(void)
{
	printf("Enter the required room temperature\n");
	float temp;
	scanf(" %f", &temp);
	if((temp < 10) || (temp > 30))
	{
		ptr->AC_state = ON;
		ptr->roomTemperature = 20;
	}
	else
	{
		ptr->AC_state = OFF;
	}
}
#if WITH_ENGINE_TEMP_CONTROLLER == 1
void engine_temperature_handler()
{
	printf("Enter the required engine temperature:\n");
	float temp;
	scanf(" %f", &temp);
	if((temp < 100) || (temp > 150))
	{
		ptr->engineControllerState = ON;
		ptr->engineTemperature = 125;
	}
	else
	{
		ptr->engineControllerState = OFF;
	}
}
#endif
void display(void)
{
	if(ptr->speed == 30)
	{
		ptr->AC_state = ON;
		ptr->roomTemperature = (ptr->roomTemperature*((float)5/4)) + 1;
#if WITH_ENGINE_TEMP_CONTROLLER == 1
		ptr->engineControllerState = ON;
		ptr->engineTemperature = (ptr->engineTemperature*((float)5/4)) + 1;
#endif
	}
	if(ptr->engineState == 0)
	{
		printf("Engine is OFF\n");
	}
	else
	{
		printf("Engine is ON\n");
	}
	if(ptr->AC_state == 0)
	{
		printf("AC is OFF\n");
	}
	else
	{
		printf("AC is ON\n");
	}

	printf("vehicle speed: %d km/Hr\n", ptr->speed);
	printf("Room Temperature: %f C\n", ptr->roomTemperature);
#if WITH_ENGINE_TEMP_CONTROLLER == 1
	if(ptr->engineControllerState == 0)
	{
		printf("Engine Temperature Controller is OFF\n");
	}
	else
	{
		printf("Engine Temperature Controller is ON\n");
	}
	printf("Engine Temperature: %f C\n\n", ptr->engineTemperature);
#endif
}
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct vehicleStates v = {1, 0, 120, 30, 0, 150};
	ptr = &v;
	open_handler();
	return 0;
}

