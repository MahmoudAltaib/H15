/*
 * TIMER1.h
 *
 * Created: 5/29/2019 7:59:28 PM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef TIMER1_H_
#define TIMER1_H_

	/************************************************************************/
	/*                  Start of platform definition                        */
	/************************************************************************/
	#define ATMEGA32
	/************************************************************************/
	/*                  End of platform definition                          */
	/************************************************************************/

	#ifdef ATMEGA32

		/************************************************************************/
		/*                               Inclusions                             */
		/************************************************************************/
		#include "ELKADY_SCHEMATIC.h"

		/************************************************************************/
		/*                    Definition of Timer1 registers                    */
		/************************************************************************/
		#define TCCR_1A (*(volatile unsigned char *)(0x4f))
		#define TCCR_1B (*(volatile unsigned char *)(0x4e))
		#define TCNT_1H (*(volatile unsigned char *)(0x4d))
		#define TCNT_1L (*(volatile unsigned char *)(0x4c))
		#define TOCR1A_1L (*(volatile unsigned char *)(0x4a))
		#define TOCR1A_1H (*(volatile unsigned char *)(0x4b))
		#define TOCR1B_1L (*(volatile unsigned char *)(0x48))
		#define TOCR1B_1H (*(volatile unsigned char *)(0x49))
		#define TCIFR (*(volatile unsigned char *)(0x58))
		#define TCIMSK (*(volatile unsigned char *)(0x59))
		
		// TCCRA
		#define TIMER1_WGM10 0
		#define TIMER1_WGM11 1
		#define TIMER1_FOC1B 2
		#define TIMER1_FOC1A 3
		#define TIMER1_COM1B0 4
		#define TIMER1_COM1B1 5
		#define TIMER1_COM1A0 6
		#define TIMER1_COM1A1 7
		//TCCRB
		#define TIMER1_CS10 0
		#define TIMER1_CS11 1
		#define TIMER1_CS12 2
		#define TIMER1_WGM12 3
		#define TIMER1_WGM13 4
		#define TIMER1_ICES1 6
		#define TIMER1_ICNC1 7
		//TCIF
		#define TIMER1_OV 2
		#define TIMER1_OCF1B 3
		#define TIMER1_OCF1A 4
		#define TIMER1_FLAG1 5
		//TCIMSK
		#define TIMER1_OIE 2
		#define TIMER1_OCIE1B 3
		#define TIMER1_OCIE1A 4
		#define TIMER1_ICIE 5
	
		/************************************************************************/
		/*                   Timer1 registers values                            */
		/************************************************************************/				
		#define TIMER1_CR_A_INIT_VALUE ((1 << TIMER1_COM1A1) | (1 << TIMER1_COM1B1) | (1 << TIMER1_WGM10))
		#define TIMER1_CR_B_INIT_VALUE ((1 << TIMER1_WGM12) | (1 << TIMER1_CS11))
		
		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/		
		extern void T1_PWM_INIT(void);
		extern void T1_PWM_DEINIT(void);
		extern void T1_PWM_DUTY_CYCLE(uint32_t u32Duty_cycle_A , uint32_t u32Duty_cycle_B);

	#else
	
		#error "DEFINE PLATFORM"

	#endif

#endif /* TIMER1_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/