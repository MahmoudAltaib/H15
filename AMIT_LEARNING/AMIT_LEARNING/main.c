/*
 * AMIT_LEARNING.c
 *
 * Created: 5/12/2019 12:23:09 AM
 * Author : A.Elkady
 */ 
#include "GPIO/GPIO.h"

#include "HAL/SEGMENT7_INTERFACE.h"
#include "HAL/AMIT_SCHEMATIC.h"
#include "HAL/LEDS_INTERFACE.h"
#include "HAL/BUZZER_INTERFACE.h"
#include "HAL/RELAY_INTERFACE.h"
#include "HAL/BUTTON_INTERFACE.h"

int main(void)
{	
	uint8_t u8Reading = 0;
	uint8_t u8Segment7_number = 0;
	uint8_t u8Button0_hold = 0 ;
	uint8_t u8Button1_hold = 0 ;
	uint8_t u8Button2_hold = 0 ;
	
	// OUTPUTS
	Pin_mode(LED1_PORT , LED1_DDR , LED1_PIN_NUMBER , OUTPUT);
	Pin_mode(LED2_PORT , LED2_DDR , LED2_PIN_NUMBER , OUTPUT);
	Pin_mode(LED3_PORT , LED3_DDR , LED3_PIN_NUMBER , OUTPUT);
	Pin_mode(BUZZER_PORT , BUZZER_DDR , BUZZER_PIN_NUMBER , OUTPUT);
	Pin_mode(RELAY_PORT , RELAY_DDR , RELAY_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT1_ENABLE_PORT , SEGMENT1_ENABLE_DDR , SEGMENT1_ENABLE_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT2_ENABLE_PORT , SEGMENT2_ENABLE_DDR , SEGMENT2_ENABLE_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT_A_PORT , SEGMENT_A_DDR , SEGMENT_A_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT_B_PORT , SEGMENT_B_DDR , SEGMENT_B_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT_C_PORT , SEGMENT_C_DDR , SEGMENT_C_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT_D_PORT , SEGMENT_D_DDR , SEGMENT_D_PIN_NUMBER , OUTPUT);
	
	// INPUTS
	Pin_mode(BUTTON0_PORT , BUTTON0_DDR , BUTTON0_PIN_NUMBER , INPUT);
	Pin_mode(BUTTON1_PORT , BUTTON1_DDR , BUTTON1_PIN_NUMBER , INPUT);
	Pin_mode(BUTTON2_PORT , BUTTON2_DDR , BUTTON2_PIN_NUMBER , INPUT);
	
	// Setting initial states
	SEGMENT_ON(SEGMENT1);
	SEGMENT_ON(SEGMENT2);
		
	LED_OFF(LED1);
	LED_OFF(LED2);
	LED_OFF(LED3);
	BUZZER_OFF();
	RELAY_OFF();
	
	SEGMENT_RESET();
	
    while (1) 
    {
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
			
				if (u8Segment7_number == 9)
				{
					u8Segment7_number = 0 ;
					SEGMENT_SHOW_NUMBER(0);
					SEGMENT_LEDS_FLASH();
				}
				else
				{
					u8Segment7_number ++ ;
					SEGMENT_SHOW_NUMBER(u8Segment7_number);
				}
				
				u8Button0_hold ++ ;
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
		BUTTON0_READ(&u8Reading);
		
		if (u8Reading == 0)
		{
			u8Button0_hold = 0;
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
			
				if (u8Segment7_number == 0)
				{
					SEGMENT_LEDS_FLASH();
				}
				else
				{
					u8Segment7_number -- ;
					SEGMENT_SHOW_NUMBER(u8Segment7_number);
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
				
				u8Segment7_number = 0;
				SEGMENT_SHOW_NUMBER(u8Segment7_number);
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
}

