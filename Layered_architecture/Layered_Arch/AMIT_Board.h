/*
 * AMIT_Board.h
 *
 * Created: 5/10/2019 11:22:53 PM
 *  Author: A.Elkady
 */ 

#ifndef AMIT_Board 
#define AMIT_Board

#include "AMIT_Layout.h"
#include "GPIO_Driver.h"

#define AMIT_ATMEGA


#ifdef AMIT_ATMEGA

#define PORT1 A
#define PORT2 B
#define PORT3 C
#define PORT4 D
	
extern void LED_On (uint8_t u8LED_Number);
extern void LED_Off(uint8_t u8LED_Number);
extern void Relay_On ();
extern void Relay_Off();
extern void Buzzer_On ();
extern void Buzzer_Off();

#endif

#endif