/*
 * Microcontrollers1.c
 *
 * Created: 5/6/2019 12:51:51 PM
 * Author : A.Elkady
 */ 

#include "Functions.h"

int main(void)
{
	uint8_t u8Temp = 0;
	
	Pin_mode(C , 2 , OUTPUT);
	Pin_mode(C , 3 , OUTPUT); 
	Pin_mode(C , 4 , OUTPUT); 
	Pin_mode(C , 5 , OUTPUT); 
	Pin_mode(C , 6 , OUTPUT);  
	Pin_mode(C , 7 , OUTPUT);  
	
	Pin_mode(D , 0 , INPUT);
	Pin_mode(D , 1 , INPUT);
	Pin_mode(D , 2 , INPUT);
	
	Set_bit(C , 2);
	Reset_bit(C , 3);
	Reset_bit(C , 4);
	Reset_bit(C , 5);
	Reset_bit(C , 6);
	Reset_bit(C , 7);
	
	*(volatile uint8_t *)(C) |= (u8Temp << 4) ;
	
	while (1)
	{
		
		if (Pin_read(D , 0) == 1)
		{
			_delay_ms(50);
			if ((Pin_read(D , 0) == 1))
			{
				if (u8Temp == 9)
				{
					u8Temp = 0 ;
					Clear_7SEG();
					*(volatile uint8_t *)(C) |= (u8Temp << 4) ;
					_delay_ms(50);
					
				}
				else
				{
					u8Temp ++ ;
					Clear_7SEG();
					*(volatile uint8_t *)(C) |= (u8Temp << 4) ;
					_delay_ms(50) ;
				}
			}
			else
			{
				
			}
		}
		else
		{
			
		}
			
	
	if (Pin_read(D , 1) == 1)
	{
		_delay_ms(50);
		if ((Pin_read(D , 1) == 1))
		{
			if (u8Temp == 0)
			{
				Reset_bit(C,2);
				_delay_ms(300);
				Set_bit(C,2);
				_delay_ms(300);
				
				Reset_bit(C,2);
				_delay_ms(300);
				Set_bit(C,2);
				_delay_ms(300);
				
				Reset_bit(C,2);
				_delay_ms(300);
				Set_bit(C,2);
				_delay_ms(300);
				
			}
			else
			{
				u8Temp -- ;
				Clear_7SEG();
				
				*(volatile uint8_t *)(C) |= (u8Temp << 4) ;
				_delay_ms(50);
			}
		}
		else
		{
			
		}
	}
	else
	{
		
	}
	
	
	if (Pin_read(D , 2) == 1)
	{
		_delay_ms(50);
		if ((Pin_read(D , 2) == 1))
		{
			u8Temp = 0;
			Clear_7SEG();
			
			*(volatile uint8_t *)(C) |= (u8Temp << 4) ;
			_delay_ms(50);
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

