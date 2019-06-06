/*
 * KEYPAD_LCD.c
 *
 * Created: 5/25/2019 5:46:42 AM
 *  Author: A.Elkady
 */ 

#include "KEYPAD_LCD.h"

extern const unsigned char gu8Key_pad[4][4];
extern volatile uint8_t gu8Password_right;
extern volatile uint8_t gu8ID_right ;
extern volatile uint8_t gu8T1_flag ;

static volatile unsigned char u8Entered_character1 = 0;
static volatile unsigned char u8Entered_character2 = 0;

static uint8_t u8Key1_sequence = 0;
static uint8_t u8Key2_sequence = 0;
static uint8_t u8Key3_sequence = 0;
static uint8_t u8Key4_sequence = 0;
static uint8_t u8Key5_sequence = 0;
static uint8_t u8Key6_sequence = 0;
static uint8_t u8Key7_sequence = 0;
static uint8_t u8Key8_sequence = 0;

static uint8_t u8Column1_reading = 0;
static uint8_t u8Column2_reading = 0;
static uint8_t u8Column3_reading = 0;
static uint8_t u8Column4_reading = 0;

static uint8_t u8Row1_reading = 0;
static uint8_t u8Row2_reading = 0;
static uint8_t u8Row3_reading = 0;
static uint8_t u8Row4_reading = 0;

static uint8_t u8Captured_row = 0;
static uint8_t u8Captured_column = 0;

static unsigned char u8Statement_pHome_1[] = {"ID :"};
static unsigned char u8Statement_pHome_2[] = {"PASS :"};
static unsigned char u8Statement_p2_1[] =    {"WRONG ID/PASS !!"};
static unsigned char u8Statement_p2_2[] =    {"TRY AGAIN ......"};
static unsigned char u8Statement_p3_1[] =    {"OK ..!!         "};
static unsigned char u8Statement_p3_2[] =    {"UNLOCKING ......"};

static uint8_t u8Statement_pHome_1_size = sizeof(u8Statement_pHome_1);
static uint8_t u8Statement_pHome_2_size = sizeof(u8Statement_pHome_2);
static uint8_t u8Statement_p2_1_size = sizeof(u8Statement_p2_1);
static uint8_t u8Statement_p2_2_size = sizeof(u8Statement_p2_2);
static uint8_t u8Statement_p3_1_size = sizeof(u8Statement_p3_1);
static uint8_t u8Statement_p3_2_size = sizeof(u8Statement_p3_2);
	
