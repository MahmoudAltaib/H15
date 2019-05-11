/*
 * Microcontrollers1.c
 *
 * Created: 5/6/2019 12:51:51 PM
 * Author : A.Elkady
 */ 
#include "Functions.h"

int main(void)
{
	Pin_mode(D-1 , 5 , OUTPUT);
	Pin_mode(D -1, 6 , OUTPUT);
	Pin_mode(D -1, 7 , OUTPUT);

	
	Reset_bit(D , 5);
	Reset_bit(D, 6);
	Reset_bit(D , 7);
	
	while (1)
	{
		Set_bit(D , 5);
		_delay_ms(500);
		Reset_bit(D , 5);
		_delay_ms(500);
		
		Set_bit(D , 6);
		_delay_ms(500);
		Reset_bit(D, 6);
		_delay_ms(500);
		
		Set_bit(D , 7);
		_delay_ms(500);
		Reset_bit(D , 7);
		_delay_ms(500);
	}
}

