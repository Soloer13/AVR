/*
 * spi.h
 *
 * Created: 3/31/2018 5:37:58 PM
 *  Author: moham
 */ 


#ifndef SPI_H_
#define SPI_H_
 
#define SS     4      // Slave Select is Bit No.4
#define MOSI   5      // Master Out Slave In is Bit No.5
#define MISO   6      // Master In Slave Out is Bit No.6
#define SCK    7     // Shift Clock is Bit No.7

#define DDR_SPI DDRB
#define DD_MOSI MOSI
#define DD_SCK 	SCK
#define DD_MISO MISO


void SPI_MasterInit(void);
void SPI_MasterTransmit(unsigned char cData);
void SPI_SlaveInit(void);
char SPI_SlaveReceive(void);


#endif /* SPI_H_ */