/*
 * LCD.h
 *
 * Created: 4/29/2018 12:15:33 PM
 *  Author: moham
 */ 


#ifndef LCD_H_
#define LCD_H_


#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>


//Low for command..... High for data
#define RS					0  //Register Select (RS) connected to pin 5

//Low for write to register ... High for read from register
//#define RW  6  //Read/Write (RW) connected to pin 6

//send High to low pulse to read from PORTx
#define E					1  //Enable (E) connected to pin 7

#define LCD_DDR				DDRC
#define CTRL_DDR			DDRD
#define LCD_DATA			PORTC  //make LCD_DATA
#define CTRL				PORTD	//make ctrl
#define Clear_DISPLAY		0x01 //LCD_clear
#define Return_Home			0x02
#define Entry_Mode_incr		0x06 //increment (I/D = 1) the address counter after subsequent DD RAM read or write operations.
#define Entry_Mode_decr		0x04 //decrement (I/D = 0) the address counter after subsequent DD RAM read or write operations

//	#define Entry_Mode_8  0x0E  //LCD_Entry mode change to 8bit
#define Entry_Mode_4		0x28  //Function Set: 4-bit, 2 Line, 5x7 Dots
#define CURSOR_ON			0x0E  //LCD_CURSOR ON
#define CURSOR_POS_0_0		0x80 //LCD_POSITION ---0 is for 0th position
#define CURSOR_BLINK		0x0F   //LCD_BLINK DISPLAY ON, CURSOR blink
#define CURSOR_POS_1_0		0xC0 //LCD_POSITION ---1 is for 0th position
#define DDRAM44				0x44




/*
Function Set: 8-bit, 1 Line, 5x7 Dots		0x30
Function Set: 8-bit, 2 Line, 5x7 Dots		0x38
Function Set: 4-bit, 1 Line, 5x7 Dots		0x20
Function Set: 4-bit, 2 Line, 5x7 Dots		0x28
Entry Mode									0x06
Display off Cursor off(clearing display without clearing DDRAM content)	0x08
Display on Cursor on						0x0E
Display on Cursor off						0x0C
Display on Cursor blinking					0x0F
Shift entire display left					0x18
Shift entire display right					0x1C
Move cursor left by one character			0x10
Move cursor right by one character			0x14
Clear Display (also clear DDRAM content)	0x01

*/

void LCD_initialization(void);
void LCD_cmd(unsigned char cmd);
void LCD_write(unsigned char data);
void LCD_Address(unsigned char line,unsigned char position);
void LCD_ClearScreen(void);
void LCD_DisplayString(char *Str);
//void Int_TO_String(int data);


#endif /* LCD_H_ */