extern void KEYPAD_WITH_LCD()
{
	uint8_t u8Count1 = 0;
	uint8_t u8Count2 = 0;
	uint8_t u8ID_check = 0;
	uint8_t u8Password_check = 0;
	
	volatile uint8_t u8Temp_character = 0;
	
	u8Entered_character1 = 0;
	u8Entered_character2 = 0;
	gu8Password_right = 0;
	gu8ID_right = 0;
	
	unsigned char u8Entered_password[MAXIMUM_NUMBER_OF_LETTERS] = {0};
	unsigned char u8Entered_ID[MAXIMUM_NUMBER_OF_LETTERS] = {0};
		
	unsigned char u8Actual_ID[MAXIMUM_NUMBER_OF_LETTERS] = {'A','E','L','K','A','D','Y'};  /*{'A','E','L','K','A','D','Y'}*/
	unsigned char u8Actual_password[MAXIMUM_NUMBER_OF_LETTERS] = {'3','5','5','2','3','9'};
			
	LCD_COMMAND(CLEAR_DISPLAY);
	_delay_us(2000);
	
	LCD_COMMAND(SHIFT_CURSOR_RIGHT);
	_delay_us(100);
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_STRING(u8Statement_pHome_1 , u8Statement_pHome_1_size);
	
	LCD_COMMAND(SHIFT_CURSOR_POSITION_LEFT);
	
	do
	{
		for (u8Count1 = 0; u8Count1 < MAXIMUM_NUMBER_OF_LETTERS; u8Count1 ++)
		{	
			u8Temp_character = 0;
			
			for (u8Count2 = 0 ; u8Count2 < 4 ; u8Count2 ++)
			{
				SET_COLUMNS_INPUT();
				POWER_ALL_COLUMNS(); // To activate pull up resistors
				
				SET_ROWS_OUTPUT();
				GROUND_ALL_ROWS();
				
				do  // To make sure that all buttons are released
				{
					READ_COLUMN1(&u8Column1_reading);
					READ_COLUMN2(&u8Column2_reading);
					READ_COLUMN3(&u8Column3_reading);
					READ_COLUMN4(&u8Column4_reading);
					
				} while (u8Column1_reading == 0 || u8Column2_reading == 0 || u8Column3_reading == 0 || u8Column4_reading == 0 );
				
				do  // To wait for a press
				{
					READ_COLUMN1(&u8Column1_reading);
					READ_COLUMN2(&u8Column2_reading);
					READ_COLUMN3(&u8Column3_reading);
					READ_COLUMN4(&u8Column4_reading);
					
				} while (u8Column1_reading != 0 && u8Column2_reading != 0 && u8Column3_reading != 0 && u8Column4_reading != 0 );
				
				BUZZER_ON();
				GET_KEY_ROW(&u8Captured_row);
				GET_KEY_COLUMN(&u8Captured_column);
				_delay_ms(50);
				BUZZER_OFF();
				
				u8Temp_character = gu8Key_pad[u8Captured_row][u8Captured_column];
				
				if (u8Temp_character == 's' || u8Temp_character == 'o')
				{
					break;
				}
				
				else
				{
					ANALYZE_PRESS(u8Temp_character);
					
					LCD_DATA(u8Entered_character1);
					
					LCD_COMMAND(SHIFT_CURSOR_POSITION_LEFT);
				}
				
			} 
			u8Entered_ID[u8Count1] = u8Entered_character1 ;
			
			if (u8Temp_character == 'o')
			{
				break ;
			}
			else if (u8Temp_character == 's')
			{	
				LCD_COMMAND(SHIFT_CURSOR_POSITION_RIGHT);
				continue;
			}
			else
			{
			}
				
		}

		break;
		
	} while (u8Entered_character1 != 'o');
	
	for (u8Count1 = 0 ;u8Count1 < MAXIMUM_NUMBER_OF_LETTERS ; u8Count1 ++)
	{
		if (u8Entered_ID[u8Count1] == u8Actual_ID[u8Count1])
		{
			u8ID_check ++;
		}
		else
		{
			
		}
	}

	
	LCD_COMMAND(SECOND_LINE_START);

	LCD_DATA_STRING(u8Statement_pHome_2 , u8Statement_pHome_2_size);
	
	LCD_COMMAND(SHIFT_CURSOR_POSITION_LEFT);
	
	do
	{
		for (u8Count1 = 0;u8Count1 < MAXIMUM_NUMBER_OF_LETTERS; u8Count1 ++)
		{
			SET_COLUMNS_INPUT();
			POWER_ALL_COLUMNS(); // To activate pull up resistors
					
			SET_ROWS_OUTPUT();
			GROUND_ALL_ROWS();
					
			do  // To make sure that all buttons are released
			{
				READ_COLUMN1(&u8Column1_reading);
				READ_COLUMN2(&u8Column2_reading);
				READ_COLUMN3(&u8Column3_reading);
				READ_COLUMN4(&u8Column4_reading);
						
			} while (u8Column1_reading == 0 || u8Column2_reading == 0 || u8Column3_reading == 0 || u8Column4_reading == 0 );
					
			do  // To wait for a press
			{
				READ_COLUMN1(&u8Column1_reading);
				READ_COLUMN2(&u8Column2_reading);
				READ_COLUMN3(&u8Column3_reading);
				READ_COLUMN4(&u8Column4_reading);
						
			} while (u8Column1_reading != 0 && u8Column2_reading != 0 && u8Column3_reading != 0 && u8Column4_reading != 0 );
					
			BUZZER_ON();
			GET_KEY_ROW(&u8Captured_row);
			GET_KEY_COLUMN(&u8Captured_column);
			_delay_ms(50);
			BUZZER_OFF();
					
			u8Entered_character2 = gu8Key_pad[u8Captured_row][u8Captured_column];
					
			if (u8Entered_character2 == 'o')
			{
				break;
			}
			else
			{
			}
					
			LCD_DATA('*');
					
			u8Entered_password[u8Count1] = u8Entered_character2 ;
		}
			
	} while (u8Entered_character2 != 'o');
			
	for (u8Count1 = 0 ;u8Count1 < MAXIMUM_NUMBER_OF_LETTERS ; u8Count1 ++)
	{
		if (u8Entered_password[u8Count1] == u8Actual_password[u8Count1])
		{
			u8Password_check ++;
		}
		else
		{
		}
	}

	if (u8ID_check == MAXIMUM_NUMBER_OF_LETTERS && u8Password_check == MAXIMUM_NUMBER_OF_LETTERS)
	{
		gu8ID_right ++ ;
		gu8Password_right ++ ;
		
		LCD_COMMAND(CLEAR_DISPLAY);
		_delay_us(2000);
		LCD_COMMAND(SHIFT_CURSOR_RIGHT);
		_delay_us(100);
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_STRING(u8Statement_p3_1 , u8Statement_p3_1_size);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_STRING(u8Statement_p3_2 , u8Statement_p3_2_size);
		
		BUZZER_ON();
		_delay_ms(300);
		BUZZER_OFF();
		
		_delay_ms(500);
		RELAY_ON();
	} 
	else
	{
		LCD_COMMAND(CLEAR_DISPLAY);
		_delay_us(2000);
		LCD_COMMAND(SHIFT_CURSOR_RIGHT);
		_delay_us(100);
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_STRING(u8Statement_p2_1 , u8Statement_p2_1_size);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_STRING(u8Statement_p2_2 , u8Statement_p2_2_size);
		
		BUZZER_FLICKER();
	}
	
}

