#include "Uart.h"



int USART_Transmit( char data, FILE* stream ){
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
	return 0;
}

int USART_Receive( FILE* stream ){
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get and return received data from buffer */
	return UDR0;
}

void USART_Init(unsigned int ubrr, float frq){
	ubrr = frq/16/ubrr-1;
	/*Set baud rate*/
	UBRR0H = (ubrr>>8);
	UBRR0L = ubrr;
	
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<URSEL0)|(1<<USBS0)|(3<<UCSZ00);
	fdevopen(USART_Transmit, USART_Receive);
}