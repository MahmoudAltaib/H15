/*
 * KEYPAD_INTERFACE.h
 *
 * Created: 5/24/2019 9:38:44 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

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
		#include "GPIO/GPIO.h"
		#include "BUZZER_INTERFACE.h"

		/************************************************************************/
		/*              Definition of KEYPAD port & pin                         */
		/************************************************************************/
		#define ROW1_PORT PORT_C
		#define ROW1_DDR DDR_C
		#define ROW1_PIN PIN_C
		#define ROW1_PIN_NUMBER 4

		#define ROW2_PORT PORT_C
		#define ROW2_DDR DDR_C
		#define ROW2_PIN PIN_C
		#define ROW2_PIN_NUMBER 5

		#define ROW3_PORT PORT_C
		#define ROW3_DDR DDR_C
		#define ROW3_PIN PIN_C
		#define ROW3_PIN_NUMBER 6

		#define ROW4_PORT PORT_C
		#define ROW4_DDR DDR_C
		#define ROW4_PIN PIN_C
		#define ROW4_PIN_NUMBER 7

		#define COLUMN1_PORT PORT_C
		#define COLUMN1_DDR DDR_C
		#define COLUMN1_PIN PIN_C
		#define COLUMN1_PIN_NUMBER 0

		#define COLUMN2_PORT PORT_C
		#define COLUMN2_DDR DDR_C
		#define COLUMN2_PIN PIN_C
		#define COLUMN2_PIN_NUMBER 1

		#define COLUMN3_PORT PORT_C
		#define COLUMN3_DDR DDR_C
		#define COLUMN3_PIN PIN_C
		#define COLUMN3_PIN_NUMBER 2

		#define COLUMN4_PORT PORT_C
		#define COLUMN4_DDR DDR_C
		#define COLUMN4_PIN PIN_C
		#define COLUMN4_PIN_NUMBER 3

		/************************************************************************/
		/*                       Other definitions                              */
		/************************************************************************/
		#define NUMBER_OF_KEYPAD_CHECKS 150

		#define ROW1 0
		#define ROW2 1
		#define ROW3 2
		#define ROW4 3

		#define COLUMN1 0
		#define COLUMN2 1
		#define COLUMN3 2
		#define COLUMN4 3

		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/
		extern void POWER_ALL_ROWS(void);
		extern void GROUND_ALL_ROWS(void);

		extern void POWER_ROW1(void);
		extern void POWER_ROW2(void);
		extern void POWER_ROW3(void);
		extern void POWER_ROW4(void);

		extern void READ_ROW1(uint8_t *pu8Reading);
		extern void READ_ROW2(uint8_t *pu8Reading);
		extern void READ_ROW3(uint8_t *pu8Reading);
		extern void READ_ROW4(uint8_t *pu8Reading);

		extern void SET_ROWS_INPUT(void);
		extern void SET_ROWS_OUTPUT(void);

		extern void POWER_ALL_COLUMNS(void);
		extern void GROUND_ALL_COLUMNS(void);

		extern void POWER_COLUMN1(void);
		extern void POWER_COLUMN2(void);
		extern void POWER_COLUMN3(void);
		extern void POWER_COLUMN4(void);

		extern void READ_COLUMN1(uint8_t *pu8Reading);
		extern void READ_COLUMN2(uint8_t *pu8Reading);
		extern void READ_COLUMN3(uint8_t *pu8Reading);
		extern void READ_COLUMN4(uint8_t *pu8Reading);

		extern void SET_COLUMNS_INPUT(void);
		extern void SET_COLUMNS_OUTPUT(void);

		extern void ACTIVATE_PULL_UP_RESISTORS(void);

		extern void GET_PRESSED_KEY(uint8_t *pu8Pressed_key);

		extern void GET_KEY_ROW_4x4(uint8_t *pu8Captured_row);
		extern void GET_KEY_COLUMN_4x4(uint8_t *pu8Captured_column);

	#else
	
		#error "DEFINE PLATFORM"

	#endif

#endif /* KEYPAD_INTERFACE_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/