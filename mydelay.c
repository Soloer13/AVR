
void mydelay()
{
	/* initial value for the timer */
	TCNT0 = 0x00;
	/* corresponding interrupt is executed if an overflow in Timer/Counter0 occurs */
	//TIMSK = (1<<TOIE0);
	/* non-PWM with 256 Prescaler */
	TCCR0 = (1<<CS00) | (1<<CS02);

	/*
	CS02 CS01 CS00 Description
	 0 	 0     0   No clock source (Timer/Counter stopped).
	 0 	 0     1   clkI/O/(No prescaling)
	 0 	 1     0   clkI/O/8 (From prescaler)
	 0 	 1     1   clkI/O/64 (From prescaler)
	 1 	 0     0   clkI/O/256 (From prescaler)
	 1 	 0     1   clkI/O/1024 (From prescaler)
	 1 	 1     0   External clock source on T0 pin. Clock on falling edge.
	 1 	 1 	   1   External clock source on T0 pin. Clock on rising edge.

	TCNT0 = the value start from
	OCR0 = the value to compare with if the compare is used!!
	*/

	while((TIFR & (1<<TOV0)) == 0)
		; //Looping
	
	TCNT0 = 0x00;
	
	/*The bit TOV0 is set (one) when an overflow occurs in Timer/Counter0. TOV0 is cleared by hardware
	when executing the corresponding interrupt handling vector. */
	TIFR = (1<<TOV0);
}


/*
ISR(TIMER0_OVF_vect){
	_delay_ms(100);
	PORTA ^= (1<<PA5);
	TCNT0 = 0x00;
	TIFR = (1<<TOV0);
}
*/
