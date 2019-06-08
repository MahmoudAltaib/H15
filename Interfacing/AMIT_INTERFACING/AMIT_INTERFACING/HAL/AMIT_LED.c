/*
 * AMIT_LED.c
 *
 * Created: 11-May-19 5:50:49 PM
 *  Author: acer
 */ 
#include "AMIT_LED.h"
#include "AMIT_UTL.h"
extern void Led_ON (unsigned int ledNum)
{
	switch (ledNum)
	{
		case AMIT_LEDNUM_0 :
		DIO_PINOUT(AMIT_DDR_LED0 , AMIT_PIN_LED0);
		DIO_WRITEPIN(AMIT_PORT_LED0 , AMIT_PIN_LED0 , LEDON) ;
		break ;
		case AMIT_LEDNUM_1 :
		DIO_PINOUT(AMIT_DDR_LED1 , AMIT_PIN_LED1);
		DIO_WRITEPIN(AMIT_PORT_LED1 , AMIT_PIN_LED1 , LEDON) ;
		break ;
		case AMIT_LEDNUM_2 :
		DIO_PINOUT(AMIT_DDR_LED2 , AMIT_PIN_LED2);
		DIO_WRITEPIN(AMIT_PORT_LED2 , AMIT_PIN_LED2 , LEDON) ;
		break ;
		default :
		break ;
	}

}

/************************************************************************/
/*                                                                      */
/************************************************************************/
extern void Led_OFF (unsigned int ledNum)
{

	switch (ledNum)
	{
		case AMIT_LEDNUM_0 :
		DIO_PINOUT(AMIT_DDR_LED0 , AMIT_PIN_LED0);
		DIO_WRITEPIN(AMIT_PORT_LED0 , AMIT_PIN_LED0 , LEDOFF) ;
		break ;
		case AMIT_LEDNUM_1 :
		DIO_PINOUT(AMIT_DDR_LED1 , AMIT_PIN_LED1);
		DIO_WRITEPIN(AMIT_PORT_LED1 , AMIT_PIN_LED1 , LEDOFF) ;
		break ;
		case AMIT_LEDNUM_2 :
		DIO_PINOUT(AMIT_DDR_LED2 , AMIT_PIN_LED2);
		DIO_WRITEPIN(AMIT_PORT_LED2 , AMIT_PIN_LED2 , LEDOFF) ;
		break ;
		default :
		break ;
	}
}


/************************************************************************/
/*                                                                      */
/************************************************************************/
extern void Led_Togg (unsigned int ledNum)
{
	switch (ledNum)
	{
		case AMIT_LEDNUM_0 :
		DIO_PINOUT(AMIT_DDR_LED0 , AMIT_PIN_LED0);
		UTL_TOGGLE_PIN(AMIT_PORT_LED0 , AMIT_PIN_LED0) ;
		break ;
		case AMIT_LEDNUM_1 :
		DIO_PINOUT(AMIT_DDR_LED1 , AMIT_PIN_LED1);
		UTL_TOGGLE_PIN(AMIT_PORT_LED1 , AMIT_PIN_LED1) ;
		break ;
		case AMIT_LEDNUM_2 :
		DIO_PINOUT(AMIT_DDR_LED2 , AMIT_PIN_LED2);
		UTL_TOGGLE_PIN(AMIT_PORT_LED2 , AMIT_PIN_LED2) ;
		break ;
		default :
		break ;
	}
}