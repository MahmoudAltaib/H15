/*
 * Functions.h
 *
 * Created: 5/6/2019 12:53:00 PM
 *  Author: A.Elkady
 */ 

#ifndef  Functions 
#define Functions

#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <string.h>

#define OUTPUT 1
#define INPUT 0

#define A 0x3B         
#define B 0x38
#define C 0x35
#define D 0x32

extern uint8_t Set_bit( uint8_t PORT_address , uint8_t  Pin_index);
extern uint8_t Reset_bit( uint8_t PORT_address , uint8_t Pin_index);
extern uint8_t Port_mode( uint8_t PORT_address , uint8_t Port_state);
extern uint8_t Pin_mode( uint8_t PORT_address , uint8_t Pin_index , uint8_t Pin_state);
extern uint8_t Port_write(uint8_t PORT_address , uint8_t u8Value);
extern uint8_t Port_read(uint8_t PORT_address  , uint8_t *u8PORT_reading);
extern uint8_t Pin_write(uint8_t PORT_address ,uint8_t u8Pin_index , uint8_t u8Value);
extern uint8_t Pin_read(uint8_t PORT_address , uint8_t u8Pin_index );

extern void Clear_7SEG();

#endif