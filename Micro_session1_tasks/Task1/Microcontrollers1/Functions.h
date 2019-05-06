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

extern void Set_bit( char cPORT_index , uint8_t u8Bit_index);
extern void Reset_bit(char cPORT_index , uint8_t u8Bit_index);

extern void Port_mode( char cPORT_index , uint8_t u8Port_state);

extern void Pin_mode( char cPORT_index , uint8_t u8Pin_index , uint8_t u8Pin_state);

#endif