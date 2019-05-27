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
static unsigned char u8Statement_p4_1[] =    {"0) 7SEG_Counter "};
static unsigned char u8Statement_p4_2[] =    {"2)Next  -->     "};
static unsigned char u8Statement_p4_1_1[] =  {"0) (+)    1) (-)"};
static unsigned char u8Statement_p4_1_2[] =  {"2)RESET  0+1)ESC"};
	
static unsigned char u8Statement_test[] =    {"Testing ...     "}; 
	
static uint8_t u8Statement_pHome_1_size = sizeof(u8Statement_pHome_1);
static uint8_t u8Statement_pHome_2_size = sizeof(u8Statement_pHome_2);
static uint8_t u8Statement_p2_1_size = sizeof(u8Statement_p2_1);
static uint8_t u8Statement_p2_2_size = sizeof(u8Statement_p2_2);
static uint8_t u8Statement_p3_1_size = sizeof(u8Statement_p3_1);
static uint8_t u8Statement_p3_2_size = sizeof(u8Statement_p3_2);
static uint8_t u8Statement_p4_1_size = sizeof(u8Statement_p4_1);
static uint8_t u8Statement_p4_2_size = sizeof(u8Statement_p4_2);
static uint8_t u8Statement_p4_1_1_size = sizeof(u8Statement_p4_1_1);
static uint8_t u8Statement_p4_1_2_size = sizeof(u8Statement_p4_1_2);
static uint8_t u8Statement_test_size = sizeof(u8Statement_test);

static uint8_t u8Button0_reading = 0;
static uint8_t u8Button1_reading = 0;
static uint8_t u8Button2_reading = 0;

extern void LCD_TEST()
{
	HOME_PAGE();
	PAGE2();
	PAGE3();
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
	// 0) SEGMENT_COUNTER  ... 2)Next
	
	uint8_t u8Next_page = 0;
	
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
			uint8_t u8End = 0;
			
			LCD_COMMAND(CLEAR_DISPLAY);
			_delay_us(2000);
			LCD_COMMAND(SHIFT_CURSOR_RIGHT);
			_delay_us(100);
			
			LCD_COMMAND(FIRST_LINE_START);
			LCD_DATA_STRING(u8Statement_p4_1_1 , u8Statement_p4_1_1_size);
			
			LCD_COMMAND(SECOND_LINE_START);
			LCD_DATA_STRING(u8Statement_p4_1_2 , u8Statement_p4_1_2_size);
			
			do 
			{
				SEGMENT_INC_DEC();
				
				BUTTON0_READ(&u8Button0_reading);
				BUTTON1_READ(&u8Button1_reading);
				
				if (u8Button0_reading !=0 && u8Button1_reading != 0)
				{
					u8End ++ ;
				}
				else
				{
					
				}
			} while (u8End == 0);
			
			_delay_ms(DELAY_BETWEEN_ACTIONS_ms);
		}
		
		else if (u8Button2_reading != 0)
		{
			u8Next_page ++;
		}
		
	} while (u8Next_page == 0);
	
}


