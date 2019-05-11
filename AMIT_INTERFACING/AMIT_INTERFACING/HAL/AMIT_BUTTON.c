/*
 * AMIT_BUTTON.c
 *
 * Created: 5/11/2019 4:41:22 PM
 *  Author: hp
 */ 
#include "AMIT_BUTTON.h"
#include "util/delay.h"

extern void READ_BUTTON(unsigned int button_Num  , unsigned int *button_Val)
{
unsigned int Button_State;
unsigned char counter;

switch (button_Num)
{
	default:
	break;
	
	case(AMIT_BUTTON0):
	
	DIO_pinIN(AMIT_DDR_BUTTON0 , AMIT_PIN_BUTTON0);
	
	for (counter = 0; counter < 150; counter++)
	{
		DIO_pinREAD(AMIT_PORT_BUTTON0, AMIT_PIN_BUTTON0, &Button_State);
	}
	
	*button_Val = Button_State;
	
	break;
	
	case(AMIT_BUTTON1):
	
	DIO_pinIN(AMIT_DDR_BUTTON1 , AMIT_PIN_BUTTON1); 
	
		for (counter = 0; counter < 150; counter++)
		{
			DIO_pinREAD(AMIT_PORT_BUTTON1, AMIT_PIN_BUTTON1, &Button_State);
		}
		
		*button_Val = Button_State;
	
	break;
	
	case(AMIT_BUTTON2):
	
	DIO_pinIN(AMIT_DDR_BUTTON2 , AMIT_PIN_BUTTON2); 
	
		for (counter = 0; counter < 150; counter++)
		{
			DIO_pinREAD(AMIT_PORT_BUTTON2, AMIT_PIN_BUTTON2, &Button_State);
		}
		
		*button_Val = Button_State;
	
	break;
}
	

	
}