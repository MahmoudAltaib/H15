/*
 * AMIT_LED.c
 *
 * Created: 5/11/2019 4:35:42 PM
 *  Author: hp
 */ 

#include "Amit_Led.h"

extern void Led_ON(unsigned int ledNum)
{
	switch (ledNum)
	{
		default:
		break;
		case(AMIT_LEDNUM_0):
		DIO_pinOUT(AMIT_DDR_LED0 , AMIT_PIN_LED0);
		DIO_pinWRITE(AMIT_PORT_LED0 , AMIT_PIN_LED0 , LEDON);
		break;
		case(AMIT_LEDNUM_1):
		DIO_pinOUT(AMIT_DDR_LED1 , AMIT_PIN_LED1);
		DIO_pinWRITE(AMIT_PORT_LED1 , AMIT_PIN_LED1 , LEDON);
		break;
		case(AMIT_LEDNUM_2):
		DIO_pinOUT(AMIT_DDR_LED1 , AMIT_PIN_LED0);
		DIO_pinWRITE(AMIT_PORT_LED1 , AMIT_PIN_LED1 , LEDON);
		break;				
	}
}

extern void Led_OFF(unsigned int ledNum)
{
	switch (ledNum)
	{
		default:
		break;
		case(AMIT_LEDNUM_0):
		DIO_pinOUT(AMIT_DDR_LED0 , AMIT_PIN_LED0);
		DIO_pinWRITE(AMIT_PORT_LED0 , AMIT_PIN_LED0 , LEDOFF);
		break;
		case(AMIT_LEDNUM_1):
		DIO_pinOUT(AMIT_DDR_LED1 , AMIT_PIN_LED1);
		DIO_pinWRITE(AMIT_PORT_LED1 , AMIT_PIN_LED1 , LEDOFF);
		break;
		case(AMIT_LEDNUM_2):
		DIO_pinOUT(AMIT_DDR_LED1 , AMIT_PIN_LED0);
		DIO_pinWRITE(AMIT_PORT_LED1 , AMIT_PIN_LED1 , LEDOFF);
		break;
	}
}

extern void Led_Toggle (unsigned int ledNum)
{

	switch (ledNum)
	{
		default:
		break;
		case(AMIT_LEDNUM_0):
		DIO_pinOUT(AMIT_DDR_LED0 , AMIT_PIN_LED0);
		DIO_pinTOGGLE(AMIT_PORT_LED0 , AMIT_PIN_LED0);
		break;
		case(AMIT_LEDNUM_1):
		DIO_pinOUT(AMIT_DDR_LED1 , AMIT_PIN_LED1);
		DIO_pinTOGGLE(AMIT_PORT_LED1 , AMIT_PIN_LED1);
		break;
		case(AMIT_LEDNUM_2):
		DIO_pinOUT(AMIT_DDR_LED1 , AMIT_PIN_LED0);
		DIO_pinTOGGLE(AMIT_PORT_LED1 , AMIT_PIN_LED1);
		break;
	}	
	
	
	
}