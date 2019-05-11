/*
 * GPIO_Driver.c
 *
 * Created: 5/10/2019 11:18:57 PM
 *  Author: A.Elkady
 */ 

#include "GPIO_Driver.h"

extern uint8_t Set_bit( uint8_t PORT_address , uint8_t Pin_index)
{
	(*(volatile uint8_t *) (PORT_address +0 )) |= (1<<Pin_index);
	return 1;
}

extern uint8_t Reset_bit( uint8_t PORT_address , uint8_t Pin_index)
{
	(*(volatile uint8_t *) (PORT_address +0 )) &= ~(1<<Pin_index);
	return 1;
}

extern uint8_t Port_mode( uint8_t PORT_address , uint8_t Port_state)
{
	if (Port_state == INPUT)
	{
		(*(volatile uint8_t *)(PORT_address - 1)) |= 0xFF  ;
		return 1;
	}
	else if   (Port_state == OUTPUT)
	{
		(*(volatile uint8_t *)(PORT_address - 1)) &=0x00 ;
		return 1;
	}
	else
	{
		/* Do nothing */
	}
	return 0;
}

extern uint8_t Pin_mode(  uint8_t PORT_address , uint8_t Pin_index , uint8_t Pin_state)
{
	if (Pin_state == INPUT)
	{
		(*(volatile uint8_t *)(PORT_address - 1)) &= ~(1<<Pin_index) ;
		return 1;
	}
	else if  (Pin_state == OUTPUT)
	{
		(*(volatile uint8_t *)(PORT_address -1)) |= (1<<Pin_index) ;
		return 1;
	}
	else
	{
		/* Do nothing */
	}
	return 0;
}

extern uint8_t Port_write(uint8_t PORT_address , uint8_t u8Value)
{
	(*(volatile uint8_t *)(PORT_address +0 )) = u8Value;
	return 1;
}

extern uint8_t Port_read(uint8_t PORT_address ,volatile uint8_t *u8PORT_reading)
{
	*u8PORT_reading = (*(volatile uint8_t *)(PORT_address-2)) ;
	return 1;
}

extern uint8_t Pin_write(uint8_t PORT_address ,uint8_t u8Pin_index , uint8_t u8Value)
{
	if (u8Value == 0)
	{
		Set_bit(PORT_address , u8Pin_index);
		return 1;
	}
	else
	{
		Reset_bit(PORT_address , u8Pin_index);
		return 1;
	}
	return 0;
}

extern void Pin_read(uint8_t PORT_address , uint8_t u8Pin_index ,volatile uint8_t *u8Pin_reading)
{
	*u8Pin_reading = (*(volatile uint8_t *)(PORT_address - 2)) & (1<<u8Pin_index) ;
}

