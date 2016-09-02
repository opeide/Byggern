#include <avr/io.h>
#include <stdio.h>
#define F_CPU 4915200
#define BAUD 9600

void USART_Init(unsigned int ubrr, float frq);
int USART_Receive( FILE* stream );
int USART_Transmit( char data, FILE* stream );