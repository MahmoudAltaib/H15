/*
 * AMIT_LEARNING.c
 *
 * Created: 5/12/2019 12:23:09 AM
 * Author : A.Elkady
 */ 
#include "AMIT_SCHEMATIC.h"

uint8_t gu8Segment7_number1 = 0;
uint8_t gu8Segment7_number2 = 0;

volatile uint8_t gu8ID_right = 0;
volatile uint8_t gu8Password_right = 0;

volatile uint8_t gu8T1_flag = 0;

const unsigned char gu8Key_pad[4][4] = {{'o','s','B','A'},
										{'#','9','6','3'},
										{'0','8','5','2'},
										{'*','7','4','1'}};
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
	/*Pin_mode(SEGMENT1_ENABLE_PORT , SEGMENT1_ENABLE_DDR , SEGMENT1_ENABLE_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT2_ENABLE_PORT , SEGMENT2_ENABLE_DDR , SEGMENT2_ENABLE_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT_A_PORT , SEGMENT_A_DDR , SEGMENT_A_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT_B_PORT , SEGMENT_B_DDR , SEGMENT_B_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT_C_PORT , SEGMENT_C_DDR , SEGMENT_C_PIN_NUMBER , OUTPUT);
	Pin_mode(SEGMENT_D_PORT , SEGMENT_D_DDR , SEGMENT_D_PIN_NUMBER , OUTPUT);
	*/
	// INPUTS

		// BUTTONS
		
		
	/*Pin_mode(BUTTON0_PORT , BUTTON0_DDR , BUTTON0_PIN_NUMBER , INPUT);
	Pin_mode(BUTTON1_PORT , BUTTON1_DDR , BUTTON1_PIN_NUMBER , INPUT);*/
	
	Pin_mode(BUTTON2_PORT , BUTTON2_DDR , BUTTON2_PIN_NUMBER , INPUT);
		// ADC
	Pin_reset(ADC0_DDR, ADC0_PIN_NUMBER); //No pull up resistors
	Pin_reset(ADC1_DDR, ADC1_PIN_NUMBER);
	// Setting initial states
	
	LED_OFF(LED1);
	LED_OFF(LED2);
	LED_OFF(LED3);
	BUZZER_OFF();
	RELAY_OFF();
	/*SEGMENT_RESET();*/
	LCD_INIT();
	USART_INIT();
	
	while (1)
	{
		
		/*if (gu8ID_right != 0 && gu8Password_right != 0)
		{
			AMIT_BT_TEST();
		} 
		else
		{
			KEYPAD_WITH_LCD();
		}*/
		AMIT_BT_TEST();
		
	}
}


