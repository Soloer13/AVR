/*
 * uart_master.c
 *
 * Created: 5/2/2018 12:00:32 AM
 * Author : moham
 */ 

#include <avr/io.h>
#include "usart.h"

int main(void)
{
    /* Replace with your application code */
    DDRD = 0xFE;
	USART_Init(51);
    
	while (1) 
    {
		USART_Transmit(0xFA);
    }
}

