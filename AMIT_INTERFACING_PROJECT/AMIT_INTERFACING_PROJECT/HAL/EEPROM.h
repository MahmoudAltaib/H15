/*
 * EEPROM.h
 *
 * Created: 6/15/2019 7:14:13 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef EEPROM_H_
#define EEPROM_H_

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
		#include "TWI/TWI.h"
		
		/************************************************************************/
		/*              Definition of EEPROM Addresses                          */
		/************************************************************************/
		#define EEPROM_SLW_ADDRESS 0xA0
		#define EEPROM_SLR_ADDRESS 0xA1

		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/		
		extern void EEPROM_WRITE(uint16_t u16Address , unsigned char u8Data);
		extern void EEPROM_READ(uint16_t u16Address , unsigned char *pu8Data);
		
		extern void EEPROM_WRITE_STRING(uint16_t u16Address , unsigned char *pu8Data);
		extern void EEPROM_READ_STRING(uint16_t u16Address , unsigned char *pu8Data);
	
	#endif

#endif /* EEPROM_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/