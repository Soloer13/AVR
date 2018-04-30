/*
 * ADC.h
 *
 * Created: 4/29/2018 12:15:07 PM
 *  Author: moham
 */ 


#ifndef ADC_H_
#define ADC_H_



#include <avr/io.h>


void ADC_initialize();
void ADC_run();
unsigned short ADC_read();




#endif /* ADC_H_ */
