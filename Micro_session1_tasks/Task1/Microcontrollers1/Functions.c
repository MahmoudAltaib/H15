/*
 * Functions.c
 *
 * Created: 5/6/2019 12:52:41 PM
 *  Author: A.Elkady
 */ 

#include "Functions.h"

extern void Set_bit( char cPORT_index , uint8_t u8Bit_index)
{
	cPORT_index |= (1<<u8Bit_index);
}

extern void Reset_bit( char cPORT_index , uint8_t u8Bit_index)
{
	cPORT_index &= ~(1<<u8Bit_index);
}

extern void Port_mode( char cPORT_index , uint8_t u8Port_state)
{
	if (u8Port_state == OUTPUT)
	{
		cPORT_index |= 0xFF;
	}
	else if  (u8Port_state == INPUT)
	{
		cPORT_index &= 0x00;
	}
	else
	{
		/* Do nothing */
	}
}

extern void Pin_mode( char cPORT_index , uint8_t u8Pin_index , uint8_t u8Pin_state)
{
	if (u8Pin_state == OUTPUT)
	{
		cPORT_index |= (1<<u8Pin_index);
	}
	else if  (u8Pin_state == INPUT)
	{
		cPORT_index &= ~(1<<u8Pin_index);
	}
	else
	{
		/* Do nothing */
	}
}
