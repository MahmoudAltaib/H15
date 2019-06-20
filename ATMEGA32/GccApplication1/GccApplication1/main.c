/*
 * GccApplication1.c
 *
 * Created: 2019-05-04 2:24:20 PM
 * Author : Ahmed Elkholi
 */ 


#include <avr/io.h>


int main(void)
{
	
		
		
		PORTD = (1<<PD5)|(1<<PD6)|(1<<PD7);
		DDRD = (1<<DDD5)|(1<<DDD6)|(1<<DDD7);
		
		
		while (1)
		{
			PORTD = (1<<PD5)|(1<<PD6)|(1<<PD7);
		}
	}


