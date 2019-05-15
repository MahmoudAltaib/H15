/*
 * BUZZER_INTERFACE.c
 *
 * Created: 5/12/2019 1:43:42 PM
 *  Author: A.Elkady
 */ 
#include "BUZZER_INTERFACE.h"

extern void BUZZER_ON()
{
	Pin_set(BUZZER_PORT , BUZZER_PIN_NUMBER);
}

extern void BUZZER_OFF()
{
	Pin_reset(BUZZER_PORT , BUZZER_PIN_NUMBER);
}
