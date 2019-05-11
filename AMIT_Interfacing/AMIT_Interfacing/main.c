/*
 * AMIT_Interfacing.c
 *
 * Created: 5/11/2019 2:05:19 PM
 * Author : dell
 */ 

#include <avr/io.h>
#include "PORT_DIO.h"
#include "AMIT_UTIL.h"



int main(void)
{
	unsigned int temp = 0 ;
	DIO_PinIn(DDRD , DDD0);
	
//	DIO_pinOut(DDRD , DDD5);
//	DIO_writePin(PORTD , PIND5 ,1);
    /* Replace with your application code */
    while (1) 
    {
		DIO_readPin(PIND , PIND0 , &temp);
		if (temp != 0)
		{
			DIO_pinOut(DDRD , DDD5);
			UTIL_TOGGLEPIN (PORTD , PD5);
			

		}
    }
}

