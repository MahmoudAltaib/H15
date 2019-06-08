/*
 * AMIT_BUZZER_RELAY.h
 *
 * Created: 18-May-19 11:50:30 AM
 *  Author: acer
 */ 


#ifndef AMIT_BUZZER_RELAY_H_
#define AMIT_BUZZER_RELAY_H_
#include "PORT_DIO.h"
#include "AMIT_BUTTON.h"

#define AMIT_ATMEGA32
#ifdef  AMIT_ATMEGA32
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "DEFINE PLATFORM"
#endif

#define BUZZER_PORT (PORTD)
#define BUZZER_PIN  (PD4)
#define BUZZER_DDR	(DDRD)

extern void BUZZER_ON (unsigned int u32ButtNum);

extern void BUZZER_OFF (unsigned int u32ButtNum);

extern void BUZZER_TOGGLE (unsigned int u32ButtNum);




#endif /* AMIT_BUZZER_RELAY_H_ */