/*
 * TIMER0c.c
 *
 * Created: 5/25/2019 10:42:31 AM
 *  Author: A.Elkady
 */ 

#include "TIMER0/TIMER0.h"

volatile static uint8_t gu8Flage = 0;
extern void T0_DELAY_1ms(void)
{
	
}

extern void T0_DELAY_3ms(void)
{
	
}

extern void T0_INIT(void)
{
	/*TIMER0_COUNT = 6 ;  // 1+255-250
	TIMER0_CR = 0x03 ; // 64 prescalar
	
	TIMER0_IMS |= (1 << TOIE0);
	
	sei();*/
}


ISR(TIMER0_OVF_vect)
{
	
}