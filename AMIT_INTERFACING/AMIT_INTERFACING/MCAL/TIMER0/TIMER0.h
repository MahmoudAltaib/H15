/*
 * TIMER0.h
 *
 * Created: 5/25/2019 10:27:28 AM
 *  Author: hp
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#define ATMEGA32
#ifdef ATMEGA32
#define AMIT_ATMEGA
#ifdef AMIT_ATMEGA
#include "avr/sfr_defs.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#else
#error "Platform is not defined"
#endif

/*#define T0_CR (*((volatile unsigned int *)(0x53)))
#define T0_CNT (*((volatile unsigned int *)(0x52)))
#define T0_INTF (*((volatile unsigned int *)(0x58)))
#define T0_INTMSK (*((volatile unsigned int *)(0x59)))
*/


#define T0_CR (*((volatile unsigned int *)(TCCR0)))
#define T0_CNT (*((volatile unsigned int *)(TCNT0)))
#define T0_INTF (*((volatile unsigned int *)(TIFR)))
#define T0_INTMSK (*((volatile unsigned int *)(TIMSK)))
extern void T0_Delay_ms(unsigned int i32_delay);
#endif
#endif /* TIMER0_H_ */