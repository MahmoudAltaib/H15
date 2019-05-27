/*
 * LEDS_INTERFACE.c
 *
 * Created: 5/12/2019 2:11:02 AM
 *  Author: A.Elkady
 */ 

#include "LEDS_INTERFACE.h"

extern void LED_ON(uint8_t u8LED_Number)
{
	if (u8LED_Number == LED1)
	{
		Pin_set(LED1_PORT , LED1_PIN_NUMBER);
	}
	else if (u8LED_Number == LED2)
	{
		Pin_set(LED2_PORT , LED2_PIN_NUMBER);
	}
	else if (u8LED_Number == LED3)
	{
		Pin_set(LED3_PORT , LED3_PIN_NUMBER);
	}
	else
	{
		
	}
}

extern void LED_OFF(uint8_t u8LED_Number)
{
	if (u8LED_Number == LED1)
	{
		Pin_reset(LED1_PORT , LED1_PIN_NUMBER);
	}
	else if (u8LED_Number == LED2)
	{
		Pin_reset(LED2_PORT , LED2_PIN_NUMBER);
	}
	else if (u8LED_Number == LED3)
	{
		Pin_reset(LED3_PORT , LED3_PIN_NUMBER);
	}
	else
	{
		
	}
}

extern void LED_FLASH(uint8_t u8LED_Number)
{
	if (u8LED_Number == LED1)
	{
		LED_ON(LED1);
		_delay_ms(150);
		LED_OFF(LED1);
		_delay_ms(150);
		
		LED_ON(LED1);
		_delay_ms(150);
		LED_OFF(LED1);
		_delay_ms(150);
		
		LED_ON(LED1);
		_delay_ms(150);
		LED_OFF(LED1);
		_delay_ms(150);
	}
	else if (u8LED_Number == LED2)
	{
		LED_ON(LED2);
		_delay_ms(150);
		LED_OFF(LED2);
		_delay_ms(150);
		
		LED_ON(LED2);
		_delay_ms(150);
		LED_OFF(LED2);
		_delay_ms(150);
		
		LED_ON(LED2);
		_delay_ms(150);
		LED_OFF(LED2);
		_delay_ms(150);
	}
	else if (u8LED_Number == LED3)
	{
		LED_ON(LED3);
		_delay_ms(150);
		LED_OFF(LED3);
		_delay_ms(150);
		
		LED_ON(LED3);
		_delay_ms(150);
		LED_OFF(LED3);
		_delay_ms(150);
		
		LED_ON(LED3);
		_delay_ms(150);
		LED_OFF(LED3);
		_delay_ms(150);
	}
	else
	{
		
	}
}

extern void LEDS_FLASH()
{
	uint8_t u8Count = 0 ;
	
	for (u8Count = 0 ; u8Count < NUMBER_OF_LEDS_FLICKERS ; u8Count ++)
	{
		LED_ON(LED1);
		LED_ON(LED2);
		LED_ON(LED3);
		_delay_ms(LEDS_FLASHING_PERIOD);
		LED_OFF(LED1);
		LED_OFF(LED2);
		LED_OFF(LED3);
		_delay_ms(LEDS_FLASHING_PERIOD);	
	}
}