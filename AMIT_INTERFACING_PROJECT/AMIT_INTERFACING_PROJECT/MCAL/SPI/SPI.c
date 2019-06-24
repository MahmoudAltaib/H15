/*
 * SPI.c
 *
 * Created: 6/12/2019 6:35:25 PM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "SPI/SPI.h"

/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/
extern void SPI_MASTER_INIT(void)
{
	Pin_mode(SPI_SS_PORT , SPI_SS_DDR , SPI_SS_PIN_Number , OUTPUT);
	Pin_mode(SPI_MISO_PORT , SPI_MISO_DDR , SPI_MISO_PIN_Number , INPUT);
	Pin_mode(SPI_MOSI_PORT , SPI_MOSI_DDR , SPI_MOSI_PIN_Number , OUTPUT);
	Pin_mode(SPI_SCK_PORT , SPI_SCK_DDR , SPI_SCK_PIN_Number , OUTPUT);
	
	SPI_SR = 0x00 ; 
	SPI_CR = SPI_CR_MASTER_VALUE ;
	
}

extern void SPI_SLAVE_INIT(void)
{
	
	Pin_mode(SPI_SS_PORT , SPI_SS_DDR , SPI_SS_PIN_Number , INPUT);
	Pin_mode(SPI_MISO_PORT , SPI_MISO_DDR , SPI_MISO_PIN_Number , OUTPUT);
	Pin_mode(SPI_MOSI_PORT , SPI_MOSI_DDR , SPI_MOSI_PIN_Number , INPUT);
	Pin_mode(SPI_SCK_PORT , SPI_SCK_DDR , SPI_SCK_PIN_Number , INPUT);
	
	SPI_SR = 0x00 ;
	SPI_CR = SPI_CR_SLAVE_VALUE ;
}

extern void SPI_DEINIT(void)
{
	SPI_SR = 0x00 ;
	SPI_CR = 0x00 ;
}

extern void SPI_MASTER_TRANSMIT(unsigned char u8Data)
{
	SPI_DR = u8Data ;
	while ( !(SPI_SR & (1 << SPI_FLAG)) );
}

extern void SPI_MASTER_TRANSMIT_STRING(unsigned char *pu8Data , uint8_t u8Size)
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < u8Size ; u8Count ++)
	{
		SPI_DR = pu8Data[u8Count] ;
		while ( !(SPI_SR & (1 << SPI_FLAG)) );
	}
}

extern void SPI_MASTER_RECEIVE(unsigned char *pu8Received_data)
{
	while ( !(SPI_SR & (1 << SPI_FLAG)) );
	*pu8Received_data = SPI_DR ;	
}

extern void SPI_MASTER_RECEIVE_STRING(unsigned char *pu8Received_data , uint8_t u8Size)
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < u8Size ; u8Count ++)
	{
		while ( !(SPI_SR & (1 << SPI_FLAG)) );
		pu8Received_data[u8Count] = SPI_DR ;
	}
}

extern void SPI_SLAVE_TRANSMIT(unsigned char u8Data)
{
	SPI_DR = u8Data ;
	while ( !(SPI_SR & (1 << SPI_FLAG)) );
}

extern void SPI_SLAVE_TRANSMIT_STRING(unsigned char *pu8Data , uint8_t u8Size)
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < u8Size ; u8Count ++)
	{
		SPI_DR = pu8Data[u8Count] ;
		while ( !(SPI_SR & (1 << SPI_FLAG)) );
	}
}

extern void SPI_SLAVE_RECEIVE(unsigned char *pu8Received_data)
{
	while ( !(SPI_SR & (1 << SPI_FLAG)) );
	*pu8Received_data = SPI_DR ;
}

extern void SPI_SLAVE_RECEIVE_STRING(unsigned char *pu8Received_data , uint8_t u8Size)
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < u8Size ; u8Count ++)
	{
		while ( !(SPI_SR & (1 << SPI_FLAG)) );
		pu8Received_data[u8Count] = SPI_DR ;
	}
}