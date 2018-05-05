/*
 * usart.c
 *
 * Created: 4/10/2018 6:32:11 AM
 *  Author: moham
 */ 

#include "usart.h"

//USART Initialization
void USART_Init( unsigned int baud )
{
	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL) | (1<<USBS) | (1<<UCSZ0) | (1<<UCSZ1);
}

//Flushing the Receive Buffer
unsigned char USART_Flush( void )
{
	unsigned char dummy=0;
	while ( UCSRA & (1<<RXC) )
	{
		dummy = UDR;
	}
	
	return dummy;
}


/* ======================USART_8BIT ====================== */

#ifdef USART_8BIT
//Data Transmission
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
		;  //looping until transmission complete
		
	/* Put data into buffer, sends the data */
	UDR = data;
}
//Receiving Frames
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
		;  //looping until receive complete
		
	/* Get and return received data from buffer */
	return UDR;
}
#endif



/* ======================USART_9BIT ====================== */
#ifdef USART_9BIT
//Data Transmission for 9 bits
void USART_Transmit( unsigned int data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) ) 
	;
	
	/* Copy 9th bit to TXB8 */
	UCSRB &= ~(1<<TXB8);
	if ( data & 0x0100 )
	UCSRB |= (1<<TXB8);
	
	/* Put data into buffer, sends the data */
	UDR = data;
}

PE

//Receiving Frames with 9 Data bits
unsigned int USART_Receive( void )
{
	unsigned char status, resh, resl;
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get status and 9th bit, then data */
	/* from buffer */
	status = UCSRA;
	resh = UCSRB;
	resl = UDR;
	/* If error, return -1 */
	if ( status & (1<<FE)|(1<<DOR)|(1<<PE) )
	return -1;
	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;
	return ((resh << 8) | resl);
}

#endif

