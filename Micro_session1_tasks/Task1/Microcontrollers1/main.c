/*
 * Microcontrollers1.c
 *
 * Created: 5/6/2019 12:51:51 PM
 * Author : A.Elkady
 */ 
#include "Functions.h"

int main(void)
{
	Pin_mode(DDRD , 5 , OUTPUT);
	Pin_mode(DDRD , 6 , OUTPUT);
	Pin_mode(DDRD , 7 , OUTPUT);

	
	Reset_bit(PORTD , 5);
	Reset_bit(PORTD , 6);
	Reset_bit(PORTD , 7);
	
	while (1)
	{
		Set_bit(PORTD , 5);
		_delay_ms(200);
		Reset_bit(PORTD , 5);
		_delay_ms(200);
		
		Set_bit(PORTD , 6);
		_delay_ms(200);
		Reset_bit(PORTD , 6);
		_delay_ms(200);
		
		Set_bit(PORTD , 7);
		_delay_ms(200);
		Reset_bit(PORTD , 7);
		_delay_ms(200);
	}
}

