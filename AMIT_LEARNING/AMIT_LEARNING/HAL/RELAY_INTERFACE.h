/*
 * RELAY_INTERFACE.h
 *
 * Created: 5/12/2019 1:43:28 PM
 *  Author: A.Elkady
 */ 


#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_

#include "GPIO/GPIO.h"
#include "AMIT_SCHEMATIC.h"

#define ATMEGA32

#ifdef ATMEGA32

	// RELAY
	#define RELAY_PORT PORT_D
	#define RELAY_DDR DDR_D
	#define RELAY_PIN PIN_D
	#define RELAY_PIN_NUMBER 3

	extern void RELAY_ON();
	extern void RELAY_OFF();

#endif

#endif /* RELAY_INTERFACE_H_ */