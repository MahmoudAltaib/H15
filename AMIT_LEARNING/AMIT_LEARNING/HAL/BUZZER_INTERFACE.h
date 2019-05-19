/*
 * BUZZER_INTERFACE.h
 *
 * Created: 5/12/2019 1:44:02 PM
 *  Author: A.Elkady
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

#include "GPIO/GPIO.h"
#include "AMIT_SCHEMATIC.h"

#define ATMEGA32

#ifdef ATMEGA32

	// BUZZER
	#define BUZZER_PORT PORT_D
	#define BUZZER_DDR DDR_D
	#define BUZZER_PIN PIN_D
	#define BUZZER_PIN_NUMBER 4

	extern void BUZZER_ON();
	extern void BUZZER_OFF();

#endif

#endif /* BUZZER_INTERFACE_H_ */