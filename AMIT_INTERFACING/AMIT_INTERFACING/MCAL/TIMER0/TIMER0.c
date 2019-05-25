/*
 * TIMER0.c
 *
 * Created: 5/25/2019 10:27:07 AM
 *  Author: hp
 */ 
#include "TIMER0.h"

static void T0_INIT(void);
volatile static unsigned char gu8_msFlag = 0; 

extern void T0_Delay_ms(unsigned int i32_delay)
{   
	T0_INIT();
	
	while (i32_delay != 0)
	{   
		
		while (gu8_msFlag == 0);
			i32_delay--;
			gu8_msFlag = 0;
		
		
	}
	
}

static void T0_INIT(void)
{   gu8_msFlag = 0;
	T0_CR = 0x03;
    T0_CNT = 0x06;
	T0_INTMSK |= (1<<(TOIE0));
	
	sei();

}

ISR(TIMER0_OVF_vect)
{
	gu8_msFlag++;
	T0_CNT = 0x06;
	
}