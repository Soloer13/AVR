/*
 * interrupt16.c
 *
 * Created: 5/1/2018 1:28:07 AM
 * Author : moham
 */ 

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#ifndef SREG
	#define SREG *(volatile unsigned char*) 0x5F
#endif




void interrupt_init(void){
	
	SREG |= (1 << 7);
	
	//Any logical change on INT1 generates an interrupt request
	MCUCR |= (1 << ISC10);
	/* When the INT1 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external
	pin interrupt is enabled */
	GICR |= (1 << INT1);
}

ISR(INT1_vect){
		PORTA ^= 1<<PA5;
	}
int main(void)
{
    /* Replace with your application code */
	interrupt_init();
	DDRA = 0xFF;
    while (1) 
    {
		
		//PORTD = 1<<5 | 1<<6 | 1<<7;
		
    }
}



