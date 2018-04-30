/*
 * LCD.c
 *
 * Created: 4/29/2018 12:14:20 PM
 *  Author: moham
 */ 


#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>


void LCD_cmd(unsigned char cmd){
	LCD_DATA = cmd;
	CTRL = (0<<RS) | (1<<E);
	_delay_ms(2);
	CTRL = (0<<RS) | (0<<E);
	_delay_ms(2);
}

void LCD_Address(unsigned char line, unsigned char position){
	if(line==0)
	{
		if (position < 16 && position >=0)
		LCD_cmd(0x80+position);
	}
	else if (line==1)
	{
		if (position < 16 && position >=0)
		LCD_cmd(0xc0 + position);
	}
}

void LCD_initialization(void){
	CTRL_DDR = 0x03;
	LCD_DDR = 0xFF;
	LCD_DATA = 0x00;
	CTRL = 0x00;
	
	LCD_cmd(Entry_Mode_4);
	_delay_ms(1);
	LCD_cmd(Clear_DISPLAY);
	_delay_ms(1);
	//LCD_cmd(Entry_Mode_8);
	//_delay_ms(1);
	LCD_cmd(CURSOR_POS_0_0);
	_delay_ms(1);
	LCD_cmd(CURSOR_BLINK);
	_delay_ms(1);
	//LCD_cmd(DDRAM44);
	_delay_ms(1);
}

void LCD_write(unsigned char data){
	#ifdef Entry_Mode_8
	LCD_DATA = data;
	CTRL = (1<<RS) | (1<<E);
	_delay_ms(2);
	CTRL = (1<<RS) | (0<<E);
	_delay_ms(2);
	#endif
	
	#ifdef Entry_Mode_4
	//unsigned char data1 =data;
	
	LCD_DATA = 0x00;
	//LCD_DATA = (LCD_DATA & 0x0F) | (data & 0xF0);
	LCD_DATA = data  ;
	CTRL = (1<<RS) | (1<<E);
	_delay_ms(2);
	CTRL = (1<<RS) | (0<<E);
	_delay_ms(2);
	LCD_DATA = 0x00;
	//LCD_DATA = (LCD_DATA & 0x0F) | (data << 4);
	LCD_DATA = data << 4 ;
	CTRL = (1<<RS) | (1<<E);
	_delay_ms(2);
	CTRL = (1<<RS) | (0<<E);
	_delay_ms(2);
	#endif
}

void LCD_DisplayString(char *Str)
{
	unsigned char i;
	while(*Str !='\0')
	{
		LCD_write(*Str);//<<<
		Str++;
		i++;
		if (i ==5)
			break;
	}
}

void LCD_ClearScreen(void)
{
	LCD_write(0x01); //Clear Display (also clear DDRAM content)	0x01
}


void Int_TO_String(int data)
{
	char buff[16];
	itoa(data,buff,16);
	LCD_DisplayString(buff);
}
