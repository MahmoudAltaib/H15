/*
 * AMIT_BUZZER.h
 *
 * Created: 5/17/2019 10:29:56 AM
 *  Author: hp
 */ 


#ifndef AMIT_BUZZER_H_
#define AMIT_BUZZER_H_

#include "PORT_DIO.h"

#define AMIT_ATMEGA
#ifdef  AMIT_ATMEGA
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "DEFINE PLATFORM"
#endif

#define  AMIT_BUZZ    0u
#define  AMIT_DDR_BUZZ   DDRD
#define  AMIT_PORT_BUZZ  PORTD
#define  AMIT_PIN_BUZZ   4

extern void BUZZ_ON();
extern void BUZZ_OFF();

#endif /* AMIT_BUZZER_H_ */