/*
 * BUZZER_ON_OFF.c
 *
 * Created: 5/17/2019 10:44:30 AM
 *  Author: A.Elkady
 */ 


#include "BUZZER_ON_OFF.h"

static uint8_t u8Buzzer_state = 0;
static uint8_t u8Button_hold = 0;
static uint8_t u8Falling_edge_wait = 0;

extern void BUZZER_ON_OFF()
{
	
	Pin_mode(BUTTON0_PORT , BUTTON0_DDR , BUTTON0_PIN_NUMBER , INPUT);
	Pin_mode(BUZZER_PORT , BUZZER_DDR , BUZZER_PIN_NUMBER , OUTPUT);
	Pin_mode(LED1_PORT , LED1_DDR , LED1_PIN_NUMBER , OUTPUT);

	uint8_t u8Reading = 0;
	
	BUTTON0_READ(&u8Reading);
	
	if (u8Button_hold == 0)
	{
		if (u8Reading != 0)
		{
			LED_OFF(LED1);
			
			if (u8Buzzer_state == OFF)
			{
				BUZZER_ON();
				u8Buzzer_state = ON;
			}
			else if (u8Buzzer_state == ON)
			{
				BUZZER_OFF();
				u8Buzzer_state = OFF;
			}
			else
			{
			
			}
			
			u8Button_hold ++ ;
			u8Falling_edge_wait ++ ;
		}
	
		else  // This means that the reading of the button became zero .
		{
			if (u8Falling_edge_wait != 0)
			{
				LED_ON(LED1);
				u8Falling_edge_wait = 0;
			}
		}
	}
	else // This means that the button is held at this time (u8Button_hold = 1)
	{
		
	}
	
	
	BUTTON0_READ(&u8Reading);
	
	if (u8Reading == 0)
	{
		u8Button_hold = 0;
	}
	else
	{
		
	}
	
	
	
	
}