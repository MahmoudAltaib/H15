/*
 * PORT_DIO.c
 *
 * Created: 11-May-19 3:13:06 PM
 *  Author: acer
 */ 
#include "PORT_DIO.h"
#include "AMIT_UTL.h"


extern void DIO_PINOUT (unsigned int PORT_ADR , unsigned int PIN_NMBR)
{
	UTL_SET_PIN(PORT_ADR , PIN_NMBR);
}

extern void DIO_PININ (unsigned int PORT_ADR , unsigned int PIN_NMBR)
{
	UTL_CLR_PIN(PORT_ADR , PIN_NMBR);
	UTL_SET_PIN(PORT_ADR +1 , PIN_NMBR); //for the pull up resistor to function//
}
extern void DIO_READPIN (unsigned int PORT_ADR , unsigned int PIN_NMBR , unsigned int * PIN_VALUE)
{
	*PIN_VALUE = (*(volatile unsigned int *) (PORT_ADR)) & (1 << PIN_NMBR);
}
extern void DIO_WRITEPIN (unsigned int PORT_ADR, unsigned int PIN_NMBR, unsigned int PIN_VALUE)
{
	if (PIN_VALUE == 0)
	{
		UTL_CLR_PIN(PORT_ADR , PIN_NMBR);
	}
	else
	{
		UTL_SET_PIN(PORT_ADR , PIN_NMBR);
	}
}