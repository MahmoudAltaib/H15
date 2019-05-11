/*
 * AMIT_INTERFACING.c
 *
 * Created: 5/11/2019 2:05:06 PM
 * Author : A.Elkady
 */ 

#include "PORT_DIO.h"


int main(void)
{
	unsigned int uiReading = 0;
	
	DIO_Pin_in(DDRD ,0);
	DIO_Pin_out(DDRD , 5);
		
    while (1) 
    {
		DIO_Pin_read(PIND , 0 , &uiReading);
		
			if (uiReading != 0)
			{	
				_delay_ms(20);
				DIO_Pin_read(PIND , 0 , &uiReading);
				
				if (uiReading != 0)
				{
					DIO_Pin_toggle(PORTD , 5 );
					_delay_ms(100);
				}
				else
				{
					
				}
			}
			else
			{
				
			}
    }
}

