/*
 * StatusLed.h
 *
 * Created: 02.09.2016 16:22:17
 *  Author: fredrop
 */ 


#ifndef StatusLed_H_
#define StatusLed_H_

#include <avr/io.h>
#include <avr/interrupt.h>


void status_led_init();
void status_led_on();
void status_led_off();
int status_led_get_status();
/*
int status_led_get_blink_activated();
void status_led_blink_once(int millis);
*/




#endif /* StatusLed_H_ */