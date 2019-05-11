/*
 * Functions.c
 *
 * Created: 5/6/2019 12:52:41 PM
 *  Author: A.Elkady
 */ 

#include "Functions.h"

extern void Set_bit(volatile unsigned char *PORT_address , uint8_t Pin_index)
{
	*(PORT_address) |= (1<<Pin_index);
}

extern void Reset_bit(volatile unsigned char *PORT_address , uint8_t Pin_index)
{
	*(PORT_address) &= ~(1<<Pin_index);
}

extern void Port_mode(volatile unsigned char *PORT_address , uint8_t Port_state)
{
	if (Port_state == INPUT)
	{
		*(PORT_address) |= 0x00  ;
	}
	else if   (Port_state == OUTPUT)
	{
		*(PORT_address) &=0xFF ;
	}
	else
	{
		/* Do nothing */
	}
}

extern void Pin_mode( volatile unsigned char *PORT_address , uint8_t Pin_index , uint8_t Pin_state)
{
	if (Pin_state == INPUT)
	{
		*(PORT_address) |= ~(1<<Pin_index) ;
	}
	else if  (Pin_state == OUTPUT)
	{
		*(PORT_address) &= (1<<Pin_index) ;
	}
	else
	{
		/* Do nothing */
	}
}
