/*
 * ahmed.c
 *
 * Created: 2019-05-07 11:49:06 PM
 * Author : Ahmed Elkholi
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/* insert your hardware initialization here */
	PORTD = (1<<PD5)(1<<PD6)(1<<PD7);
	DDRD = (1<<DDD5)(1<<DDD6)(1<<DDD7);
	/* insert your main loop code here */
	while (1)
	{
		PORTD = (1<<PD5);
		_delay_ms(500);
		PORTD = (1<<PD6);
		_delay_ms(500);
		PORTD = (1<<PD7);
		_delay_ms(500);
	}
	return 0;   /* never reached */
}


