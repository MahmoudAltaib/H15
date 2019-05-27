/*
 * TIMER0.h
 *
 * Created: 5/25/2019 10:42:41 AM
 *  Author: A.Elkady
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#define ATMEGA32

#ifdef ATMEGA32

	#include "avr/io.h"
	#include "avr/interrupt.h"

	#define TIMER0_CR (*(volatile unsigned int *)(0x33))
	#define TIMER0_COUNT TCNT0
	#define TIMER0_INT_F TIFR
	#define TIMER0_IMS TIMSK
	
	extern void T0_DELAY_1ms(void);
	extern void T0_DELAY_3ms(void);
	extern void T0_INIT(void);

#endif

#endif /* TIMER0_H_ */