/*
 * GPIO.c
 *
 * Created: 2019-06-11 9:35:50 PM
 *  Author: Ahmed Elkholi
 */ 

#include "GPIO.h"

extern void Pin_set( unsigned int PORT_address , uint8_t  Pin_index)
{
	(*(volatile uint8_t *) (PORT_address)) |= (1<<Pin_index);
}

extern void Pin_reset( unsigned int PORT_address , uint8_t Pin_index)
{
	(*(volatile uint8_t *) (PORT_address)) &= ~(1<<Pin_index);
}

extern void Pin_toggle( unsigned int PORT_address , uint8_t Pin_index)
{
	(*(volatile uint8_t *) (PORT_address)) ^= (1<<Pin_index);
}

extern void Pin_mode(unsigned int PORT_address , unsigned int DDR_address , uint8_t Pin_index , uint8_t Pin_state)
{
	if (Pin_state == INPUT)
	{
		(*(volatile uint8_t *)(DDR_address)) &= ~(1<<Pin_index) ;
		(*(volatile uint8_t *)(PORT_address)) |= (1<<Pin_index); //  pull up on
	}
	else if (Pin_state == OUTPUT)
	{
		(*(volatile uint8_t *)(DDR_address )) |= (1<<Pin_index) ;
	}
	
}

extern void Pin_read(unsigned int PIN_address , uint8_t u8Pin_index , volatile uint8_t *pointer_reading)
{
	uint8_t u8Temp = 0;
	
	u8Temp = (*(volatile uint8_t *)(PIN_address)) & (1 << u8Pin_index) ;
	
	*pointer_reading = u8Temp ;
}
