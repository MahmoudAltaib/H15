/*
 * LEDS_INTERFACE.h
 *
 * Created: 5/12/2019 2:11:17 AM
 *  Author: A.Elkady
 */ 


#ifndef LEDS_INTERFACE_H_
#define LEDS_INTERFACE_H_

#include "GPIO/GPIO.h"
#include "AMIT_SCHEMATIC.h"

#define LED1 1
#define LED2 2
#define LED3 3

#define NUMBER_OF_FLASHES 3

extern void LED_ON(uint8_t u8LED_Number);
extern void LED_OFF(uint8_t u8LED_Number);

extern void LED_FLASH(uint8_t u8LED_Number);
extern void LEDS_FLASH();

#endif /* LEDS_INTERFACE_H_ */