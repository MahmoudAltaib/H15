/*
 * BUZZER_ONEBUTTON_ONOFF.c
 *
 * Created: 5/17/2019 10:28:34 AM
 *  Author: hp
 */ 
#include "BUZZER_ONEBUTTON_ONOFF.h"
void BUZZER_ONEBUTTON_ONOFF(unsigned int button_Num)
{     unsigned int button_val = 0;
	  int flag = 0;
	READ_BUTTON(button_Num,&button_val);
	
	if (button_val && !flag)
	{
		BUZZ_ON();
		flag = 1; 
	}
	if(button_val && flag)
	{
		BUZZ_OFF();
		flag = 0;
	}
}