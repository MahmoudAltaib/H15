/*
 * PORT_DIO.c
 *
 * Created: 5/11/2019 2:10:24 PM
 *  Author: dell
 */ 
#include "PORT_DIO.h"
#include "AMIT_UTIL.h"

extern void DIO_pinOut(unsigned int PORTADD , unsigned int PIN_NUMBER )
{
	UTIL_SETPIN(PORTADD , PIN_NUMBER);
}
extern void DIO_PinIn(unsigned int PORTADD , unsigned int PIN_NUMBER)
{
		UTIL_CLRPIN (PORTADD , PIN_NUMBER);
		UTIL_SETPIN(PORTADD+1 , PIN_NUMBER);
}

extern void DIO_readPin(unsigned int PORTADD , unsigned int PIN_NUMBER , unsigned int *pinvalue)
{
*pinvalue =(*(volatile unsigned int *)(PORTADD) & (1<<PIN_NUMBER));
}

extern void DIO_writePin(unsigned int PORTADD , unsigned int PIN_NUMBER , unsigned int pinvalue)
{
	if(pinvalue == 0)
	{
		UTIL_CLRPIN(PORTADD , PIN_NUMBER);
	}else
	 UTIL_SETPIN(PORTADD , PIN_NUMBER);
}