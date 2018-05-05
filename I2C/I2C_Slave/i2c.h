/*
 * i2c.h
 *
 * Created: 4/22/2018 11:00:23 PM
 *  Author: moham
 */ 


#ifndef I2C_H_
#define I2C_H_

#ifndef I2C_PRESCALE
#define I2C_PRESCALE 1 //1 4 16 64
#endif

#define I2C_MT_ARB_LOST   0x38
#define I2C_MR_ARB_LOST   0x38
#define I2C_START         0x08
#define I2C_REP_START     0x10
#define I2C_MT_SLA_ACK    0x18
#define I2C_MT_DATA_ACK   0x28
#define I2C_MR_DATA_NACK  0x58
#define I2C_MR_SLA_NACK   0x48
#define I2C_MT_SLA_NACK   0x20
#define I2C_MT_DATA_NACK  0x30
#define I2C_MR_DATA_ACK   0x50
#define I2C_MR_SLA_ACK    0x40




void I2C_init(unsigned long SCL_CLOCK);

void I2C_start();

void I2C_write(unsigned char cByte);

void I2C_stop();

void I2C_Slave_set_address(unsigned char address);

unsigned char I2C_read_ACK();

unsigned char I2C_read_NACK();

unsigned char I2C_Get_Status(void);


#endif /* I2C_H_ */