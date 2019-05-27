/*
 * RELAY_INTERFACE.c
 *
 * Created: 5/12/2019 1:43:14 PM
 *  Author: A.Elkady
 */ 

#include "RELAY_INTERFACE.h"

extern void RELAY_ON()
{
	Pin_set(RELAY_PORT , RELAY_PIN_NUMBER);
}

extern void RELAY_OFF()
{
	Pin_reset(RELAY_PORT , RELAY_PIN_NUMBER);
}

extern void RELAY_FLICKER()
{
	uint8_t u8Count = 0;
	
	for (u8Count = 0 ; u8Count < NUMBER_OF_RELAY_FLICKERS ; u8Count ++)
	{
		RELAY_ON();
		_delay_ms(RELAY_FLICKERING_PERIOD);
		RELAY_OFF();
		_delay_ms(RELAY_FLICKERING_PERIOD);
	}
	
}