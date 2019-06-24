/*
 * AMIT_SCHEMATIC.h
 *
 * Created: 5/12/2019 12:31:59 AM
 *  Author: A.Elkady
 */ 

#ifndef AMIT_SCHEMATIC_H_
#define AMIT_SCHEMATIC_H_

#define AMIT_KIT_ATMEGA32

#ifdef AMIT_KIT_ATMEGA32

#include "avr/interrupt.h"

#include "BUZZER_ONE_BUTTON/BUZZER_ON_OFF.h"
#include "SEGMENT7/SEGMENT_INC_DEC.h"
#include "LCD_HELLO/LCD_HELLO.h"	
#include "LCD_TEST/LCD_TEST.h"
#include "KEYPAD/KEYPAD_LCD.h"
#include "AMIT_BT/AMIT_BLUETOOTH.h"
#include "USART/USART.h"
#include "TIMER0/TIMER0.h"	
#include "TIMER1/TIMER1.h"

#include "ADC/ADC.h"
#endif

#endif /* AMIT_SCHEMATIC_H_ */

