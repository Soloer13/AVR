/*
 * SPI.c
 *
 * Created: 3/31/2018 5:00:42 PM
 * Author : moham
 */ 
#define  F_CPU   8000000UL

#include <avr/io.h>
#include "spi.h"


int main(void)
{
	SPI_MasterInit();

	SPI_MasterTransmit(0xFF);

    /* Replace with your application code */
    while (1) 
    {	
    }
}

