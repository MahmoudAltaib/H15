/*
 * GccApplication2.c
 *
 * Created: 5/4/2019 11:15:05 PM
 * Author : hp
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	LDI D5,$00 = (1<<5);
	LDI D6,$00 = (1<<6);
	LDI D7,$00 = (1<<7);
	DDRD |= (1<<DDD5);
	DDRD |= (1<<DDD6)
	DDRD |= (1<<DDD7);	
    while (1) 
    {
	
	LDI D5,$00 = (1<<5) ;
	_delay_ms(1000);
	LDI D5,$00 = (1<<6);
	_delay_ms(1000);
	LDI D5,$00 = (1<<7);
	_delay_ms(1000);

    }
}

