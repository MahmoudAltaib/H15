/*
 * Layered_architecture.c
 *
 * Created: 5/10/2019 11:17:02 PM
 * Author : A.Elkady
 */ 
#include "GPIO_Driver.h"
#include "AMIT_Board.h"
#include "AMIT_Layout.h"

int main(void)
{
	volatile uint8_t u8Pin_reading = 0;
	
  Pin_mode(PORT4 , AMIT_LED1 , OUTPUT);
  Pin_mode(PORT4 , PUSH_BUTTON0 , INPUT);
  Reset_bit(PORT4 , AMIT_LED1);
  
    while (1) 
    {
		Pin_read(PORT4 , PUSH_BUTTON0 ,&u8Pin_reading );
		_delay_ms(50);
		
		Pin_read(PORT4 , PUSH_BUTTON0 ,&u8Pin_reading );
		
		if (u8Pin_reading != 0)
		{
			Set_bit(PORT4 , AMIT_LED1);
		}
		else
		{
			Reset_bit(PORT4 , AMIT_LED1);
			
		}
		
		
		
    }
}

