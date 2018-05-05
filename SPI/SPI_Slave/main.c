/*
 * spi_slave.c
 *
 * Created: 5/2/2018 6:56:31 PM
 * Author : moham
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"

int main(void)
{
    /* Replace with your application code */
	SPI_SlaveInit();
	DDRD = 0x01;
	DDRA = 0x00;
	unsigned char variable = SPI_SlaveReceive();
    while (1) 
    {
		//unsigned char variable = SPI_SlaveReceive();
		if (variable == 0xFF){
			PORTD ^= (1<<PD0);
			_delay_ms(20);
		}
		else{
			PORTD = (1<<PD0);
		}
		

    }
}

