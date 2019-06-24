/*
 * ELKADY_SCHEMATIC.h
 *
 * Created: 5/12/2019 12:31:59 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef ELKADY_SCHEMATIC_H_
#define ELKADY_SCHEMATIC_H_

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
		#include "avr/interrupt.h"
		#include "LEDS_INTERFACE.h"
		#include "BUZZER_INTERFACE.h"
		#include "BUTTON_INTERFACE.h"
		#include "RELAY_INTERFACE.h"
		#include "KIT_TEST/LCD_TEST.h"
		#include "GET_INFO/KEYPAD_LCD.h"
		#include "BLUETOOTH_CONTROL/Elkady_BLUETOOTH.h"
		#include "USART/USART.h"
		#include "TIMER1/TIMER1.h"
		#include "TWI/TWI.h"
		#include "ADC/ADC.h"
		#include "EEPROM.h"
		#include "INTERNAL_EEPROM/INTERNAL_EEPROMh.h"

	#else
	
		#error "DEFINE PLATFORM"

	#endif

#endif /* ELKADY_SCHEMATIC_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/

