/* LED ON
 * Work1.c
 *
 * Created: 5/4/2019 2:18:46 PM
 * Author : A.Elkady
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= (1<<DDD5);
	DDRD |= (1<<DDD6);
	DDRD |= (1<<DDD7);
    PORTD &= ~(1<<PD5);
    PORTD &= ~(1<<PD6);
    PORTD &= ~(1<<PD7);
    

    while (1) 
    {
		PORTD |= (1<<PD5);
		 _delay_ms(2000);
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

