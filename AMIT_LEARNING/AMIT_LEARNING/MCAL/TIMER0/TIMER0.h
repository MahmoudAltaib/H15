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

	#include "AMIT_SCHEMATIC.h"

	#define TCCR_0 (*(volatile unsigned int *)(0x53))
	#define TCNT_0 (*(volatile unsigned int *)(0x52))
	#define OCR_0 (*(volatile unsigned int *)(0x5c))
	#define TCIFR (*(volatile unsigned int *)(0x58))
	#define TCIMSK (*(volatile unsigned int *)(0x59))
	
	extern void TIMER0_SET_PRESCALE_64();
	extern void TIMER0_ENABLE_IOVERFLOW();
	extern void TIMER0_DISABLE_IOVERFLOW();
	
	extern void TIMER0_STOP();

	extern void T0_DELAY_ms(uint32_t u32Delay_time);
	extern void T0_INIT(void);
	extern void T0_DEINIT(void);

#endif

#endif /* TIMER0_H_ */