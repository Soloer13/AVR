/*
 * led_blink.c
 *
 * Created: 2/21/2018 10:10:56 PM
 * Author : moham
 */ 

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	//DDRD |= 0b11100000;  //make last 3 PINs of PORTD output and the rest input
	DDRD = 0x0F;
	PORTD |= ~(1 <<5 | 1<<6 |1<<7);  //
    while (1) 
    {
		//PORTD = 1<<5 | 1<<6 | 1<<7;
		
		
		if (PIND &(1<<PD3)) //check if PIND0 is pressed
		{
			while (PIND &(1<<PD3))
			{
				_delay_ms(20);
			}
			PORTD ^= (1<<5 | 1<<6 | 1<<7);
			//_delay_ms(20);
			
		}
		
    }
}

