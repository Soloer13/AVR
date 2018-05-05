/*
 * USART.c
 *
 * Created: 4/9/2018 5:19:04 PM
 * Author : moham
 */ 

#define  F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "usart.h"

int main(void)
{
	
	/*
	UCSRB = (1<<RXEN) | (1<<TXEN);	//enable Reciver and Transmitter
	UCSRC = (1<<URSEL)|(1<<USBS)|(1<<UCSZ0) | (1<<UCSZ1); 	//mode3 use 8bit data & 2 bit stop
	UBRRL = 51;
	DDRB = 0xFF;
	DDRD = 0xFE;
	*/
	DDRD = 0xFE;
	DDRB = 0xFF;
	USART_Init(51);
    
	/* Replace with your application code */
    while (1) 
    {
		
		//Receive Data
		unsigned char received;
		received = USART_Receive();
		if(received == 0xFF)
		{
			PORTB ^= (1<<PB0);
			_delay_ms(200);
		}
		else
		{
			PORTB = (1<<PB0);	
		}
		
		//USART_Transmit(0xFF);
    }
}
