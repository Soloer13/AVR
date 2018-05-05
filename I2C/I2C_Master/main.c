
#define F_CPU 8000000UL

#include <avr/io.h>
#include "i2c.h"


int main(void){
	//I2C initialization with 100KHz
	I2C_init(0x48);
	
	unsigned char i2c_current_status;
	
	//while(1){
		//send start bit
		I2C_start();
		
		//check current status
		i2c_current_status = I2C_Get_Status();
		if( i2c_current_status != 0x08 ){
			return 0;
		}
		I2C_Master_write(0b11010000+0);
		i2c_current_status = I2C_Get_Status();
		if( i2c_current_status != 0x18 ){
			return 0;
		}
		I2C_Master_write(0xFF);
		i2c_current_status = I2C_Get_Status();
		if( i2c_current_status != 0x28 ){
			return 0;
		}
		
		I2C_stop();
	//}
}