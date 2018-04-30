/*
 * ADC16.c
 *
 * Created: 4/29/2018 12:14:35 PM
 *  Author: moham
 */ 

#include <avr/io.h>

void ADC_initialize(){
	
	//ADMUX
	//AVCC with external capacitor at AREF pin
	
	//Internal 2.56V Voltage Reference with external capacitor at AREF pin
	ADMUX |=  (1<<REFS0) | (1<<REFS1) | (1<<ADLAR);
	
	//Enable ADC
	ADCSRA |= (1 << ADEN);
	
	//  division factor is 128
	ADCSRA |=  (1 << ADPS0)  | (1 << ADPS1) | (1 << ADPS2);
}


void ADC_run(){
	// start conversion
	ADCSRA |= (1 << ADSC);
	
}

unsigned short ADC_read(){
	//ADCSRA |= 1 << ADSC;
	
	//wait till the conversion complete
	while ((ADCSRA & (1 << ADIF)) == 0)
		; //loop
	
	//PORTB = ADCL;
	//PORTC = ADCH;
	/*	
	ADC = (Vin * 1024) / Vref
	*/
	
	//ADIF is cleared by writing a logical one to the flag
	ADCSRA |= (1 << ADIF);
	return ADC;
}
