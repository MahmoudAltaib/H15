/*
 * AMIT_LED.h
 *
 * Created: 5/11/2019 4:36:22 PM
 *  Author: hp
 */ 


#ifndef AMIT_LED_H_
#define AMIT_LED_H_

#include "PORT_DIO.h"

#define AMIT_ATMEGA
#ifdef  AMIT_ATMEGA
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "DEFINE PLATFORM"
#endif

#define  AMIT_LEDNUM_0    0u
#define  AMIT_DDR_LED0   DDRD
#define  AMIT_PORT_LED0  PORTD
#define  AMIT_PIN_LED0   5

#define  AMIT_LEDNUM_1    1u
#define  AMIT_DDR_LED1   DDRD
#define  AMIT_PORT_LED1  PORTD
#define  AMIT_PIN_LED1   6

#define  AMIT_LEDNUM_2    2u
#define  AMIT_DDR_LED2   DDRD
#define  AMIT_PORT_LED2  PORTD
#define  AMIT_PIN_LED2   7

#define LEDON         1u
#define LEDOFF        0u

extern void Led_ON(unsigned int ledNum);

extern void Led_OFF(unsigned int ledNum);

extern void Led_Toggle(unsigned int ledNum);


#endif /* AMIT_LED_H_ */