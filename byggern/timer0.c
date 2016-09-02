/*
 * timer0.c
 *
 * Created: 02.09.2016 18:51:36
 *  Author: fredrop
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer0.h"


typedef void (*t_func)();
static t_func function;
static int counter = 0;
 

void timer0_init(){
	TCCR0 = (1<<CS02) | (1<<CS00);	//selects clock source with /1024 prescaling
}

//TODO: calculate counter limit based on millis, prescaling and clock frequency
void timer0_execute_function_in_millis(t_func func, int millis){
	printf("Starting timer\n");
	TIMSK |= (1<<TOIE0);	//enables timer overflow interrupt
	function = func;
}



ISR(TIMER0_OVF_vect){
	counter += 1;
	if (counter % 100 == 0){
		printf("Overflow triggered: %d\n", counter);
		TIMSK &= ~(1<<TOIE0);	//disable overflow timer
		function();
	}
	TIFR |= (1<<TOV0);		//clears the interrupt flag, unsure if necessary
}