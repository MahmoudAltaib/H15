/*
 * interrupt.c
 *
 * Created: 2019-06-07 2:55:31 AM
 * Author : Ahmed Elkholi
 */ 

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>



int main(void)
{
    GICR|=(1<<INT0);
	MCUCR&=~(1<<ISC00);
	MCUCR|=(1<<ISC01);
	DDRD|=(1<<5);
	DDRD&=~(1<<0);
	DDRD|=(1<<6)|(1<<7);
	sei();

    while (1) 
    {
		PORTD|=(1<<6)|(1<<7);
		_delay_ms(300);
    }
}

ISR(INT0_vect){
	PORTD|=(1<<5);
	_delay_ms(200);
	PORTD^=(1<<6)^(1<<7);
		_delay_ms(200);

}

