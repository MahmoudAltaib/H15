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

static unsigned char u8Entered_character = 0;

static uint8_t u8Key_sequence = 0;

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
static unsigned char u8Statement_p2_1[] =    {"WRONG ID/PASS.!!"};
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
	uint8_t u8Count = 0;
	uint8_t u8ID_check = 0;
	uint8_t u8Password_check = 0;
	
	uint8_t u8Temp_character = 0;
	
	gu8Password_right = 0;
	
	unsigned char u8Entered_password[MAXIMUM_NUMBER_OF_LETTERS] = {0};
	unsigned char u8Entered_ID[MAXIMUM_NUMBER_OF_LETTERS] = {0};
		
	unsigned char u8Actual_ID[MAXIMUM_NUMBER_OF_LETTERS] = {'A','E','L','K','A','D','Y'};
	unsigned char u8Actual_password[MAXIMUM_NUMBER_OF_LETTERS] = {'3','5','5','2','3','9'};
			
	LCD_COMMAND(CLEAR_DISPLAY);
	_delay_us(2000);
	
	LCD_COMMAND(SHIFT_CURSOR_RIGHT);
	_delay_us(100);
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_STRING(u8Statement_pHome_1 , u8Statement_pHome_1_size);
	
	
	do
	{
		do 
		{
			for (u8Count = 0;u8Count < MAXIMUM_NUMBER_OF_LETTERS; u8Count ++)
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
				
				u8Temp_character = 	gu8Key_pad[u8Captured_row][u8Captured_column];
				
				if (u8Temp_character == '-')
				{
					break;
				}
				else
				{
					ANALYZE_PRESS(u8Temp_character );
				}
					
				LCD_DATA(u8Entered_character);
				LCD_COMMAND(SHIFT_CURSOR_LEFT);

				}
				
			} while (u8Key_sequence != 5);
			
			u8Key_sequence = 0;
			
			LCD_COMMAND(SHIFT_CURSOR_RIGHT);
						
			u8Entered_ID[u8Count] = u8Entered_character ;
			
			break;
	} while (1);
	
	for (u8Count = 0 ;u8Count < MAXIMUM_NUMBER_OF_LETTERS ; u8Count ++)
	{
		if (u8Entered_ID[u8Count] == u8Actual_ID[u8Count])
		{
			u8ID_check ++;
		}
		else
		{
		}
	}
	
	LCD_COMMAND(SECOND_LINE_START);
	
	LCD_DATA_STRING(u8Statement_pHome_2 , u8Statement_pHome_2_size);
	
	do
	{
		for (u8Count = 0;u8Count < MAXIMUM_NUMBER_OF_LETTERS; u8Count ++)
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
					
			u8Entered_character = gu8Key_pad[u8Captured_row][u8Captured_column];
					
			if (u8Entered_character == '-')
			{
				break;
			}
			else
			{
			}
					
			LCD_DATA('*');
					
			u8Entered_password[u8Count] = u8Entered_character ;
		}
				
				
	} while (u8Entered_character != '-');
			
	for (u8Count = 0 ;u8Count < MAXIMUM_NUMBER_OF_LETTERS ; u8Count ++)
	{
		if (u8Entered_password[u8Count] == u8Actual_password[u8Count])
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
		if (u8Key_sequence == 0)
		{
			u8Entered_character = 'A';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 1)
		{
			u8Entered_character = 'B';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 2)
		{
			u8Entered_character = 'C';
			u8Key_sequence = '5' ;
		}
	}
	
	if (u8Temp_character == '3')
	{
		if (u8Key_sequence == 0)
		{
			u8Entered_character = 'D';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 1)
		{
			u8Entered_character = 'E';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 2)
		{
			u8Entered_character = 'F';
			u8Key_sequence = '5' ;
		}
	}
	
	if (u8Temp_character == '4')
	{
		if (u8Key_sequence == 0)
		{
			u8Entered_character = 'G';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 1)
		{
			u8Entered_character = 'H';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 2)
		{
			u8Entered_character = 'I';
			u8Key_sequence = '5' ;
		}
	}
	
	if (u8Temp_character == '5')
	{
		if (u8Key_sequence == 0)
		{
			u8Entered_character = 'J';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 1)
		{
			u8Entered_character = 'K';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 2)
		{
			u8Entered_character = 'L';
			u8Key_sequence = '5' ;
		}
	}
	
	if (u8Temp_character == '6')
	{
		if (u8Key_sequence == 0)
		{
			u8Entered_character = 'M';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 1)
		{
			u8Entered_character = 'N';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 2)
		{
			u8Entered_character = 'O';
			u8Key_sequence = '5' ;
		}
	}
	
	if (u8Temp_character == '7')
	{
		if (u8Key_sequence == 0)
		{
			u8Entered_character = 'P';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 1)
		{
			u8Entered_character = 'Q';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 2)
		{
			u8Entered_character = 'R';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 3)
		{
			u8Entered_character = 'S';
			u8Key_sequence = '5' ;
		}
	}
	
	if (u8Temp_character == '8')
	{
		if (u8Key_sequence == 0)
		{
			u8Entered_character = 'T';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 1)
		{
			u8Entered_character = 'U';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 2)
		{
			u8Entered_character = 'V';
			u8Key_sequence = '5' ;
		}
	}
	
	if (u8Temp_character == '9')
	{
		if (u8Key_sequence == 0)
		{
			u8Entered_character = 'W';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 1)
		{
			u8Entered_character = 'X';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 2)
		{
			u8Entered_character = 'Y';
			u8Key_sequence ++ ;
		}
		else if (u8Key_sequence == 3)
		{
			u8Entered_character = 'Z';
			u8Key_sequence = '5' ;
		}
	}
}
