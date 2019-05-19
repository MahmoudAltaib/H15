/*
 * LEDS_INTERFACE.h
 *
 * Created: 5/12/2019 2:11:17 AM
 *  Author: A.Elkady
 */ 


#ifndef LEDS_INTERFACE_H_
#define LEDS_INTERFACE_H_

#include "GPIO/GPIO.h"
#include "AMIT_SCHEMATIC.h"

#define ATMEGA32

#ifdef ATMEGA32

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

	#define LED1 1
	#define LED2 2
	#define LED3 3

	#define NUMBER_OF_FLASHES 3

	extern void LED_ON(uint8_t u8LED_Number);
	extern void LED_OFF(uint8_t u8LED_Number);

	extern void LED_FLASH(uint8_t u8LED_Number);
	extern void LEDS_FLASH();

#endif

#endif /* LEDS_INTERFACE_H_ */