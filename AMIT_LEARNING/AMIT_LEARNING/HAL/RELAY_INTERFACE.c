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
