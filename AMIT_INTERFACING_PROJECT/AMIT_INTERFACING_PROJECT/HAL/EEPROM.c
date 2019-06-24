/*
 * EEPROM.c
 *
 * Created: 6/15/2019 7:14:29 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "EEPROM.h"



/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/

extern void EEPROM_WRITE(uint16_t u16Address , unsigned char u8Data)
{	

	TWI_START();
		
	TWI_TRANSMIT(0xA0);
	TWI_TRANSMIT(0xA0);
	
	TWI_TRANSMIT(0);
	TWI_TRANSMIT(0);
	
	TWI_TRANSMIT(u8Data);
	
	TWI_STOP();	
	
	_delay_ms(20);	
}

extern void EEPROM_READ(uint16_t u16Address , unsigned char *pu8Data)
{
	uint8_t u8Temp = 0;

	TWI_START();
	
	TWI_TRANSMIT(0xA0);
	
	TWI_TRANSMIT(0);
	
	TWI_TRANSMIT(0);
	
	TWI_START();
	
	TWI_TRANSMIT(0xA1);
	
	TWI_RECEIVE_ACK(&u8Temp);
	
	TWI_RECEIVE_NOACK(&u8Temp);
	*pu8Data = u8Temp ;
	
	TWI_STOP();
}

extern void EEPROM_WRITE_STRING(uint16_t u16Address , unsigned char *pu8Data)
{

	TWI_START();
	
	TWI_TRANSMIT(0xA0);
	
	TWI_TRANSMIT(0x00);
	TWI_TRANSMIT(0x00);
	
	TWI_STOP();
	
	_delay_ms(20);
}

extern void EEPROM_READ_STRING(uint16_t u16Address , unsigned char *pu8Data)
{
	uint8_t u8Temp = 0;

	TWI_START();
	
	TWI_TRANSMIT(0xA0);
	
	TWI_TRANSMIT(0x00);
	
	TWI_TRANSMIT(0x00);
	
	TWI_START();
	
	TWI_TRANSMIT(0xA1);
	
	TWI_RECEIVE_ACK(&u8Temp);
	
	TWI_RECEIVE_NOACK(&u8Temp);
	*pu8Data = u8Temp ;
	LCD_DATA(u8Temp);
		
	TWI_STOP();
}