extern void GET_KEY_ROW(uint8_t *pu8Captured_row)
{
	SET_ROWS_INPUT();
	POWER_ALL_ROWS(); // To deactivate pull up resistors
	
	SET_COLUMNS_OUTPUT();
	GROUND_ALL_COLUMNS();
	
	while (1)
	{
		READ_ROW1(&u8Row1_reading);
		
		if (u8Row1_reading == 0)
		{
			*pu8Captured_row = ROW1 ;
			break;
		}
		else
		{
			
		}
		
		READ_ROW2(&u8Row2_reading);
		
		if (u8Row2_reading == 0)
		{
			*pu8Captured_row = ROW2 ;
			break;
		}
		else
		{
			
		}
		
		READ_ROW3(&u8Row3_reading);
		
		if (u8Row3_reading == 0)
		{
			*pu8Captured_row = ROW3 ;
			break;
		}
		else
		{
			
		}
		
		READ_ROW4(&u8Row4_reading);
		
		if (u8Row4_reading == 0)
		{
			*pu8Captured_row = ROW4 ;
			break;
		}
		else
		{
			
		}

	}
		
	GROUND_ALL_COLUMNS();
	
}

extern void GET_KEY_COLUMN(uint8_t *pu8Captured_column)
{
	SET_COLUMNS_INPUT();
	POWER_ALL_COLUMNS(); // To activate pull up resistors
	
	SET_ROWS_OUTPUT();
	GROUND_ALL_ROWS();
	
	while (1)
	{
		READ_COLUMN1(&u8Column1_reading);
		
		if (u8Column1_reading == 0)
		{
			*pu8Captured_column = COLUMN1 ;
			break;
		}
		else
		{
			
		}
		
		READ_COLUMN2(&u8Column2_reading);
		
		if (u8Column2_reading == 0)
		{
			*pu8Captured_column = COLUMN2 ;
			break;
		}
		else
		{
			
		}
		
		READ_COLUMN3(&u8Column3_reading);
		
		if (u8Column3_reading == 0)
		{
			*pu8Captured_column = COLUMN3 ;
			break;
		}
		else
		{
			
		}
		
		READ_COLUMN4(&u8Column4_reading);
		
		if (u8Column4_reading == 0)
		{
			*pu8Captured_column = COLUMN4 ;
			break;
		}
		else
		{
			
		}
		
	}
	
	GROUND_ALL_ROWS();
}

