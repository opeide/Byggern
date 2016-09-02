/*
 * Agurk.c
 *
 * Created: 30.08.2016 14:37:24
 *  Author: matsmm
 */ 
#define F_CPU 4915200

#include <avr/io.h>
#include <util/delay.h>
#include "Uart.h"
#include "StatusLed.h"




int main(void)
{
	status_led_init();
	USART_Init(BAUD, F_CPU);
	
	while(1)
    {
		status_led_on();
		printf("LED status: %d\n", status_led_get_status());
		_delay_ms(1000);
		status_led_off();
		printf("LED status: %d\n", status_led_get_status());
		_delay_ms(1000);
    }
	return 0;
}