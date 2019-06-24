/*
 * BUZZER_INTERFACE.c
 *
 * Created: 5/12/2019 1:43:42 PM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "BUZZER_INTERFACE.h"



/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/

extern void BUZZER_ON(void)
{
	Pin_set(BUZZER_PORT , BUZZER_PIN_NUMBER);
}

extern void BUZZER_OFF(void)
{
	Pin_reset(BUZZER_PORT , BUZZER_PIN_NUMBER);
}

extern void BUZZER_FLICKER(void)
{
	uint8_t u8Count = 0;
	
	for (u8Count = 0 ; u8Count < NUMBER_OF_BUZZER_FLICKERS ; u8Count ++)
	{
		BUZZER_ON();
		_delay_ms(BUZZER_FLICKERING_PERIOD);
		BUZZER_OFF();
		_delay_ms(BUZZER_FLICKERING_PERIOD);
	}
}