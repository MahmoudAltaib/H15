/*
 * BUTTON_INTERFACE.h
 *
 * Created: 5/12/2019 2:01:20 PM
 *  Author: A.Elkady
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "AMIT_SCHEMATIC.h"
#include "GPIO/GPIO.h"

#define NUMBER_OF_CHECKS 150

extern void BUTTON0_READ(uint8_t *pu8Reading);
extern void BUTTON1_READ(uint8_t *pu8Reading);
extern void BUTTON2_READ(uint8_t *pu8Reading);

#endif /* BUTTON_INTERFACE_H_ */