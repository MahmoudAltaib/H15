/*
 * USART.c
 *
 * Created: 6/6/2019 9:11:22 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "USART.h"


/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/
extern void USART_INIT(void)
{
	USART_CSRB |= USART_CSR_B_VALUE;				
	USART_CSRC |= USART_CSR_C_VALUE;	
	USART_BRRL = USART_BRRL_VALUE;							
}

extern void USART_DEINIT(void)
{
	USART_CSRB = 0x00;				
	USART_CSRC = 0x00;	
	USART_BRRL = 0x00;
	USART_DR = 0x00 ;
}

extern void USART_TRANSMIT(char u8Transmitted_data)
{
	USART_DR = u8Transmitted_data ;
	while ( !(USART_CSRA & (1 << USART_DRE)) );
}

extern void USART_TRANSMIT_STRING(char *pu8Transmitted_string , char u8Transmitted_data_size)
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < u8Transmitted_data_size ; u8Count ++)
	{
		USART_TRANSMIT(pu8Transmitted_string[u8Count]);
	}
}

extern void USART_RECEIVE(char *pu8Received_data)
{
	while ( !(USART_CSRA & (1 << USART_RXC)));
	*pu8Received_data = USART_DR ;
}

extern void USART_TRANSMIT_CERTAIN_STRING(char *pu8String , char u8Transmitted_data_size)					
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < u8Transmitted_data_size ; u8Count ++)
	{
		USART_TRANSMIT(pu8String[u8Count]);
	}
}
