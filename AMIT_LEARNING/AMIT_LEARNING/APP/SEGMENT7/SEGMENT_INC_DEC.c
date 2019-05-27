/*
 * SEGMENT_INC_DEC.c
 *
 * Created: 5/17/2019 10:43:22 AM
 *  Author: A.Elkady
 */ 

#include "SEGMENT_INC_DEC.h"

extern uint8_t gu8Segment7_number1 ;
extern uint8_t gu8Segment7_number2 ;

static uint8_t u8Reading = 0 ;
static uint8_t u8Button0_hold = 0 ;
static uint8_t u8Button1_hold = 0 ;
static uint8_t u8Button2_hold = 0 ;

extern void SEGMENT_INC_DEC()
{
	SHOW_TWO_NUMBERS(gu8Segment7_number1 , gu8Segment7_number2);

	BUTTON0_READ(&u8Reading);
	
	if (u8Button0_hold == 0)
	{
		if (u8Reading != 0)
		{
			LED_ON(LED1);
			LED_ON(LED2);
			LED_ON(LED3);
			BUZZER_ON();
			RELAY_ON();
			_delay_ms(30);
			
			if (gu8Segment7_number1 == 9)
			{
				if (gu8Segment7_number2 != 9)
				{
					gu8Segment7_number1 = 0 ;
					gu8Segment7_number2 ++ ;
					SHOW_TWO_NUMBERS(gu8Segment7_number1 , gu8Segment7_number2);
				}
				else
				{
					gu8Segment7_number1 = 0;
					gu8Segment7_number2 = 0;
					SEGMENT_LEDS_FLASH();
				}
				
			}
			else
			{
				gu8Segment7_number1 ++ ;
				SHOW_TWO_NUMBERS(gu8Segment7_number1 , gu8Segment7_number2);
			}
			
			u8Button0_hold ++ ;
		}
		else
		{
			
		}
	}
	
	else
	{
		
	}
	
	// Checking if the button is released
	BUTTON0_READ(&u8Reading);
	
	if (u8Reading == 0)
	{
		u8Button0_hold = 0;
		LED_OFF(LED1);
		LED_OFF(LED2);
		LED_OFF(LED3);
		BUZZER_OFF();
		RELAY_OFF();
	}
	else
	{
		
	}
	
	BUTTON1_READ(&u8Reading);
	
	if (u8Button1_hold == 0)
	{
		if (u8Reading != 0)
		{
			LED_ON(LED1);
			LED_ON(LED2);
			LED_ON(LED3);
			BUZZER_ON();
			RELAY_ON();
			_delay_ms(30);
			
			if (gu8Segment7_number1 == 0)
			{
				if (gu8Segment7_number2 == 0)
				{
					gu8Segment7_number1 = 0;
					gu8Segment7_number2 = 0;
					SHOW_TWO_NUMBERS(gu8Segment7_number1 , gu8Segment7_number2);
					SEGMENT_LEDS_FLASH();
				}
				else
				{
					gu8Segment7_number1 = 9;
					gu8Segment7_number2 -- ;
					SHOW_TWO_NUMBERS(gu8Segment7_number1 , gu8Segment7_number2);
				}
				
			}
			else
			{
				gu8Segment7_number1 -- ;
				SHOW_TWO_NUMBERS(gu8Segment7_number1 , gu8Segment7_number2);
			}
			u8Button1_hold ++;
		}
		else
		{
			LED_OFF(LED1);
			LED_OFF(LED2);
			LED_OFF(LED3);
			BUZZER_OFF();
			RELAY_OFF();
		}
	}
	else
	{
		
	}
	
	// Checking if the button is released
	BUTTON1_READ(&u8Reading);
	
	if (u8Reading == 0)
	{
		u8Button1_hold = 0;
	}
	else
	{
		
	}
	
	BUTTON2_READ(&u8Reading);
	
	if(u8Button2_hold == 0)
	{
		if (u8Reading != 0)
		{
			LED_ON(LED1);
			LED_ON(LED2);
			LED_ON(LED3);
			BUZZER_ON();
			RELAY_ON();
			_delay_ms(30);
			
			gu8Segment7_number1 = 0;
			gu8Segment7_number2 = 0;
			SHOW_TWO_NUMBERS(gu8Segment7_number1 , gu8Segment7_number2);
			SEGMENT_LEDS_FLASH();
			u8Button2_hold ++;
		}
		else
		{
			LED_OFF(LED1);
			LED_OFF(LED2);
			LED_OFF(LED3);
			BUZZER_OFF();
			RELAY_OFF();
		}
	}
	else
	{
		
	}
	
	// Checking if the button is released
	BUTTON2_READ(&u8Reading);
	
	if (u8Reading == 0)
	{
		u8Button2_hold = 0;
	}
	else
	{
		
	}
}
