/*
 * TIMER1.c
 *
 * Created: 5/29/2019 7:59:16 PM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "TIMER1/TIMER1.h"


/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/
extern void T1_PWM_INIT(void)
{
	TCCR_1A = 0x00 ;
	TCCR_1B = 0x00 ;
	
	TCCR_1A |= TIMER1_CR_A_INIT_VALUE ;
	TCCR_1B |= TIMER1_CR_B_INIT_VALUE ;
	
	TOCR1A_1L = 0x00;
	TOCR1B_1L = 0x00;
}

extern void T1_PWM_DEINIT(void)
{
	TCCR_1A = 0x00;
	TCCR_1B = 0x00;
	
	TOCR1A_1L = 0x00;
	TOCR1B_1L = 0x00;
}

extern void T1_PWM_DUTY_CYCLE(uint32_t u32Duty_cycle_A , uint32_t u32Duty_cycle_B)
{
	TOCR1A_1L = 0x00 ;
	TOCR1B_1L = 0x00 ;
	
	if (u32Duty_cycle_A >= 1 && u32Duty_cycle_A <= 100)
	{
		TOCR1A_1L |= ((u32Duty_cycle_A * 256) / 100) -1 ;
	}
	else
	{
		TOCR1A_1L = 0x00 ;
	}
	
	if (u32Duty_cycle_B >= 1 && u32Duty_cycle_B <= 100)
	{
		TOCR1B_1L |= ((u32Duty_cycle_B * 256) / 100) -1 ;
	}
	else
	{
		TOCR1B_1L = 0x00 ;
	}
}
