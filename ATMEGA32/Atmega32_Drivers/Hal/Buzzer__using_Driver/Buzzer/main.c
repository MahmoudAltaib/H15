/*
 * Buzzer.c
 *
 * Created: 2019-05-17 10:45:50 PM
 * Author : Ahmed Elkholi
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <GPIO/GPIO.h/GPIO.h>


int main(void)
{
	 Pin_set(0x32,0);
	 Pin_set(0x32,1);
	 Pin_reset(0x31,0);
	 Pin_reset(0x31,1);
	 Pin_set(0x31,4);
	 Pin_reset(0x32,4);
	
    
    while (1) 
    {
		uint8_t pin6_value;
		uint8_t pin7_value;
		
		pin6_value = (( PIND ) & 1);
		
		if( pin6_value == 1 )
	
		{
			PORTD |= (1<<4);
			
		}
		
		pin7_value = ((PIND>>1) & 1);
		
		if( pin7_value == 1)
		
		{
			PORTD &= ~(1<<4);
		
		}
		
	
    }
}

