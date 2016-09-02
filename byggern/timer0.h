/*
 * timer0.h
 *
 * Created: 02.09.2016 18:51:07
 *  Author: fredrop
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include <util/delay.h>

void timer0_init();
void timer0_execute_function_in_millis(void (*func)(), int millis);



#endif /* TIMER0_H_ */