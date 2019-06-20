/*
 * interrupt2.c
 *
 * Created: 2019-06-07 10:02:30 PM
 * Author : Ahmed Elkholi
 */ 

#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>



int main(void)
{
	GICR=(1<<INT0);
	MCUCR=(1<<ISC00)|(1<<ISC01);

	//MCUCR|=(1<<ISC01);
	DDRD|=(1<<5)|(1<<6)|(1<<7);
	DDRD&=~(1<<2);
	PORTD|=(1<<6)|(1<<7);
	
	sei();


    while (1) 
    {
    }
}

ISR(INT0_vect)
{
	static int led_0=0;
	//_delay_ms(500);
	if(led_0==0)
	{
		PORTD&=~(1<<6);
		PORTD&=~(1<<7);
		PORTD|=(1<<5);
		led_0=1;
	}
	else if(led_0==1)
	{
		PORTD|=(1<<6)|(1<<7);
		PORTD&=~(1<<5);
		led_0=0;
		
	}
}
	
