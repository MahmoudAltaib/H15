/*
 * GPIO.c
 *
 * Created: 5/12/2019 12:36:27 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "GPIO.h"

/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/
extern void Pin_set( unsigned int PORT_address , uint8_t  Pin_index)
{
	(*(volatile unsigned char *) (PORT_address)) |= (1<<Pin_index);
}

extern void Pin_reset( unsigned int PORT_address , uint8_t Pin_index)
{
	(*(volatile unsigned char *) (PORT_address)) &= ~(1<<Pin_index);
}

extern void Pin_toggle( unsigned int PORT_address , uint8_t Pin_index)
{
	(*(volatile unsigned char *) (PORT_address)) ^= (1<<Pin_index);
}

extern void Pin_mode(unsigned int PORT_address , unsigned int DDR_address , uint8_t Pin_index , uint8_t Pin_state)
{
	if (Pin_state == INPUT)
	{
		(*(volatile unsigned char *)(DDR_address)) &= ~(1<<Pin_index) ;
		(*(volatile unsigned char *)(PORT_address)) |= (1<<Pin_index) ; // To activate the pull up resistor
	}
	else if (Pin_state == OUTPUT)
	{
		(*(volatile unsigned char *)(DDR_address )) |= (1<<Pin_index) ;
	}
	else
	{
		
	}
}

extern void Pin_read(unsigned int PIN_address , uint8_t u8Pin_index , volatile uint8_t *pu8PORT_reading)
{
	uint8_t u8Temp = 0;
	
	u8Temp = (*(volatile unsigned char *)(PIN_address)) & (1 << u8Pin_index) ;
	
	*pu8PORT_reading = u8Temp ;
}

