/*
 * Try.c
 *
 * Created: 5/10/2019 4:15:46 PM
 * Author : A.Elkady
 */ 

#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
 uint8_t u8Temp = 0;
 uint8_t u8Reading = 0;
 
DDRC |= (1<<2);
DDRC |= (1<<3);
DDRC |= (1<<4);
DDRC |= (1<<5);
DDRC |= (1<<6);
DDRC |= (1<<7);

 DDRD &= ~(1<<0);
 DDRD &= ~(1<<1);
 DDRD &= ~(1<<2);
 
 PORTC |= (1<<2);
 PORTC &= ~(1<<3);
 PORTC &= ~(1<<4);
 PORTC &= ~(1<<5);
 PORTC &= ~(1<<6);
 PORTC &= ~(1<<7);

 PORTC |= (u8Temp << 4) ;
 
 
	 while (1)
	 {
		 u8Reading = PIND & (1) ;
		 
		 if (u8Reading == 1)
		 {
			 u8Temp ++;
			 PORTC |= (u8Temp << 4) ;
			 _delay_ms(1000);
		 }
		 
	 }
 
 
}