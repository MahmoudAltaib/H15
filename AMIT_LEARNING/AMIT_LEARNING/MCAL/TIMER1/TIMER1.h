/*
 * TIMER1.h
 *
 * Created: 5/29/2019 7:59:28 PM
 *  Author: A.Elkady
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#define ATMEGA32

#ifdef ATMEGA32

#include "AMIT_SCHEMATIC.h"

#define TCCR_1A (*(volatile unsigned int *)(0x4f))
#define TCCR_1B (*(volatile unsigned int *)(0x4e))
#define TCNT_1H (*(volatile unsigned int *)(0x4d))
#define TCNT_1L (*(volatile unsigned int *)(0x4c))
#define TOCR1A_1L (*(volatile unsigned int *)(0x4a))
#define TOCR1A_1H (*(volatile unsigned int *)(0x4b))
#define TOCR1B_1L (*(volatile unsigned int *)(0x48))
#define TOCR1B_1H (*(volatile unsigned int *)(0x49))
#define TCIFR (*(volatile unsigned int *)(0x58))
#define TCIMSK (*(volatile unsigned int *)(0x59))

extern void T1_PWM_INIT(void);
extern void T1_PWM_DEINIT(void);

extern void T1_PWM_DUTY_CYCLE(uint32_t u32Duty_cycle_A , uint32_t u32Duty_cycle_B);

#endif

#endif /* TIMER1_H_ */