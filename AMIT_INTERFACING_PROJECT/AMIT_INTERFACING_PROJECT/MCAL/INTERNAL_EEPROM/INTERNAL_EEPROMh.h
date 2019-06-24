/*
 * INTERNAL_EEPROMh.h
 *
 * Created: 6/17/2019 8:53:06 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef INTERNAL_EEPROMH_H_
#define INTERNAL_EEPROMH_H_

	/************************************************************************/
	/*                  Start of platform definition                        */
	/************************************************************************/
	#define ATMEGA32
	/************************************************************************/
	/*                  End of platform definition                          */
	/************************************************************************/

	#ifdef ATMEGA32
		/************************************************************************/
		/*                               Inclusions                             */
		/************************************************************************/	
		#include <inttypes.h>
		#include "ELKADY_SCHEMATIC.h"
		/************************************************************************/
		/*                    Definition of  EEPROM registers                   */
		/************************************************************************/		
		#define EEPROM_ARH ( *( (volatile unsigned char *)(0x3F) ) )
		#define EEPROM_ARL ( *( (volatile unsigned char *)(0x3E) ) )
		#define EEPROM_DR ( *( (volatile unsigned char *)(0x3D) ) )
		#define EEPROM_CR ( *( (volatile unsigned char *)(0x3C) ) )
		#define STORE_PROGRAM_MEMORY_CR  ( *( (volatile unsigned char *)(0x57) ) )
		
		// EEPROM_CONTROL_REGISTER
		#define EEPROM_RIE   3
		#define EEPROM_MWE   2
		#define EEPROM_WE    1
		#define EEPROM_RE    0
		// STORE_PROGRAM_MEMORY_CONTROL_REGISTER
		#define STORE_PROGRAM_MEMORY_ENABLE   0

		/************************************************************************/
		/*                       Other definitions                              */
		/************************************************************************/		
		#define NUMBER_OF_LETTERS 10
		
		#define EEPROM_ADDRESS_OF_NUMBER_OF_ENTRIES 0
		#define EEPROM_FIRST_ID_ADDRESS 20
		#define EEPROM_FIRST_PASSWORD_ADDRESS 30
		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/		
		extern void INTERNAL_EEPROM_WRITE(uint16_t u16Address , char u8Data);
		extern void INTERNAL_EEPROM_READ(uint16_t u16Address , char *pu8Data);
		extern void INTERNAL_EEPROM_WRITE_STRING(uint16_t u16Starting_address , char *pu8Data);
		extern void INTERNAL_EEPROM_READ_STRING(uint16_t u16Starting_address , char *pu8Data );
		extern void INTERNAL_EEPROM_ENTER_ID(char *puID);
		extern void INTERNAL_EEPROM_ENTER_PASSWORD(char *puID);
	#endif


#endif /* INTERNAL_EEPROMH_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/