/*
 * DIO.h
 *
 * Created: 6/5/2018 4:27:08 PM
 *  Author: moham
 */ 


#ifndef DIO_H_

#define DIO_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>


#define SET_BIT(PORT,PIN) (PORT |= (1<<PIN)  /*set bit */
#define CLEAR_BIT(PORT,PIN) (PORT &= ~(1<<PIN)) /*clear bit */
#define CHECK_SET(PINX,PIN) (PINX &(1<<PIN) ==1)  /*check if bit is set */
#define CHECK_CLEAR(PINX,PIN) (PINX &(1<<PIN) ==0) /*check if bit is clear */
#define TOGGLE_BIT(PORTX,PIN) (PORTX ^= (1<<PIN)) /*toggle bit */
#define BIT_SHIIFT(b) ( 1 << n )  /*shift bit */

#endif /* DIO_H_ */
