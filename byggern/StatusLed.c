/*
 * Led.c
 *
 * Created: 02.09.2016 16:32:08
 *  Author: fredrop
 */ 
#include "StatusLed.h"
#include <avr/io.h>
#include <avr/interrupt.h>

static int status = 0;
//static int blink_activated = 0;

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
int status_led_get_blink_activated(){
	return blink_activated;
}

void status_led_blink_once(int millis){
	blink_activated = 1;
}
*/