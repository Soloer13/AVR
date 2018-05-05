/*
 * spi.c
 *
 * Created: 3/31/2018 5:39:20 PM
 *  Author: mohamed
 */
#include <avr/io.h>
#include "spi.h" 

void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	DDR_SPI = (1<<DD_MOSI) | (1<<DD_SCK) | (1<<SS);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_MasterTransmit(unsigned char cData)
{
	PORTB &= ~(1<<SS);
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
		;
	PORTB |= (1<<SS);
}


void SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	DDR_SPI = (1<<DD_MISO);
	/* Enable SPI */
	SPCR = (1<<SPE);
}
char SPI_SlaveReceive(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return data register */
	return SPDR;
}