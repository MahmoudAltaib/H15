/*
 * AMIT_SCHEMATIC.h
 *
 * Created: 5/11/2019 4:40:34 PM
 *  Author: hp
 */ 


#ifndef AMIT_SCHEMATIC_H_
#define AMIT_SCHEMATIC_H_

#define AMIT_ATMEGA
#ifdef  AMIT_ATMEGA
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "DEFINE PLATFORM"
#endif

#include "AMIT_BUTTON.h"
#include "AMIT_LED.h"
#include "AMIT_7_SEGMENT.h"
#include "AMIT_BUZZER.h"




#endif /* AMIT_SCHEMATIC_H_ */