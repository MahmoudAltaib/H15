/*
 * GPIO.h
 *
 * Created: 5/12/2019 12:36:07 AM
 *  Author: A.Elkady
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#define F_CPU 16000000ul
#include <inttypes.h>
#include <util/delay.h>

#define ATMEGA32

#ifdef ATMEGA32
	
	#define PORT_A 0x3B
	#define DDR_A ((PORT_A)-(1))
	#define PIN_A ((PORT_A)-(2))
	
	#define PORT_B 0x38
	#define DDR_B ((PORT_B)-(1))
	#define PIN_B ((PORT_B)-(2))
	
	#define PORT_C 0x35
	#define DDR_C ((PORT_C)-(1))
	#define PIN_C ((PORT_C)-(2))
	
	#define PORT_D 0x32
	#define DDR_D ((PORT_D)-(1))
	#define PIN_D ((PORT_D)-(2))
	
	#define INPUT 0
	#define OUTPUT 1

#else
#error "DEFINE PLATFORM"

#endif

extern void Pin_set( unsigned int PORT_address , uint8_t  Pin_index);
extern void Pin_reset( unsigned int PORT_address , uint8_t Pin_index);
extern void Pin_toggle( unsigned int PORT_address , uint8_t Pin_index);
extern void Pin_mode( unsigned int PORT_address ,unsigned int DDR_address , uint8_t Pin_index , uint8_t Pin_state);
extern void Pin_read(unsigned int PIN_address , uint8_t u8Pin_index , volatile uint8_t *pu8PORT_reading);


#endif /* GPIO_H_ */