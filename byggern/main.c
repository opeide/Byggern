/*
 * Agurk.c
 *
 * Created: 30.08.2016 14:37:24
 *  Author: matsmm
 */ 
#define F_CPU 4915200

#include "Uart.h"
#include <util/delay.h>

int main(void)
{
	DDRA = 0x1;
	
	PORTA |= (1 << PA0);
	_delay_ms(1000);
	PORTA &= ~(1 << PA0);
	USART_Init(BAUD,F_CPU);
	//unsigned char inn = USART_Receive(NULL);
	int b=10;
    while(1)
    {
		
		printf("160 %d. ", b);
		_delay_ms(1000);
        //TODO:: Please write your application code 
    }
}