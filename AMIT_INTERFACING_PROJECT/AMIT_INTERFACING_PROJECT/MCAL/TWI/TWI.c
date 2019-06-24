/*
 * TWI.c
 *
 * Created: 6/14/2019 2:21:23 PM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "TWI/TWI.h"

/************************************************************************/
/*                         Declarations & Definitions                   */
/************************************************************************/
extern void TWI_INIT()
{
	TWI_SR = 0x00 ;
	TWI_BR = TWI_BR_VALUE ;
}

extern void TWI_START()
{
	TWI_CR = TWI_MASTER_START_VALUE ;
	while ( ((TWI_CR) & (1 << TWI_INT)) == 0 );	
}

extern void TWI_STOP()
{
	TWI_CR = TWI_MASTER_STOP_VALUE ;
}

extern void TWI_TRANSMIT(unsigned char u8Data)
{
	TWI_DR = u8Data ;
	TWI_CR = (1 << TWI_INT) | (1 << TWI_EN) ;
	while ( ((TWI_CR) & (1 << TWI_INT)) == 0 );
}

extern void TWI_RECEIVE_ACK(unsigned char *pu8Received_data)
{
	TWI_CR = (1 << TWI_INT) | (1 << TWI_EN) | (1 << TWI_EA) ;
	while (((TWI_CR) & (1 << TWI_INT)) == 0 );
	*pu8Received_data = TWI_DR ;
}

extern void TWI_RECEIVE_NOACK(unsigned char *pu8Received_data)
{
	TWI_CR = (1 << TWI_INT) | (1 << TWI_EN) ;
	while (((TWI_CR) & (1 << TWI_INT)) == 0 );
	*pu8Received_data = TWI_DR ;
}

extern void TWI_TRANSMIT_STRING(unsigned char *pu8Data , uint8_t u8Size)
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < u8Size ; u8Count ++)
	{
		TWI_TRANSMIT(pu8Data[u8Count]);
	}
	
}

extern void TWI_RECEIVE_STRING(unsigned char *pu8Received_data , uint8_t u8Size)
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < u8Size ; u8Count ++)
	{
		TWI_CR = 0x00 ;
		TWI_CR |= (1 << TWI_EA) ;
		TWI_RECEIVE_ACK(&pu8Received_data[u8Count]);
	}
}




