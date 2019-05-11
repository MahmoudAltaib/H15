/*
 * AMIT_INTERFACING.c
 *
 * Created: 5/11/2019 1:49:00 PM
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#define AMIT_ATMEGA
#include "MCAL/DIO/PORT_DIO.h"
#include <avr/io.h>
#include <inttypes.h>
#include "HAL/AMIT_SCHEMATIC.h"

int main(void)
{   uint8_t number = 0;
	unsigned int B_0 = 0;
	unsigned int B_1 = 0;
	unsigned int B_2 = 0;
	
    /* Replace with your application code */
    while (1) 
    {	
		SEGMENT_DISPLAY_NUM(number);
		
		READ_BUTTON(AMIT_BUTTON0,&B_0);
		READ_BUTTON(AMIT_BUTTON1,&B_1);
		READ_BUTTON(AMIT_BUTTON2,&B_2);
		
		if (B_0)
	{   
			if (number < 9)
		{
			number++;
			while (1)
			{
				READ_BUTTON(AMIT_BUTTON0, &B_0);
				
				if (!B_0)
				{
					break;
				}
			}				
		}
	}
		
		if (B_1)
		{
			if (number > 0)
			{
				number--;
				while (1)
				{
					READ_BUTTON(AMIT_BUTTON1, &B_1);
					if (!B_1)
					{
						break;
					}
				}
			}
		}
	
		if (B_2)
		{	
				number = 0;
				while (1)
				{
					READ_BUTTON(AMIT_BUTTON2, &B_0);
					
					if (!B_0)
					{
						break;
					}
				}
			
		}			
		
    }

}

