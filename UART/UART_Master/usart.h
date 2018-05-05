/*
 * usart.h
 *
 * Created: 4/10/2018 6:32:47 AM
 *  Author: moham
 */ 


#ifndef USART_H_
#define USART_H_

#include <avr/io.h>



//use 8bits Data
#define USART_8BIT

//use 9bits Data
//#define USART_9BIT


//USART Initialization
void USART_Init( unsigned int baud );

//Data Transmission
void USART_Transmit( unsigned char data );

//Receiving Frames
unsigned char USART_Receive( void );




#endif /* USART_H_ */