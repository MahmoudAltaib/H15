/*
 * Amit_led.h
 *
 * Created: 11/05/2019 05:10:06 
 *  Author: pearl
 */ 


#ifndef AMIT_LED_H_
#define AMIT_LED_H_


#include "PORT_DIO.h"

#define AMIT_ATMEGA32
#ifdef  AMIT_ATMEGA32
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "DEFINE PLATFORM"
#endif

#define  AMIT_LEDNUM_0      0u
#define  AMIT_DDR_LED0   (DDRD)
#define  AMIT_PORT_LED0  (PORTD)
#define  AMIT_PIN_LED0   (PD5)

#define  AMIT_LEDNUM_1     1u
#define  AMIT_DDR_LED1   (DDRD)
#define  AMIT_PORT_LED1  (PORTD)
#define  AMIT_PIN_LED1   (PD6)

#define  AMIT_LEDNUM_2      2u
#define  AMIT_DDR_LED2   (DDRD)
#define  AMIT_PORT_LED2  (PORTD)
#define  AMIT_PIN_LED2   (PD7)

#define LEDON         1u
#define LEDOFF        0u


/************************************************************************/
/*                                                                      */
/************************************************************************/
extern void Led_ON (unsigned int ledNum);

/************************************************************************/
/*                                                                      */
/************************************************************************/
extern void Led_OFF (unsigned int ledNum);


/************************************************************************/
/*                                                                      */
/************************************************************************/
extern void Led_Togg (unsigned int ledNum);

#endif /* AMIT_LED_H_ */