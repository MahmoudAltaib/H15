/*
 * AMIT_BUZZER.c
 *
 * Created: 5/17/2019 10:30:14 AM
 *  Author: hp
 */ 
#include "AMIT_BUZZER.h"
extern void BUZZ_ON()
{
	DIO_pinOUT(AMIT_DDR_BUZZ , AMIT_PIN_BUZZ );
	DIO_pinWRITE(AMIT_PORT_BUZZ , AMIT_PIN_BUZZ , 1);
}

extern void BUZZ_OFF()
{
		DIO_pinOUT(AMIT_DDR_BUZZ , AMIT_PIN_BUZZ );
		DIO_pinWRITE(AMIT_PORT_BUZZ , AMIT_PIN_BUZZ , 0);
	
}