/*
 * GccApplication15.c
 *
 * Created: 2019-05-14 11:35:55 PM
 * Author : Ahmed Elkholi
 */ 

#in#define F_CPU 16000000UL
clude <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= (1<<5);
	DDRD |= (1<<6);
	DDRD |= (1<<7);
	PORTD &= ~(1<<5);
	PORTD &= ~(1<<6);
	PORTD &= ~(1<<7);
	

	while (1)
	{
		PORTD  |= (1<<PD5);
		_delay_ms(200);
		PORTD &= ~(1<<PD5);
		_delay_ms(200);
		PORTD |= (1<<PD6);
		_delay_ms(200);
		PORTD &= ~(1<<PD6);
		_delay_ms(200);
		PORTD |= (1<<PD7);
		_delay_ms(200);
		PORTD &= ~(1<<PD7);
		_delay_ms(200);
	}
}


