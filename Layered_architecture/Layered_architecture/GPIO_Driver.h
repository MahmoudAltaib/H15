/*
 * GPIO_Driver.h
 *
 * Created: 5/10/2019 11:19:15 PM
 *  Author: A.Elkady
 */ 
#ifndef GPIO_Driver 
#define GPIO_Driver

#define F_CPU 16000000ul
#include <inttypes.h>
#include <util/delay.h>

#define AMIT_ATMEGA 

#ifdef AMIT_ATMEGA 

	#define INPUT 0
	#define OUTPUT 1

	#define A 0x3B
	#define B 0x38
	#define C 0x35
	#define D 0x32

	extern uint8_t Set_bit( uint8_t PORT_address , uint8_t  Pin_index);
	extern uint8_t Reset_bit( uint8_t PORT_address , uint8_t Pin_index);
	extern uint8_t Port_mode( uint8_t PORT_address , uint8_t Port_state);
	extern uint8_t Pin_mode( uint8_t PORT_address , uint8_t Pin_index , uint8_t Pin_state);
	extern uint8_t Port_write(uint8_t PORT_address , uint8_t u8Value);
	extern uint8_t Port_read(uint8_t PORT_address  , volatile uint8_t *u8PORT_reading);
	extern uint8_t Pin_write(uint8_t PORT_address ,uint8_t u8Pin_index , uint8_t u8Value);
	extern void Pin_read(uint8_t PORT_address , uint8_t u8Pin_index , volatile uint8_t *u8PORT_reading);

#endif
#endif

