/*
 * try.c
 *
 * Created: 5/9/2019 4:20:17 PM
 * Author : A.Elkady
 */ 
#include "functions.h"

int main(void)
{
	Pin_mode(D,5,OUTPUT);
	Reset_bit(D,5);
	
    while (1) 
    {
		Set_bit(D,5);
		_delay_ms(200);
		Reset_bit(D,5);
		_delay_ms(200);
    }
}

