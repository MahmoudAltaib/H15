/*
 * functions.h
 *
 * Created: 5/9/2019 4:20:59 PM
 *  Author: A.Elkady
 */ 

#ifndef functions 
#define functions 

#define F_CPU 16000000ul
#include <inttypes.h>
#include <util/delay.h>

#define A 0x3B
#define B 0x38
#define C 0x35
#define D 0x32

#define INPUT 0
#define OUTPUT 1

extern uint8_t Pin_mode(uint8_t u8Port_index , uint8_t u8Pin_index , uint8_t u8Mode);
extern uint8_t Set_bit(uint8_t u8Port_index , uint8_t u8Pin_index);
extern uint8_t Reset_bit (uint8_t u8Port_index , uint8_t u8Pin_index);

#endif
