/*
 * functions.c
 *
 * Created: 5/9/2019 4:20:46 PM
 *  Author: A.Elkady
 */ 

#include "functions.h"

extern uint8_t Pin_mode(uint8_t u8Port_index , uint8_t u8Pin_index , uint8_t u8Mode)
{
	if (u8Mode == OUTPUT)
	{
		*((volatile uint8_t *)(u8Port_index-1)) |= (1<<u8Pin_index); 
	}
	else if (u8Mode == INPUT)
	{
		*((volatile uint8_t *)(u8Port_index-1)) &= ~(1<<u8Pin_index);
	}
	else
	{
		return 0;
	}
	
	return 1;
}


extern uint8_t Set_bit(uint8_t u8Port_index , uint8_t u8Pin_index)
{
	*((volatile uint8_t *)u8Port_index) |= (1<<u8Pin_index);
	return 1;
}

extern uint8_t Reset_bit (uint8_t u8Port_index , uint8_t u8Pin_index)
{
	*((volatile uint8_t *)u8Port_index) &= ~(1<<u8Pin_index);
	return 1;
}