
#define F_CPU 8000000UL

#include <avr/io.h>
#include "i2c.h"
#include <util/delay.h>


int main (){
	
	
	unsigned char ch=0;
	unsigned char i2c_current_status;
	DDRA = 0xFF; // PORTA is output
	I2C_Slave_set_address(0b11010000); // enable slave at address
	// 01101000 and do not accept general call
	
	

	ch = I2C_read_ACK();	// send ACK when master connects
		
	i2c_current_status = I2C_Get_Status(); // own SLA+W(0) has been transmitted and ACK has been returned   receive byte and send ACK
		
	if(i2c_current_status != 0x60){
		return 0;
	}
		
	ch = I2C_read_ACK();
		
	i2c_current_status = I2C_Get_Status();
		
	if(i2c_current_status != 0x80){
		return 0;
	}
	
	while(1){
		if(ch == 0xFF){
			PORTA ^= (1<<PB0);
			_delay_ms(200);
		}
	}
	
	return 0 ;
}
