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

#define A (*(volatile unsigned char *)0x3B)  /* Those are the addresses of the ports A,B,C and D  */
#define B (*(volatile unsigned char *)0x38)
#define C (*(volatile unsigned char *)0x35)
#define D (*(volatile unsigned char *)0x32)

extern void Set_bit(volatile unsigned char *PORT_address , uint8_t  Pin_index);
extern void Reset_bit(volatile unsigned char *PORT_address , uint8_t Pin_index);

extern void Port_mode(volatile unsigned char *PORT_address , uint8_t Port_state);

extern void Pin_mode(volatile unsigned char *PORT_address , uint8_t Pin_index , uint8_t Pin_state);

#endif