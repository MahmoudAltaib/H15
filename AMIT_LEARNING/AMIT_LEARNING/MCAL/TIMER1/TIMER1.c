/*
 * TIMER1.c
 *
 * Created: 5/29/2019 7:59:16 PM
 *  Author: A.Elkady
 */ 


#include "TIMER1/TIMER1.h"

extern volatile uint8_t gu8T1_flag ;

extern void T1_PWM_INIT(void)
{
	TCCR_1A = 0x00 ;
	TCCR_1B = 0x00 ;
	
	TCCR_1A |= 0xa1 ;
	TCCR_1B |= 0x0a ;
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
	
	if (u32Duty_cycle_A >= 1 )
	{
		TOCR1A_1L |= ((u32Duty_cycle_A * 256) / 100) -1 ;
	}
	else
	{
		TOCR1A_1L = 0x00 ;
	}
	if (u32Duty_cycle_B >= 1 )
	{
		TOCR1B_1L |= ((u32Duty_cycle_B * 256) / 100) -1 ;
	}
	else
	{
		TOCR1B_1L = 0x00 ;
	}
}
