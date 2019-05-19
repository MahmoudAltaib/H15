/*
 * AMIT_LEARNING.c
 *
 * Created: 5/12/2019 12:23:09 AM
 * Author : A.Elkady
 */ 
#include "AMIT_SCHEMATIC.h"

uint8_t u8Segment7_number1 = 0;
uint8_t u8Segment7_number2 = 0;

int main(void)
{	
	// OUTPUTS
	
		// LEDS
		Pin_mode(LED1_PORT , LED1_DDR , LED1_PIN_NUMBER , OUTPUT);
		Pin_mode(LED2_PORT , LED2_DDR , LED2_PIN_NUMBER , OUTPUT);
		Pin_mode(LED3_PORT , LED3_DDR , LED3_PIN_NUMBER , OUTPUT);
		
		//BUZZER
		Pin_mode(BUZZER_PORT , BUZZER_DDR , BUZZER_PIN_NUMBER , OUTPUT);
		
		//RELAY
		Pin_mode(RELAY_PORT , RELAY_DDR , RELAY_PIN_NUMBER , OUTPUT);
		
		//7SEGMENT
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
	
	LED_OFF(LED1);
	LED_OFF(LED2);
	LED_OFF(LED3);
	BUZZER_OFF();
	RELAY_OFF();

	SEGMENT_RESET();
	
	LCD_INIT();
		
	unsigned char u8Statement1[16] = {"Hello World !!.."};
		uint8_t u8Button0_reading = 0;
		uint8_t u8Button1_reading = 0;
		uint8_t u8Button2_reading = 0;
		
	while (1)
	{
		LCD_DATA_STRING(u8Statement1 , 16);
		do 
		{
			BUTTON0_READ(&u8Button0_reading);
			BUTTON1_READ(&u8Button1_reading);
			BUTTON2_READ(&u8Button2_reading);
			
		} while ((u8Button0_reading == 0) & (u8Button1_reading == 0) & (u8Button2_reading == 0) );
	}
}


