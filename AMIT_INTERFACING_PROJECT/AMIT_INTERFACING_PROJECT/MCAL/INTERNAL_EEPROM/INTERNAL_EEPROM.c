/*
 * INTERNAL_EEPROM.c
 *
 * Created: 6/17/2019 8:53:17 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "INTERNAL_EEPROM/INTERNAL_EEPROMh.h"

/************************************************************************/
/*          Declaration of global variables from other files            */
/************************************************************************/
extern char gc8EEPROM_address_of_number_of_entries ;


/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/
extern void INTERNAL_EEPROM_WRITE(uint16_t u16Address , char u8Data)
{
	uint8_t u8Temp_address = 0 ;
	
	while ( (EEPROM_CR & (1 << EEPROM_WE)) != 0 );
	while ( (STORE_PROGRAM_MEMORY_CR & (1 << STORE_PROGRAM_MEMORY_ENABLE)) != 0 );
	
	u8Temp_address = u16Address ;
	EEPROM_ARL = u8Temp_address ;
	
	u8Temp_address = (u16Address >> 8);
	EEPROM_ARH = u8Temp_address ; 
	
	EEPROM_DR = u8Data ;
	
	EEPROM_CR = (1 << EEPROM_MWE);
	EEPROM_CR |= (1 << EEPROM_WE);
}

extern void INTERNAL_EEPROM_READ(uint16_t u16Address , char *pu8Data)
{
	uint8_t u8Temp_address = 0 ;
	
	while ( (EEPROM_CR & (1 << EEPROM_WE)) != 0 );
	
	u8Temp_address = u16Address ;
	EEPROM_ARL = u8Temp_address ;
	
	u8Temp_address = (u16Address >> 8);
	EEPROM_ARH = u8Temp_address ;
	
	EEPROM_CR |= (1 << EEPROM_RE);
	
	*pu8Data = EEPROM_DR ;
}

extern void INTERNAL_EEPROM_WRITE_STRING(uint16_t u16Starting_address , char *pu8Data )
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < NUMBER_OF_LETTERS ; u8Count ++)
	{
		INTERNAL_EEPROM_WRITE( (u16Starting_address + u8Count) , pu8Data[u8Count] );
	}
}

extern void INTERNAL_EEPROM_READ_STRING(uint16_t u16Starting_address , char *pu8Data )
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < NUMBER_OF_LETTERS ; u8Count ++)
	{
		INTERNAL_EEPROM_READ( (u16Starting_address + u8Count) , &pu8Data[u8Count] );
	}
}

extern void INTERNAL_EEPROM_ENTER_ID(char *pc8ID)
{
	if (gc8EEPROM_address_of_number_of_entries == 0 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS ) , pc8ID);
	} 
	else if (gc8EEPROM_address_of_number_of_entries == 1 )
	{	
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS + 20) , pc8ID);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 2 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS + 40) , pc8ID);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 3 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS + 60) , pc8ID);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 4 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS + 80) , pc8ID);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 5 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS + 100) , pc8ID);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 6 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS + 120) , pc8ID);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 7 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS + 140) , pc8ID);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 8 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS + 160) , pc8ID);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 9 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_ID_ADDRESS + 180) , pc8ID);
	}
	else
	{
		LCD_CLEAR();
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("Full database", 13);
	}
}

extern void INTERNAL_EEPROM_ENTER_PASSWORD(char *pc8Password)
{
	
	if (gc8EEPROM_address_of_number_of_entries == 0 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS ) , pc8Password);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 1 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS + 20) , pc8Password);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 2 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS + 40) , pc8Password);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 3 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS + 60) , pc8Password);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 4 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS + 80) , pc8Password);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 5 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS + 100) , pc8Password);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 6 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS + 120) , pc8Password);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 7 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS + 140) , pc8Password);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 8 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS + 160) , pc8Password);
	}
	else if (gc8EEPROM_address_of_number_of_entries == 9 )
	{
		INTERNAL_EEPROM_WRITE_STRING((uint16_t) (EEPROM_FIRST_PASSWORD_ADDRESS + 180) , pc8Password);
	}
	else
	{
		LCD_CLEAR();
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("Full database", 13);
	}
}
