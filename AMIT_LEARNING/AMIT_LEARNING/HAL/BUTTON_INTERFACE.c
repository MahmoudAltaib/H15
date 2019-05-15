/*
 * BUTTON_INTERFACE.c
 *
 * Created: 5/12/2019 2:01:32 PM
 *  Author: A.Elkady
 */ 

#include "BUTTON_INTERFACE.h"

extern void BUTTON0_READ(uint8_t *pu8Reading)
{
	uint8_t u8Temp = 0;
	uint8_t u8Count = 0;
	uint8_t u8Num_of_correct_checks = 0;
	
	Pin_read(BUTTON0_PIN , BUTTON0_PIN_NUMBER , &u8Temp);
	
	if (u8Temp != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_CHECKS ; u8Count ++)
		{
			Pin_read(BUTTON0_PIN , BUTTON0_PIN_NUMBER , &u8Temp);
			
			if (u8Temp != 0)
			{
				u8Num_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Num_of_correct_checks == NUMBER_OF_CHECKS)
		{
			*pu8Reading = u8Temp;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
	
}

extern void BUTTON1_READ(uint8_t *pu8Reading)
{
	uint8_t u8Temp = 0;
	uint8_t u8Count = 0;
	uint8_t u8Num_of_correct_checks = 0;
	
	Pin_read(BUTTON1_PIN , BUTTON1_PIN_NUMBER , &u8Temp);
	
	if (u8Temp != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_CHECKS ; u8Count ++)
		{
			Pin_read(BUTTON1_PIN , BUTTON1_PIN_NUMBER , &u8Temp);
			
			if (u8Temp != 0)
			{
				u8Num_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Num_of_correct_checks == NUMBER_OF_CHECKS)
		{
			*pu8Reading = u8Temp;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
}

extern void BUTTON2_READ(uint8_t *pu8Reading)
{
	uint8_t u8Temp = 0;
	uint8_t u8Count = 0;
	uint8_t u8Num_of_correct_checks = 0;
	
	Pin_read(BUTTON2_PIN , BUTTON2_PIN_NUMBER , &u8Temp);
	
	if (u8Temp != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_CHECKS ; u8Count ++)
		{
			Pin_read(BUTTON2_PIN , BUTTON2_PIN_NUMBER , &u8Temp);
			
			if (u8Temp != 0)
			{
				u8Num_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Num_of_correct_checks == NUMBER_OF_CHECKS)
		{
			*pu8Reading = u8Temp;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
}