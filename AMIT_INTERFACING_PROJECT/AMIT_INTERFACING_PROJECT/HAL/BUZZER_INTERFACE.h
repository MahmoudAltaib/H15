/*
 * BUZZER_INTERFACE.h
 *
 * Created: 5/12/2019 1:44:02 PM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

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
		/*              Definition of BUZZER port & pin                         */
		/************************************************************************/
		// BUZZER
		#define BUZZER_PORT PORT_D
		#define BUZZER_DDR DDR_D
		#define BUZZER_PIN PIN_D
		#define BUZZER_PIN_NUMBER 4

		/************************************************************************/
		/*                       Other definitions                              */
		/************************************************************************/
		#define NUMBER_OF_BUZZER_FLICKERS 3
		#define BUZZER_FLICKERING_PERIOD 300 // in milliseconds

		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/	
		extern void BUZZER_ON(void);
		extern void BUZZER_OFF(void);
		extern void BUZZER_FLICKER(void);

	#else
	
		#error "DEFINE PLATFORM"

	#endif

#endif /* BUZZER_INTERFACE_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/