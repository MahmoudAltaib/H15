/*
 * LCD_TEST.c
 *
 * Created: 5/21/2019 4:49:51 PM
 *  Author: A.Elkady
 */ 

#include "LCD_TEST/LCD_TEST.h"

static unsigned char u8Statement_pHome_1[] = {"  AMIT_LEARNING "};
static unsigned char u8Statement_pHome_2[] = {"Test list -> (2)"};
static unsigned char u8Statement_p2_1[] =    {"0)LEDS   1)RELAY"};
static unsigned char u8Statement_p2_2[] =    {"2)Next  -->     "};
static unsigned char u8Statement_p3_1[] =    {"0)BUZZER        "};
static unsigned char u8Statement_p3_2[] =    {"2)Next  -->     "};
static unsigned char u8Statement_p4_1[] =    {"0)ADC           "};
static unsigned char u8Statement_p4_2[] =    {"2)Next  -->     "};
static unsigned char u8Statement_p5_1[] =    {"0)PWM   & ADC   "};
static unsigned char u8Statement_p5_2[] =    {"2)Next  -->     "};
static unsigned char u8Statement_p6_1[] =    {"0)PWM  LED0&BUZZ"};
static unsigned char u8Statement_p6_2[] =    {"2)Next  -->     "};

static unsigned char u8Statement_p4_1_1[] =  {"ADC0  :"};
static unsigned char u8Statement_p4_1_2[] =  {"ADC1  :"};

	
static unsigned char u8Statement_test[] =    {"Testing ...     "}; 
	
static uint8_t u8Statement_pHome_1_size = sizeof(u8Statement_pHome_1);
static uint8_t u8Statement_pHome_2_size = sizeof(u8Statement_pHome_2);
static uint8_t u8Statement_p2_1_size = sizeof(u8Statement_p2_1);
static uint8_t u8Statement_p2_2_size = sizeof(u8Statement_p2_2);
static uint8_t u8Statement_p3_1_size = sizeof(u8Statement_p3_1);
static uint8_t u8Statement_p3_2_size = sizeof(u8Statement_p3_2);
static uint8_t u8Statement_p4_1_size = sizeof(u8Statement_p4_1);
static uint8_t u8Statement_p4_2_size = sizeof(u8Statement_p4_2);
static uint8_t u8Statement_p5_1_size = sizeof(u8Statement_p5_1);
static uint8_t u8Statement_p5_2_size = sizeof(u8Statement_p5_2);
static uint8_t u8Statement_p6_1_size = sizeof(u8Statement_p6_1);
static uint8_t u8Statement_p6_2_size = sizeof(u8Statement_p6_2);

static uint8_t u8Statement_p4_1_1_size = sizeof(u8Statement_p4_1_1);
static uint8_t u8Statement_p4_1_2_size = sizeof(u8Statement_p4_1_2);

static uint8_t u8Statement_test_size = sizeof(u8Statement_test);

static uint8_t u8Button0_reading = 0;
static uint8_t u8Button1_reading = 0;
static uint8_t u8Button2_reading = 0;

static uint16_t u16ADC0_value[4] = {0};
static uint16_t u16ADC1_value[4] = {0};

extern void LCD_TEST()
{
	HOME_PAGE();
	PAGE2();
	PAGE3();
	PAGE4();
	PAGE5();
	PAGE6();
}

extern void HOME_PAGE()
{
	LCD_COMMAND(CLEAR_DISPLAY);
	_delay_us(2000);
	LCD_COMMAND(SHIFT_CURSOR_RIGHT);
	_delay_us(100);
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_STRING(u8Statement_pHome_1 , u8Statement_pHome_1_size);
	
	LCD_COMMAND(SECOND_LINE_START);
	LCD_DATA_STRING(u8Statement_pHome_2 , u8Statement_pHome_2_size);
	
	do
	{
		BUTTON2_READ(&u8Button2_reading);
	} while (u8Button2_reading == 0 );
	
	_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
}

