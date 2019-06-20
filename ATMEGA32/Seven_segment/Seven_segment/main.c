/*
 * Seven_segment.c
 *
 * Created: 2019-05-21 5:14:23 AM
 * Author : Ahmed Elkholi
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    PORTD|=(1<<0);
    PORTD|=(1<<1);
    
    DDRD&=~(1<<0);
    DDRD&=~(1<<1);
	PORTC&=~(1<<3);
	PORTC&=~(1<<2);
	DDRC|=(1<<3);
	DDRC|=(1<<2);
    while (1) 
    {
		int pin6_value;
		int pin7_value;
		int i;
		pin6_value= (( PIND ) & 1);
		if ( pin6_value == 1 )
		{
			i++;
			PORTC&=~(1<<4);   //
			PORTC&=~(1<<5);
			PORTC&=~(1<<6);
			PORTC&=~(1<<7);
			PORTC|=(i<<4);     //
			
			PORTC|=(1<<3);
			PORTC|=(1<<2);
			_delay_ms(300);
			
		}
		pin7_value=((PIND>>1) & 1);
		if (pin7_value == 1)
		{    
				i--;
			PORTC&=~(1<<4);  //
			PORTC&=~(1<<5);
			PORTC&=~(1<<6);
			PORTC&=~(1<<7);
			PORTC|=(i<<4);   //
			
			PORTC|=(1<<3);
			PORTC|=(1<<2);
			
			_delay_ms(300);
		}
    }
}

