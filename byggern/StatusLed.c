/*
 * Led.c
 *
 * Created: 02.09.2016 16:32:08
 *  Author: fredrop
 */ 
#include "StatusLed.h"


static int status = 0;

void status_led_init(){
	DDRA |= (1<<DDA0);		//defines port A pin 0 as output 
}

void status_led_on(){
	PORTA |= (1<<PA0);
	status = 1;
}

void status_led_off(){
	PORTA &= ~(1<<PA0);
	status = 0;
}

int status_led_get_status(){
	return status;
}

/*

void status_led_blink_once(int millis){
	//use timer to delay status_led_off by millis
}
*/