/*
 * SEGMENT7_INTERFACE.c
 *
 * Created: 5/12/2019 4:39:38 PM
 *  Author: A.Elkady
 */ 

#include "SEGMENT7_INTERFACE.h"


extern void SEGMENT_ON(uint8_t u8Segment_number)
{
	if (u8Segment_number == SEGMENT1)
	{
	Pin_set(SEGMENT1_ENABLE_PORT , SEGMENT1_ENABLE_PIN_NUMBER);
	}
	else if (u8Segment_number == SEGMENT2)
	{
	Pin_set(SEGMENT2_ENABLE_PORT , SEGMENT2_ENABLE_PIN_NUMBER);
	}
}

extern void SEGMENT_OFF(uint8_t u8Segment_number)
{
	if (u8Segment_number == SEGMENT1)
	{
		Pin_reset(SEGMENT1_ENABLE_PORT , SEGMENT1_ENABLE_PIN_NUMBER);
	}
	else if (u8Segment_number == SEGMENT2)
	{
		Pin_reset(SEGMENT2_ENABLE_PORT , SEGMENT2_ENABLE_PIN_NUMBER);
	}
}

extern void BCD_PIN_SET(uint8_t u8Pin_number)
{
	if (u8Pin_number == BCD_A)
	{
		Pin_set(SEGMENT_A_PORT , SEGMENT_A_PIN_NUMBER);
	}
	else if (u8Pin_number == BCD_B)
	{
		Pin_set(SEGMENT_B_PORT , SEGMENT_B_PIN_NUMBER);
	}
	else if (u8Pin_number == BCD_C)
	{
		Pin_set(SEGMENT_C_PORT , SEGMENT_C_PIN_NUMBER);
	}
	else if (u8Pin_number == BCD_D)
	{
		Pin_set(SEGMENT_D_PORT , SEGMENT_D_PIN_NUMBER);
	}
	else
	{
		
	}
}

extern void BCD_PIN_RESET(uint8_t u8Pin_number)
{
	if (u8Pin_number == BCD_A)
	{
	Pin_reset(SEGMENT_A_PORT , SEGMENT_A_PIN_NUMBER);
	}
	else if (u8Pin_number == BCD_B)
	{
	Pin_reset(SEGMENT_B_PORT , SEGMENT_B_PIN_NUMBER);
	}
	else if (u8Pin_number == BCD_C)
	{
	Pin_reset(SEGMENT_C_PORT , SEGMENT_C_PIN_NUMBER);
	}
	else if (u8Pin_number == BCD_D)
	{
	Pin_reset(SEGMENT_D_PORT , SEGMENT_D_PIN_NUMBER);
	}
	else
	{
		
	}
}

extern void SEGMENT_RESET()
{
	BCD_PIN_RESET(BCD_A);
	BCD_PIN_RESET(BCD_B);
	BCD_PIN_RESET(BCD_C);
	BCD_PIN_RESET(BCD_D);
}



extern void SEGMENT_SHOW_NUMBER(uint8_t u8Segment7_number1)
{
	uint8_t u8Temp = 0;
	
	u8Temp = u8Segment7_number1 ;
	
	SEGMENT_RESET();
	*((volatile unsigned int *)(SEGMENT_A_PORT)) |= (u8Temp << SEGMENT_A_PIN_NUMBER);
	_delay_ms(1);
}

extern void SHOW_TWO_NUMBERS(uint8_t u8Num1 , uint8_t u8Num2)
{
	SEGMENT_ON(SEGMENT1);
	SEGMENT_SHOW_NUMBER(u8Num1);
	SEGMENT_OFF(SEGMENT1);
	
	SEGMENT_ON(SEGMENT2);
	SEGMENT_SHOW_NUMBER(u8Num2);
	SEGMENT_OFF(SEGMENT2);
	
}

extern void SEGMENT_FLASH()
{
	uint8_t u8Count = 0;
	
	for (u8Count = 0 ; u8Count < NUMBER_OF_FLASHES ; u8Count ++)
	{
		SEGMENT_OFF(SEGMENT1);
		SEGMENT_OFF(SEGMENT2);
		_delay_ms(150);
		SEGMENT_ON(SEGMENT1);
		SEGMENT_ON(SEGMENT2);
		_delay_ms(150);	
	}
}

extern void SEGMENT_LEDS_FLASH()
{
	uint8_t u8Count = 0;
	
	for (u8Count = 0 ; u8Count < NUMBER_OF_FLASHES ; u8Count ++)
	{
		LED_OFF(LED1);
		LED_OFF(LED2);
		LED_OFF(LED3);
		SEGMENT_OFF(SEGMENT1);
		SEGMENT_OFF(SEGMENT2);
		_delay_ms(150);
		LED_ON(LED1);
		LED_ON(LED2);
		LED_ON(LED3);
		SEGMENT_ON(SEGMENT1);
		SEGMENT_ON(SEGMENT2);
		_delay_ms(150);	
	}
	LED_OFF(LED1);
	LED_OFF(LED2);
	LED_OFF(LED3);
}

