/*
 * timer0.c
 *
 * Created: 02.09.2016 18:51:36
 * Author: fredrop
 * Driver for the 8 bit timer0 
 * TODO: queue several functions and decrement their respective target overflows, execute at 0
 *
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer0.h"


typedef void (*t_func)();
static t_func delayed_function;

static int overflow_counter = 0;
static float overflow_time = 425.0 / 128.0;	//1000 * (F_CPU / (prescale * timer_maxval))^-1 
static int target_overflows = 0; 

void timer0_init(){
	TCCR0 = (1<<CS01) | (1<<CS00);	//selects clock source with /64 prescaling
}

//Delays function execution without halting
void timer0_execute_function_in_millis(t_func func, int millis){	
	delayed_function = func;
	target_overflows = (int) ((float) millis / overflow_time);
	overflow_counter = 0;
	TIMSK |= (1<<TOIE0);			//enable timer overflow interrupt
}


//Timer0 overflow interrupt service routine
ISR(TIMER0_OVF_vect){
	overflow_counter += 1;
	if (overflow_counter >= target_overflows){
		TIMSK &= ~(1<<TOIE0);	//disable overflow timer
		printf("Overflow counter reached, executing function\n");
		delayed_function();
	}
	TIFR |= (1<<TOV0);		//clears the interrupt flag, unsure if necessary
}