extern void ANALYZE_PRESS(uint8_t u8Temp_character )
{
	if (u8Temp_character == '2')
	{	
		u8Key2_sequence = 0;
		u8Key3_sequence = 0;
		u8Key4_sequence = 0;
		u8Key5_sequence = 0;
		u8Key6_sequence = 0;
		u8Key7_sequence = 0;
		u8Key8_sequence = 0;
		
		if (u8Key1_sequence == 0)
		{
			u8Entered_character1 = 'A';
			u8Key1_sequence ++ ;
		}
		else if (u8Key1_sequence == 1)
		{
			u8Entered_character1 = 'B';
			u8Key1_sequence ++ ;
		}
		else if (u8Key1_sequence == 2)
		{
			u8Entered_character1 = 'C';
			u8Key1_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '3')
	{	
		u8Key1_sequence = 0;
		u8Key3_sequence = 0;
		u8Key4_sequence = 0;
		u8Key5_sequence = 0;
		u8Key6_sequence = 0;
		u8Key7_sequence = 0;
		u8Key8_sequence = 0;
		
		if (u8Key2_sequence == 0)
		{
			u8Entered_character1 = 'D';
			u8Key2_sequence ++ ;
		}
		else if (u8Key2_sequence == 1)
		{
			u8Entered_character1 = 'E';
			u8Key2_sequence ++ ;
		}
		else if (u8Key2_sequence == 2)
		{
			u8Entered_character1 = 'F';
			u8Key2_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '4')
	{	
		u8Key2_sequence = 0;
		u8Key1_sequence = 0;
		u8Key4_sequence = 0;
		u8Key5_sequence = 0;
		u8Key6_sequence = 0;
		u8Key7_sequence = 0;
		u8Key8_sequence = 0;
		
		if (u8Key3_sequence == 0)
		{
			u8Entered_character1 = 'G';
			u8Key3_sequence ++ ;
		}
		else if (u8Key3_sequence == 1)
		{
			u8Entered_character1 = 'H';
			u8Key3_sequence ++ ;
		}
		else if (u8Key3_sequence == 2)
		{
			u8Entered_character1 = 'I';
			u8Key3_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '5')
	{
		u8Key2_sequence = 0;
		u8Key3_sequence = 0;
		u8Key1_sequence = 0;
		u8Key5_sequence = 0;
		u8Key6_sequence = 0;
		u8Key7_sequence = 0;
		u8Key8_sequence = 0;
		
		if (u8Key4_sequence == 0)
		{
			u8Entered_character1 = 'J';
			u8Key4_sequence ++ ;
		}
		else if (u8Key4_sequence == 1)
		{
			u8Entered_character1 = 'K';
			u8Key4_sequence ++ ;
		}
		else if (u8Key4_sequence == 2)
		{
			u8Entered_character1 = 'L';
			u8Key4_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '6')
	{
		u8Key2_sequence = 0;
		u8Key3_sequence = 0;
		u8Key4_sequence = 0;
		u8Key1_sequence = 0;
		u8Key6_sequence = 0;
		u8Key7_sequence = 0;
		u8Key8_sequence = 0;
		
		if (u8Key5_sequence == 0)
		{
			u8Entered_character1 = 'M';
			u8Key5_sequence ++ ;
		}
		else if (u8Key5_sequence == 1)
		{
			u8Entered_character1 = 'N';
			u8Key5_sequence ++ ;
		}
		else if (u8Key5_sequence == 2)
		{
			u8Entered_character1 = 'O';
			u8Key5_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '7')
	{
		u8Key2_sequence = 0;
		u8Key3_sequence = 0;
		u8Key4_sequence = 0;
		u8Key5_sequence = 0;
		u8Key1_sequence = 0;
		u8Key7_sequence = 0;
		u8Key8_sequence = 0;
		
		if (u8Key6_sequence == 0)
		{
			u8Entered_character1 = 'P';
			u8Key6_sequence ++ ;
		}
		else if (u8Key6_sequence == 1)
		{
			u8Entered_character1 = 'Q';
			u8Key6_sequence ++ ;
		}
		else if (u8Key6_sequence == 2)
		{
			u8Entered_character1 = 'R';
			u8Key6_sequence ++ ;
		}
		else if (u8Key6_sequence == 3)
		{
			u8Entered_character1 = 'S';
			u8Key6_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '8')
	{
		u8Key2_sequence = 0;
		u8Key3_sequence = 0;
		u8Key4_sequence = 0;
		u8Key5_sequence = 0;
		u8Key6_sequence = 0;
		u8Key1_sequence = 0;
		u8Key8_sequence = 0;
		
		if (u8Key7_sequence == 0)
		{
			u8Entered_character1 = 'T';
			u8Key7_sequence ++ ;
		}
		else if (u8Key7_sequence == 1)
		{
			u8Entered_character1 = 'U';
			u8Key7_sequence ++ ;
		}
		else if (u8Key7_sequence == 2)
		{
			u8Entered_character1 = 'V';
			u8Key7_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '9')
	{
		u8Key2_sequence = 0;
		u8Key3_sequence = 0;
		u8Key4_sequence = 0;
		u8Key5_sequence = 0;
		u8Key6_sequence = 0;
		u8Key7_sequence = 0;
		u8Key1_sequence = 0;
		
		if (u8Key8_sequence == 0)
		{
			u8Entered_character1 = 'W';
			u8Key8_sequence ++ ;
		}
		else if (u8Key8_sequence == 1)
		{
			u8Entered_character1 = 'X';
			u8Key8_sequence ++ ;
		}
		else if (u8Key8_sequence == 2)
		{
			u8Entered_character1 = 'Y';
			u8Key8_sequence ++ ;
		}
		else if (u8Key8_sequence == 3)
		{
			u8Entered_character1 = 'Z';
			u8Key8_sequence = 0 ;
		}
	}
	else
	{
		
	}
}
