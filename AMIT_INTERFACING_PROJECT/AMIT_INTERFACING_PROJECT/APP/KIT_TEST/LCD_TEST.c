/*
 * LCD_TEST.c
 *
 * Created: 5/21/2019 4:49:51 PM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "KIT_TEST/LCD_TEST.h"

/************************************************************************/
/*                     Static variables definition                      */
/************************************************************************/
static uint8_t gu8Button0_reading = 0;
static uint8_t gu8Button1_reading = 0;
static uint8_t gu8Button2_reading = 0;

static uint16_t gu16ADC0_value[4] = {0};
static uint16_t gu16ADC1_value[4] = {0};


/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/
extern void LCD_TEST(void)
{
	HOME_PAGE();
	PAGE2();
	PAGE3();
	PAGE4();
	PAGE5();
	PAGE6();
}

extern void HOME_PAGE(void)
{
	LCD_CLEAR();
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_CERTAIN_STRING("  AMIT_LEARNING " , 16);
	
	LCD_COMMAND(SECOND_LINE_START);
	LCD_DATA_CERTAIN_STRING("Test list -> (2)" , 16);
	
	do
	{
		BUTTON2_READ(&gu8Button2_reading);
	} while (gu8Button2_reading == 0 );
	
	_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
}

extern void PAGE2(void)
{
	// 0) LEDS ... 1) RELAYS  ... 2)Next
	
	uint8_t u8Next_page = 0;
	
	do 
	{
		LCD_CLEAR();

		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("0)LEDS   1)RELAY" , 16);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("2)Next  -->     " , 16);
		
		do
		{
			BUTTON0_READ(&gu8Button0_reading);
			BUTTON1_READ(&gu8Button1_reading);
			BUTTON2_READ(&gu8Button2_reading);
			
		} while (gu8Button0_reading == 0 && gu8Button1_reading == 0 && gu8Button2_reading == 0);
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (gu8Button0_reading != 0)
		{
			LCD_CLEAR();
			
			LCD_COMMAND(FIRST_LINE_START);
			LCD_DATA_CERTAIN_STRING("Testing ...     " , 16);
			
			LEDS_FLASH();
		}
		
		else if (gu8Button1_reading != 0)
		{
			LCD_CLEAR();
			
			LCD_COMMAND(FIRST_LINE_START);
			LCD_DATA_CERTAIN_STRING("Testing ...     " , 16);
			
			RELAY_FLICKER();
		}
		
		else if (gu8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
		
}

extern void PAGE3(void)
{
	// 0) BUZZER  ... 2)Next
	
	uint8_t u8Next_page = 0;
	
	do
	{
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("0)BUZZER        " , 16);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("2)Next  -->     " , 16);
		
		do
		{
			BUTTON0_READ(&gu8Button0_reading);
			BUTTON2_READ(&gu8Button2_reading);
			
		} while (gu8Button0_reading == 0 && gu8Button2_reading == 0);
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (gu8Button0_reading != 0)
		{
			LCD_CLEAR();
			
			LCD_COMMAND(FIRST_LINE_START);
			LCD_DATA_CERTAIN_STRING("Testing ...     " , 16);
			
			BUZZER_FLICKER();
		}
		
		else if (gu8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
	
}

extern void PAGE4(void)
{
	// 0) ADC  ... 2)Next
	
	uint8_t u8Next_page = 0;
	
	uint8_t u8End = 0;
	
	uint16_t u16ADC0_reading= 0;
	uint16_t u16ADC1_reading= 0;
	

	do
	{
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("0)ADC           " , 16);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("2)Next  -->     " , 16);
		
		do
		{
			BUTTON0_READ(&gu8Button0_reading);
			BUTTON2_READ(&gu8Button2_reading);
			
		} while (gu8Button0_reading == 0 && gu8Button2_reading == 0);
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (gu8Button0_reading != 0)
		{
			LCD_CLEAR();
			
			do 
			{	
				ADC0_READ(&u16ADC0_reading);
				ADC1_READ(&u16ADC1_reading);
				
				u16ADC0_reading = u16ADC0_reading *  5;  // mv  
				u16ADC1_reading = u16ADC1_reading *  5;  // mv
				
				ADC_VALUE_ANALYSE(u16ADC0_reading , gu16ADC0_value);
				ADC_VALUE_ANALYSE(u16ADC1_reading , gu16ADC1_value);
				
				LCD_COMMAND(FIRST_LINE_START);
				LCD_DATA_CERTAIN_STRING("ADC0  :" , 7);
				ADC_SHOW_VALUE(gu16ADC0_value);
				LCD_DATA('v');

				LCD_COMMAND(SECOND_LINE_START);
				LCD_DATA_CERTAIN_STRING("ADC1  :" , 7);
				ADC_SHOW_VALUE(gu16ADC1_value);
				LCD_DATA('v');
									
				BUTTON0_READ(&gu8Button0_reading);
				BUTTON1_READ(&gu8Button1_reading);
				
				if (gu8Button0_reading != 0 && gu8Button1_reading != 0)
				{
					u8End ++;
				}
				else
				{
					
				}
				
				_delay_ms(200);
			} while (u8End == 0);
			
			_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		}
		
		else if (gu8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
	
}


extern void PAGE5(void)
{
	// 0)PWM  ... 2)Next
	
	uint8_t u8Next_page = 0;
	uint8_t u8End = 0;
	
	uint32_t u32ADC0_reading= 0;
	uint32_t u32ADC1_reading= 0;
	
	uint32_t u32Duty_cycle_A = 0 ;
	uint32_t u32Duty_cycle_B = 0 ;
	
	
	do
	{
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("0)PWM   & ADC   " , 16);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("2)Next  -->     " , 16);
		
		do
		{
			BUTTON0_READ(&gu8Button0_reading);
			BUTTON2_READ(&gu8Button2_reading);
			
		} while (gu8Button0_reading == 0 && gu8Button2_reading == 0);
		T1_PWM_INIT();
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (gu8Button0_reading != 0)
		{
			LCD_CLEAR();
			
			do
			{
				ADC0_32_READ(&u32ADC0_reading);
				ADC1_32_READ(&u32ADC1_reading);
				
				u32ADC0_reading = u32ADC0_reading * 5 ;  // mv  
				u32ADC1_reading = u32ADC1_reading * 5 ;  // mv
				
				if (u32ADC0_reading >= 50 )
				{
					u32Duty_cycle_A = (u32ADC0_reading * 100) / 5000 ;
				} 
				else
				{
					u32Duty_cycle_A = 0;
				}
				
				if (u32ADC1_reading >= 50 )
				{
					u32Duty_cycle_B = (u32ADC1_reading * 100) / 5000 ;
				} 
				else
				{
					u32Duty_cycle_B = 0;
				}
				
				T1_PWM_DUTY_CYCLE(u32Duty_cycle_A , u32Duty_cycle_B);
				
				BUTTON2_READ(&gu8Button2_reading);
				
				if (gu8Button2_reading != 0 )
				{
					u8End ++;
				}
				else
				{
					
				}
				
				_delay_ms(200);
			} while (u8End == 0);
			
			_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		}
		
		else if (gu8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
	
	T1_PWM_DEINIT();
}

extern void PAGE6(void)
{
	uint8_t u8Next_page = 0;
	uint8_t u8End = 0;
	
	uint8_t u8Duty_cycle_A = 0 ;
	uint8_t u8Duty_cycle_B = 0 ;
	
	uint8_t u8PWM_A_value = 0;
	uint8_t u8PWM_B_value = 0;
	
	do
	{
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("0)PWM  LED0&BUZZ", 16);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("2)Next  -->     " , 16);
		
		do
		{
			BUTTON0_READ(&gu8Button0_reading);
			BUTTON2_READ(&gu8Button2_reading);
			
		} while (gu8Button0_reading == 0 && gu8Button2_reading == 0);
		T1_PWM_INIT();
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (gu8Button0_reading != 0)
		{
			LCD_CLEAR();
			
			do
			{
				LCD_COMMAND(FIRST_LINE_START);
				LCD_DATA(u8PWM_A_value);
				LCD_DATA(' ');
				LCD_DATA('+');
				
				LCD_COMMAND(SECOND_LINE_START);
				LCD_DATA(u8PWM_B_value);
				LCD_DATA(' ');
				LCD_DATA('-');
				
				
				BUTTON0_READ(&gu8Button0_reading);
				BUTTON1_READ(&gu8Button1_reading);
				BUTTON2_READ(&gu8Button2_reading);
				
				T1_PWM_DUTY_CYCLE(u8Duty_cycle_A , u8Duty_cycle_B);
				
				if (gu8Button0_reading != 0)
				{
					if (u8PWM_A_value <= 9)
					{
						u8PWM_A_value ++ ;
						u8PWM_B_value ++ ;
						
						u8Duty_cycle_A = u8PWM_A_value * 10 ;
						u8Duty_cycle_B = u8PWM_B_value * 10 ;
					}
					else
					{
						
					}
				}
				else if (gu8Button1_reading != 0)
				{
					if (u8PWM_A_value != 0)
					{
						u8PWM_A_value -- ;
						u8PWM_B_value -- ;
						
						u8Duty_cycle_A = u8PWM_A_value * 10 ;
						u8Duty_cycle_B = u8PWM_B_value * 10 ;
					}
					
					else
					{
						
					}
				}
				else if (gu8Button2_reading != 0)
				{
					u8End ++ ;
				}
				
				
				_delay_ms(200);
			} while (u8End == 0);
			
			_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		}
		
		else if (gu8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
	
	T1_PWM_DEINIT();
}