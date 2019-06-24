/*
 * LEDS_INTERFACE.h
 *
 * Created: 5/12/2019 2:11:17 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef LEDS_INTERFACE_H_
#define LEDS_INTERFACE_H_

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
		#include "ELKADY_SCHEMATIC.h"

		/************************************************************************/
		/*              Definition of LEDS ports & pins                         */
		/************************************************************************/		
		// LEDS
		#define LED1_PORT PORT_D
		#define LED1_DDR DDR_D
		#define LED1_PIN PIN_D
		#define LED1_PIN_NUMBER 5

		#define LED2_PORT PORT_D
		#define LED2_DDR DDR_D
		#define LED2_PIN PIN_D
		#define LED2_PIN_NUMBER 6

		#define LED3_PORT PORT_D
		#define LED3_DDR DDR_D
		#define LED3_PIN PIN_D
		#define LED3_PIN_NUMBER 7

		/************************************************************************/
		/*                       Other definitions                              */
		/************************************************************************/
		#define LED1 1
		#define LED2 2
		#define LED3 3

		#define NUMBER_OF_LEDS_FLICKERS 5
		#define LEDS_FLASHING_PERIOD 500 // in milliseconds

		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/	
		extern void LED_ON(uint8_t u8LED_Number);
		extern void LED_OFF(uint8_t u8LED_Number);

		extern void LED_FLASH(uint8_t u8LED_Number);
		extern void LEDS_FLASH(void);

	#else
	
		#error "DEFINE PLATFORM"

	#endif

#endif /* LEDS_INTERFACE_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/