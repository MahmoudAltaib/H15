/*
 * TIMER0c.c
 *
 * Created: 5/25/2019 10:42:31 AM
 *  Author: A.Elkady
 */ 

#include "TIMER0/TIMER0.h"

volatile static uint8_t gu8Flag = 0;

extern void T0_DELAY_ms(uint32_t u32Delay_time)
{
	while (u32Delay_time != 0)
	{
		T0_INIT();
		
		while (gu8Flag == 0);
		
		u32Delay_time -- ;
		
		T0_DEINIT();
	}
}


extern void T0_INIT(void)
{
	gu8Flag = 0;
	
	TCNT_0 = 68 ;  // 256-188 (number of maximum counts ) - ( number of needed counts)
	TIMER0_SET_PRESCALE_64();
	TIMER0_ENABLE_IOVERFLOW();
	
	sei();  // Enable global interrupt
}

extern void T0_DEINIT(void)
{
	gu8Flag = 0;
	
	TCNT_0 = 0 ;  // Reset counter
	TIMER0_STOP();
	TIMER0_DISABLE_IOVERFLOW();
	
	cli();  // Disable global interrupt 
}

extern void TIMER0_SET_PRESCALE_64()
{
	TCCR_0 &= !(1<<0);  // Reset CS00
	TCCR_0 &= !(1<<1);  // Reset CS01
	TCCR_0 &= !(1<<2);  // Reset CS02
	
	TCCR_0 |= 0x03 ;
}

extern void TIMER0_STOP()
{
	TCCR_0 = 0x00;
}

extern void TIMER0_DISABLE_IOVERFLOW()
{
	TCIMSK &= ( 1<< TOIE0);	
}

extern void TIMER0_ENABLE_IOVERFLOW()
{
	TCIMSK |= (1 << TOIE0);
}

ISR(TIMER0_OVF_vect)
{
	gu8Flag ++ ;
}