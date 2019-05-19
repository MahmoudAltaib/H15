/*
 * SEGMENT7_INTERFACE.h
 *
 * Created: 5/12/2019 4:39:55 PM
 *  Author: A.Elkady
 */ 


#ifndef SEGMENT7_INTERFACE_H_
#define SEGMENT7_INTERFACE_H_

#include "GPIO/GPIO.h"
#include "AMIT_SCHEMATIC.h"
#include "LEDS_INTERFACE.h"

#define AMIT_KIT_ATMEGA32

#ifdef AMIT_KIT_ATMEGA32

#define SEGMENT1_ENABLE_PORT PORT_C
#define SEGMENT1_ENABLE_DDR DDR_C
#define SEGMENT1_ENABLE_PIN PIN_C
#define SEGMENT1_ENABLE_PIN_NUMBER 2

#define SEGMENT2_ENABLE_PORT PORT_C
#define SEGMENT2_ENABLE_DDR DDR_C
#define SEGMENT2_ENABLE_PIN PIN_C
#define SEGMENT2_ENABLE_PIN_NUMBER 3

#define SEGMENT_A_PORT PORT_C
#define SEGMENT_A_DDR DDR_C
#define SEGMENT_A_PIN PIN_C
#define SEGMENT_A_PIN_NUMBER 4

#define SEGMENT_B_PORT PORT_C
#define SEGMENT_B_DDR DDR_C
#define SEGMENT_B_PIN PIN_C
#define SEGMENT_B_PIN_NUMBER 5

#define SEGMENT_C_PORT PORT_C
#define SEGMENT_C_DDR DDR_C
#define SEGMENT_C_PIN PIN_C
#define SEGMENT_C_PIN_NUMBER 6

#define SEGMENT_D_PORT PORT_C
#define SEGMENT_D_DDR DDR_C
#define SEGMENT_D_PIN PIN_C
#define SEGMENT_D_PIN_NUMBER 7

#define SEGMENT1 1
#define SEGMENT2 2

#define BCD_A 1
#define BCD_B 2
#define BCD_C 3
#define BCD_D 4

extern void SEGMENT_ON(uint8_t u8Segment_number);
extern void SEGMENT_OFF(uint8_t u8Segment_number);

extern void BCD_PIN_SET(uint8_t u8Pin_number);
extern void BCD_PIN_RESET(uint8_t u8Pin_number);

extern void SEGMENT_RESET();

extern void SEGMENT_SHOW_NUMBER(uint8_t u8Segment7_number1);
extern void SHOW_TWO_NUMBERS(uint8_t u8Num1 , uint8_t u8Num2);

extern void SEGMENT_FLASH();

extern void SEGMENT_LEDS_FLASH();

#endif
// 7SEGMENT


#endif /* SEGMENT7_INTERFACE_H_ */