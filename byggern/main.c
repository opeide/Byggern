/*
 * Agurk.c
 *
 * Created: 30.08.2016 14:37:24
 *  Author: matsmm
 */ 
#define F_CPU 4915200

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Uart.h"
#include "StatusLed.h"
#include "timer0.h"



int main(void)
{
	status_led_init();
	USART_Init(BAUD, F_CPU);
	timer0_init();
	
	printf("*****STARTING PROGRAM*****\n");
	//Enable global interrupts
	sei();
	

	
	while(1)
    {		
		printf("LED status: %d\n", status_led_get_status());		
		timer0_execute_function_in_millis(status_led_on, 5000);
		_delay_ms(5000);
		printf("5 seconds passed\n");
		_delay_ms(1000);
		status_led_off();
		
    }
	return 0;
}

