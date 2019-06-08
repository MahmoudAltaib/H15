/*
 * CFile1.c
 *
 * Created: 18-May-19 11:49:26 AM
 *  Author: acer
 */ 

#include "AMIT_BUZZER_RELAY.h"



extern void BUZZER_ON(unsigned int u32ButtNum)
{
	unsigned int u32BuzzOutput = 0;
	Button_Read(u32ButtNum , &u32BuzzOutput);
	if (u32BuzzOutput > 0)
	{
		DIO_PINOUT(BUZZER_DDR , BUZZER_PIN);
		DIO_WRITEPIN(BUZZER_PORT , BUZZER_PIN , 1);
	}
	
}

extern void BUZZER_OFF(unsigned int u32ButtNum)
{
	unsigned int u32BuzzOutput = 0;
	Button_Read(u32ButtNum , &u32BuzzOutput);
	if (u32BuzzOutput == 3)
	{
		DIO_PINOUT(BUZZER_DDR , BUZZER_PIN);
		DIO_WRITEPIN(BUZZER_PORT , BUZZER_PIN , 0);
	}
}

extern void BUZZER_TOGGLE(unsigned int u32ButtNum)
{
	
}
