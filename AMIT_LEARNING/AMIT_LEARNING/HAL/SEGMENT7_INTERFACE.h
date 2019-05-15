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

extern void SEGMENT_SHOW_NUMBER(uint8_t u8Segment7_number);

extern void SEGMENT_FLASH();

extern void SEGMENT_LEDS_FLASH();

#endif /* SEGMENT7_INTERFACE_H_ */