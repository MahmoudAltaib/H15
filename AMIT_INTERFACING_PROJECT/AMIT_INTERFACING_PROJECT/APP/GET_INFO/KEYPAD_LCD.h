/*
 * KEYPAD_LCD.h
 *
 * Created: 5/25/2019 5:47:15 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef KEYPAD_LCD_H_
#define KEYPAD_LCD_H_

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
		#include "KEYPAD_INTERFACE.h"
		#include "ELKADY_SCHEMATIC.h"
		#include "BUTTON_INTERFACE.h"

		/************************************************************************/
		/*                       Other definitions                              */
		/************************************************************************/
		#define ROW1 0
		#define ROW2 1
		#define ROW3 2
		#define ROW4 3

		#define COLUMN1 0
		#define COLUMN2 1
		#define COLUMN3 2
		#define COLUMN4 3

		#define MAXIMUM_NUMBER_OF_LETTERS 10
		#define MAXIMUM_NUMBER_OF_KEY_SEQUENCE 4
		
		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/
		extern void GET_LOGIN_INFO(void);
		extern uint8_t COMPARE_LOGIN_INFO(char *pc8ID , char *pc8Password);
		extern void SIGN_UP(void);
		extern void GET_KEY_ROW(uint8_t *pu8Captured_row);
		extern void GET_KEY_COLUMN(uint8_t *pu8Captured_column);
		extern void ANALYZE_PRESS(uint8_t u8Entered_character );
		extern uint8_t SIGN_UP_OR_IN_PAGE(void);
		extern uint8_t KIT_OR_BT_CONTROL();
		extern void INFO_CONTROL();
		extern void KIT_CONTROL();

	#else
	
		#error "DEFINE PLATFORM"

	#endif

#endif /* KEYPAD_LCD_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/