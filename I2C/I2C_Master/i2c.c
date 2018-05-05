/*
 * i2c.c
 *
 * Created: 4/22/2018 11:00:13 PM
 *  Author: moham
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/twi.h>
#include "i2c.h"

void I2C_init(unsigned long SCL_CLOCK){
	
	//set the I2C frequency
	TWBR = (unsigned char) (((F_CPU/SCL_CLOCK)-16)/(2* I2C_PRESCALE));
	
	if(I2C_PRESCALE == 1)
		TWSR =0;
	else if(I2C_PRESCALE ==4)
		TWSR =1;
	else if(I2C_PRESCALE ==16)
		TWSR =2;
	else if(I2C_PRESCALE ==64)
		TWSR =3;
	
	TWCR = (1<<TWEN);
}

		
void I2C_start(){
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	while( (TWCR & (1<<TWINT)) == 0)
		; //wait to finish	
}

void I2C_stop(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void I2C_Master_write(unsigned char cByte){
	TWDR = cByte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while((TWCR & (1<<TWINT))==0)
		; //wait to finish 
}


void I2C_Slave_set_address(unsigned char address){
	TWAR = address;	 
}

unsigned char I2C_read_ACK(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}

unsigned char I2C_read_NACK(){
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}


unsigned char I2C_Get_Status(void)
{
	unsigned char status;
	
	//mask status
	status = TWSR & 0xF8;
	return status;
}