/*
 * BUTTON_INTERFACE.h
 *
 * Created: 5/12/2019 2:01:20 PM
 *  Author: A.Elkady
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "AMIT_SCHEMATIC.h"
#include "GPIO/GPIO.h"

#define ATMEGA32

#ifdef ATMEGA32

	// BUTTONS
	#define BUTTON0_PORT PORT_D
	#define BUTTON0_DDR DDR_D
	#define BUTTON0_PIN PIN_D
	#define BUTTON0_PIN_NUMBER 0

	#define BUTTON1_PORT PORT_D
	#define BUTTON1_DDR DDR_D
	#define BUTTON1_PIN PIN_D
	#define BUTTON1_PIN_NUMBER 1

	#define BUTTON2_PORT PORT_D
	#define BUTTON2_DDR DDR_D
	#define BUTTON2_PIN PIN_D
	#define BUTTON2_PIN_NUMBER 2

	#define NUMBER_OF_CHECKS 150

	extern void BUTTON0_READ(uint8_t *pu8Reading);
	extern void BUTTON1_READ(uint8_t *pu8Reading);
	extern void BUTTON2_READ(uint8_t *pu8Reading);

#endif

#endif /* BUTTON_INTERFACE_H_ */