extern void PAGE2()
{
	// 0) LEDS ... 1) RELAYS  ... 2)Next
	
	uint8_t u8Next_page = 0;
	
	do 
	{
		LCD_COMMAND(CLEAR_DISPLAY);
		_delay_us(2000);
		LCD_COMMAND(SHIFT_CURSOR_RIGHT);
		_delay_us(100);
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_STRING(u8Statement_p2_1 , u8Statement_p2_1_size);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_STRING(u8Statement_p2_2 , u8Statement_p2_2_size);
		
		do
		{
			BUTTON0_READ(&u8Button0_reading);
			BUTTON1_READ(&u8Button1_reading);
			BUTTON2_READ(&u8Button2_reading);
			
		} while (u8Button0_reading == 0 && u8Button1_reading == 0 && u8Button2_reading == 0);
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (u8Button0_reading != 0)
		{
			LCD_COMMAND(CLEAR_DISPLAY);
			_delay_us(2000);
			LCD_COMMAND(SHIFT_CURSOR_RIGHT);
			_delay_us(100);
			
			LCD_COMMAND(FIRST_LINE_START);
			LCD_DATA_STRING(u8Statement_test , u8Statement_test_size);
			
			LEDS_FLASH();
		}
		
		else if (u8Button1_reading != 0)
		{
			LCD_COMMAND(CLEAR_DISPLAY);
			_delay_us(2000);
			LCD_COMMAND(SHIFT_CURSOR_RIGHT);
			_delay_us(100);
			
			LCD_COMMAND(FIRST_LINE_START);
			LCD_DATA_STRING(u8Statement_test , u8Statement_test_size);
			
			RELAY_FLICKER();
		}
		
		else if (u8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
		
}

extern void PAGE3()
{
	// 0) BUZZER  ... 2)Next
	
	uint8_t u8Next_page = 0;
	
	do
	{
		LCD_COMMAND(CLEAR_DISPLAY);
		_delay_us(2000);
		LCD_COMMAND(SHIFT_CURSOR_RIGHT);
		_delay_us(100);
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_STRING(u8Statement_p3_1 , u8Statement_p3_1_size);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_STRING(u8Statement_p3_2 , u8Statement_p3_2_size);
		
		do
		{
			BUTTON0_READ(&u8Button0_reading);
			BUTTON2_READ(&u8Button2_reading);
			
		} while (u8Button0_reading == 0 && u8Button2_reading == 0);
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (u8Button0_reading != 0)
		{
			LCD_COMMAND(CLEAR_DISPLAY);
			_delay_us(2000);
			LCD_COMMAND(SHIFT_CURSOR_RIGHT);
			_delay_us(100);
			
			LCD_COMMAND(FIRST_LINE_START);
			LCD_DATA_STRING(u8Statement_test , u8Statement_test_size);
			
			BUZZER_FLICKER();
		}
		
		else if (u8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
	
}

extern void PAGE4()
{
	// 0) ADC  ... 2)Next
	
	uint8_t u8Next_page = 0;
	
	uint8_t u8End = 0;
	
	uint16_t u16ADC0_reading= 0;
	uint16_t u16ADC1_reading= 0;
	

	do
	{
		LCD_COMMAND(CLEAR_DISPLAY);
		_delay_us(2000);
		LCD_COMMAND(SHIFT_CURSOR_RIGHT);
		_delay_us(100);
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_STRING(u8Statement_p4_1 , u8Statement_p4_1_size);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_STRING(u8Statement_p4_2 , u8Statement_p4_2_size);
		
		do
		{
			BUTTON0_READ(&u8Button0_reading);
			BUTTON2_READ(&u8Button2_reading);
			
		} while (u8Button0_reading == 0 && u8Button2_reading == 0);
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (u8Button0_reading != 0)
		{
			LCD_COMMAND(CLEAR_DISPLAY);
			_delay_us(2000);
			LCD_COMMAND(SHIFT_CURSOR_RIGHT);
			_delay_us(100);
			do 
			{	
				ADC0_READ(&u16ADC0_reading);
				ADC1_READ(&u16ADC1_reading);
				
				u16ADC0_reading = u16ADC0_reading *  48/10;  // mv  4.78 is the actual voltage directed to AVREF NOT 5v
				u16ADC1_reading = u16ADC1_reading * 48/10 ;  // mv
				
				ADC_VALUE_ANALYSE(u16ADC0_reading , u16ADC0_value);
				ADC_VALUE_ANALYSE(u16ADC1_reading , u16ADC1_value);
				
				LCD_COMMAND(FIRST_LINE_START);
				LCD_DATA_STRING(u8Statement_p4_1_1 , u8Statement_p4_1_1_size);
				ADC_SHOW_VALUE(u16ADC0_value);
				LCD_DATA('v');

				LCD_COMMAND(SECOND_LINE_START);
				LCD_DATA_STRING(u8Statement_p4_1_2 , u8Statement_p4_1_2_size);
				ADC_SHOW_VALUE(u16ADC1_value);
				LCD_DATA('v');
									
				BUTTON0_READ(&u8Button0_reading);
				BUTTON1_READ(&u8Button1_reading);
				
				if (u8Button0_reading != 0 && u8Button1_reading != 0)
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
		
		else if (u8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
	
}


extern void PAGE5()
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
		LCD_COMMAND(CLEAR_DISPLAY);
		_delay_us(2000);
		LCD_COMMAND(SHIFT_CURSOR_RIGHT);
		_delay_us(100);
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_STRING(u8Statement_p5_1 , u8Statement_p5_1_size);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_STRING(u8Statement_p5_2 , u8Statement_p5_2_size);
		
		do
		{
			BUTTON0_READ(&u8Button0_reading);
			BUTTON2_READ(&u8Button2_reading);
			
		} while (u8Button0_reading == 0 && u8Button2_reading == 0);
		T1_PWM_INIT();
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (u8Button0_reading != 0)
		{
			LCD_COMMAND(CLEAR_DISPLAY);
			_delay_us(2000);
			LCD_COMMAND(SHIFT_CURSOR_RIGHT);
			_delay_us(100);
			
			do
			{
				ADC0_32_READ(&u32ADC0_reading);
				ADC1_32_READ(&u32ADC1_reading);
				
				u32ADC0_reading = u32ADC0_reading * 48/10;  // mv  4.78 is the actual voltage directed to AVREF NOT 5v
				u32ADC1_reading = u32ADC1_reading * 48/10;  // mv
				
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
				
				BUTTON2_READ(&u8Button2_reading);
				
				if (u8Button2_reading != 0 )
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
		
		else if (u8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
	
	T1_PWM_DEINIT();
}

extern void PAGE6()
{
	uint8_t u8Next_page = 0;
	uint8_t u8End = 0;
	
	uint8_t u8Duty_cycle_A = 0 ;
	uint8_t u8Duty_cycle_B = 0 ;
	
	uint8_t u8PWM_A_value = 0;
	uint8_t u8PWM_B_value = 0;
	
	do
	{
		LCD_COMMAND(CLEAR_DISPLAY);
		_delay_us(2000);
		LCD_COMMAND(SHIFT_CURSOR_RIGHT);
		_delay_us(100);
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_STRING(u8Statement_p6_1 , u8Statement_p6_1_size);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_STRING(u8Statement_p6_2 , u8Statement_p6_2_size);
		
		do
		{
			BUTTON0_READ(&u8Button0_reading);
			BUTTON2_READ(&u8Button2_reading);
			
		} while (u8Button0_reading == 0 && u8Button2_reading == 0);
		T1_PWM_INIT();
		
		_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		
		if (u8Button0_reading != 0)
		{
			LCD_COMMAND(CLEAR_DISPLAY);
			_delay_us(2000);
			LCD_COMMAND(SHIFT_CURSOR_RIGHT);
			_delay_us(100);
			
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
				
				
				BUTTON0_READ(&u8Button0_reading);
				BUTTON1_READ(&u8Button1_reading);
				BUTTON2_READ(&u8Button2_reading);
				
				T1_PWM_DUTY_CYCLE(u8Duty_cycle_A , u8Duty_cycle_B);
				
				if (u8Button0_reading != 0)
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
				else if (u8Button1_reading != 0)
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
				else if (u8Button2_reading != 0)
				{
					u8End ++ ;
				}
				
				
				_delay_ms(200);
			} while (u8End == 0);
			
			_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		}
		
		else if (u8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
	
	T1_PWM_DEINIT();
}