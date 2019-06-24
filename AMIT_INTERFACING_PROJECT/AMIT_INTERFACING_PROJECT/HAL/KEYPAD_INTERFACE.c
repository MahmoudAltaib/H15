/*
 * KEYPAD_INTERFACE.c
 *
 * Created: 5/24/2019 9:38:37 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "KEYPAD_INTERFACE.h"



/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/

extern unsigned char gu8Key_pad[4][4];

static uint8_t gu8Column1_reading = 0;
static uint8_t gu8Column2_reading = 0;
static uint8_t gu8Column3_reading = 0;
static uint8_t gu8Column4_reading = 0;

static uint8_t gu8Row1_reading = 0;
static uint8_t gu8Row2_reading = 0;
static uint8_t gu8Row3_reading = 0;
static uint8_t gu8Row4_reading = 0;

static uint8_t gu8Captured_row = 0;
static uint8_t gu8Captured_column = 0;

extern void POWER_ROW1(void)
{
	Pin_set(ROW1_PORT , ROW1_PIN_NUMBER);
}
extern void POWER_ROW2(void)
{
	Pin_set(ROW2_PORT , ROW2_PIN_NUMBER);
}
extern void POWER_ROW3(void)
{
	Pin_set(ROW3_PORT , ROW3_PIN_NUMBER);
}
extern void POWER_ROW4(void)
{
	Pin_set(ROW4_PORT , ROW4_PIN_NUMBER);
}
extern void POWER_ALL_ROWS(void)
{
	POWER_ROW1();
	POWER_ROW2();
	POWER_ROW3();
	POWER_ROW4();
}
extern void GROUND_ALL_ROWS(void)
{
	Pin_reset(ROW1_PORT , ROW1_PIN_NUMBER);
	Pin_reset(ROW2_PORT , ROW2_PIN_NUMBER);
	Pin_reset(ROW3_PORT , ROW3_PIN_NUMBER);
	Pin_reset(ROW4_PORT , ROW4_PIN_NUMBER);
}
extern void READ_ROW1(uint8_t *pu8Reading)
{
	uint8_t u8Reading = 0;
	uint8_t u8Count = 0;
	uint8_t u8Number_of_correct_checks = 0;
	
	Pin_read(ROW1_PIN , ROW1_PIN_NUMBER , &u8Reading);
	
	if (u8Reading != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_KEYPAD_CHECKS ; u8Count ++)
		{
			Pin_read(ROW1_PIN , ROW1_PIN_NUMBER , &u8Reading);
			
			if (u8Reading != 0)
			{
				u8Number_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Number_of_correct_checks == NUMBER_OF_KEYPAD_CHECKS)
		{
			*pu8Reading = u8Reading ;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
	
}
extern void READ_ROW2(uint8_t *pu8Reading)
{
	uint8_t u8Reading = 0;
	uint8_t u8Count = 0;
	uint8_t u8Number_of_correct_checks = 0;
	
	Pin_read(ROW2_PIN , ROW2_PIN_NUMBER , &u8Reading);
	
	if (u8Reading != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_KEYPAD_CHECKS ; u8Count ++)
		{
			Pin_read(ROW2_PIN , ROW2_PIN_NUMBER , &u8Reading);
			
			if (u8Reading != 0)
			{
				u8Number_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Number_of_correct_checks == NUMBER_OF_KEYPAD_CHECKS)
		{
			*pu8Reading = u8Reading ;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
	
}
extern void READ_ROW3(uint8_t *pu8Reading)
{
	uint8_t u8Reading = 0;
	uint8_t u8Count = 0;
	uint8_t u8Number_of_correct_checks = 0;
	
	Pin_read(ROW3_PIN , ROW3_PIN_NUMBER , &u8Reading);
	
	if (u8Reading != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_KEYPAD_CHECKS ; u8Count ++)
		{
			Pin_read(ROW3_PIN , ROW3_PIN_NUMBER , &u8Reading);
			
			if (u8Reading != 0)
			{
				u8Number_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Number_of_correct_checks == NUMBER_OF_KEYPAD_CHECKS)
		{
			*pu8Reading = u8Reading ;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
	
}
extern void READ_ROW4(uint8_t *pu8Reading)
{
	uint8_t u8Reading = 0;
	uint8_t u8Count = 0;
	uint8_t u8Number_of_correct_checks = 0;
	
	Pin_read(ROW4_PIN , ROW4_PIN_NUMBER , &u8Reading);
	
	if (u8Reading != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_KEYPAD_CHECKS ; u8Count ++)
		{
			Pin_read(ROW4_PIN , ROW4_PIN_NUMBER , &u8Reading);
			
			if (u8Reading != 0)
			{
				u8Number_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Number_of_correct_checks == NUMBER_OF_KEYPAD_CHECKS)
		{
			*pu8Reading = u8Reading ;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
	
}
extern void SET_ROWS_INPUT(void)
{
	Pin_mode(ROW1_PORT , ROW1_DDR , ROW1_PIN_NUMBER , INPUT);
	Pin_mode(ROW2_PORT , ROW2_DDR , ROW2_PIN_NUMBER , INPUT);
	Pin_mode(ROW3_PORT , ROW3_DDR , ROW3_PIN_NUMBER , INPUT);
	Pin_mode(ROW4_PORT , ROW4_DDR , ROW4_PIN_NUMBER , INPUT);

}
extern void SET_ROWS_OUTPUT(void)
{
	Pin_mode(ROW1_PORT , ROW1_DDR , ROW1_PIN_NUMBER , OUTPUT);
	Pin_mode(ROW2_PORT , ROW2_DDR , ROW2_PIN_NUMBER , OUTPUT);
	Pin_mode(ROW3_PORT , ROW3_DDR , ROW3_PIN_NUMBER , OUTPUT);
	Pin_mode(ROW4_PORT , ROW4_DDR , ROW4_PIN_NUMBER , OUTPUT);

}

extern void POWER_COLUMN1(void)
{
	Pin_set(COLUMN1_PORT , COLUMN1_PIN_NUMBER);
}
extern void POWER_COLUMN2(void)
{
	Pin_set(COLUMN2_PORT , COLUMN2_PIN_NUMBER);
}
extern void POWER_COLUMN3(void)
{
	Pin_set(COLUMN3_PORT , COLUMN3_PIN_NUMBER);
}
extern void POWER_COLUMN4(void)
{
	Pin_set(COLUMN4_PORT , COLUMN4_PIN_NUMBER);
}
extern void POWER_ALL_COLUMNS(void)
{
	POWER_COLUMN1();
	POWER_COLUMN2();
	POWER_COLUMN3();
	POWER_COLUMN4();
}
extern void GROUND_ALL_COLUMNS(void)
{
	Pin_reset(COLUMN1_PORT , COLUMN1_PIN_NUMBER);
	Pin_reset(COLUMN2_PORT , COLUMN2_PIN_NUMBER);
	Pin_reset(COLUMN3_PORT , COLUMN3_PIN_NUMBER);
	Pin_reset(COLUMN4_PORT , COLUMN4_PIN_NUMBER);
}
extern void READ_COLUMN1(uint8_t *pu8Reading)
{
	uint8_t u8Reading = 0;
	uint8_t u8Count = 0;
	uint8_t u8Number_of_correct_checks = 0;
	
	Pin_read(COLUMN1_PIN , COLUMN1_PIN_NUMBER , &u8Reading);
	
	if (u8Reading != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_KEYPAD_CHECKS ; u8Count ++)
		{
			Pin_read(COLUMN1_PIN , COLUMN1_PIN_NUMBER , &u8Reading);
			
			if (u8Reading != 0)
			{
				u8Number_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Number_of_correct_checks == NUMBER_OF_KEYPAD_CHECKS)
		{
			*pu8Reading = u8Reading ; 
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
	
	
}
extern void READ_COLUMN2(uint8_t *pu8Reading)
{
	uint8_t u8Reading = 0;
	uint8_t u8Count = 0;
	uint8_t u8Number_of_correct_checks = 0;
	
	Pin_read(COLUMN2_PIN , COLUMN2_PIN_NUMBER , &u8Reading);
	
	if (u8Reading != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_KEYPAD_CHECKS ; u8Count ++)
		{
			Pin_read(COLUMN2_PIN , COLUMN2_PIN_NUMBER , &u8Reading);
			
			if (u8Reading != 0)
			{
				u8Number_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Number_of_correct_checks == NUMBER_OF_KEYPAD_CHECKS)
		{
			*pu8Reading = u8Reading ;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
}
extern void READ_COLUMN3(uint8_t *pu8Reading)
{
	uint8_t u8Reading = 0;
	uint8_t u8Count = 0;
	uint8_t u8Number_of_correct_checks = 0;
	
	Pin_read(COLUMN3_PIN , COLUMN3_PIN_NUMBER , &u8Reading);
	
	if (u8Reading != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_KEYPAD_CHECKS ; u8Count ++)
		{
			Pin_read(COLUMN3_PIN , COLUMN3_PIN_NUMBER , &u8Reading);
			
			if (u8Reading != 0)
			{
				u8Number_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Number_of_correct_checks == NUMBER_OF_KEYPAD_CHECKS)
		{
			*pu8Reading = u8Reading ;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
}
extern void READ_COLUMN4(uint8_t *pu8Reading)
{
	uint8_t u8Reading = 0;
	uint8_t u8Count = 0;
	uint8_t u8Number_of_correct_checks = 0;
	
	Pin_read(COLUMN4_PIN , COLUMN4_PIN_NUMBER , &u8Reading);
	
	if (u8Reading != 0)
	{
		for (u8Count = 0 ; u8Count < NUMBER_OF_KEYPAD_CHECKS ; u8Count ++)
		{
			Pin_read(COLUMN4_PIN , COLUMN4_PIN_NUMBER , &u8Reading);
			
			if (u8Reading != 0)
			{
				u8Number_of_correct_checks ++ ;
			}
			else
			{
				
			}
		}
		
		if (u8Number_of_correct_checks == NUMBER_OF_KEYPAD_CHECKS)
		{
			*pu8Reading = u8Reading ;
		}
		else
		{
			*pu8Reading = 0;
		}
	}
	else
	{
		*pu8Reading = 0;
	}
}
extern void SET_COLUMNS_INPUT(void)
{
	Pin_mode(COLUMN1_PORT , COLUMN1_DDR , COLUMN1_PIN_NUMBER , INPUT);
	Pin_mode(COLUMN2_PORT , COLUMN2_DDR , COLUMN2_PIN_NUMBER , INPUT);
	Pin_mode(COLUMN3_PORT , COLUMN3_DDR , COLUMN3_PIN_NUMBER , INPUT);
	Pin_mode(COLUMN4_PORT , COLUMN4_DDR , COLUMN4_PIN_NUMBER , INPUT);
}
extern void SET_COLUMNS_OUTPUT(void)
{
	Pin_mode(COLUMN1_PORT , COLUMN1_DDR , COLUMN1_PIN_NUMBER , OUTPUT);
	Pin_mode(COLUMN2_PORT , COLUMN2_DDR , COLUMN2_PIN_NUMBER , OUTPUT);
	Pin_mode(COLUMN3_PORT , COLUMN3_DDR , COLUMN3_PIN_NUMBER , OUTPUT);
	Pin_mode(COLUMN4_PORT , COLUMN4_DDR , COLUMN4_PIN_NUMBER , OUTPUT);
}
extern void ACTIVATE_PULL_UP_RESISTORS(void)
{
	Pin_set(COLUMN1_PORT , COLUMN1_PIN_NUMBER);
	Pin_set(COLUMN2_PORT , COLUMN2_PIN_NUMBER);
	Pin_set(COLUMN3_PORT , COLUMN3_PIN_NUMBER);
	Pin_set(COLUMN4_PORT , COLUMN4_PIN_NUMBER);
}

extern void GET_PRESSED_KEY(uint8_t *pu8Pressed_key)
{
	uint8_t u8Entered_character = 0 ;
	_delay_ms(3000);
	LCD_CLEAR();
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA('1');
	SET_COLUMNS_INPUT();
	POWER_ALL_COLUMNS(); // To activate pull up resistors
	
	SET_ROWS_OUTPUT();
	GROUND_ALL_ROWS();
	LCD_DATA('1');
	
	do  // To make sure that all buttons are released
	{
		READ_COLUMN1(&gu8Column1_reading);
		READ_COLUMN2(&gu8Column2_reading);
		READ_COLUMN3(&gu8Column3_reading);
		READ_COLUMN4(&gu8Column4_reading);
		
	} while (gu8Column1_reading == 0 || gu8Column2_reading == 0 || gu8Column3_reading == 0 || gu8Column4_reading == 0 );
	LCD_DATA('2');
	LCD_DATA('2');
	
	do  // To wait for a press
	{
		READ_COLUMN1(&gu8Column1_reading);
		READ_COLUMN2(&gu8Column2_reading);
		READ_COLUMN3(&gu8Column3_reading);
		READ_COLUMN4(&gu8Column4_reading);
		
	} while (gu8Column1_reading != 0 && gu8Column2_reading != 0 && gu8Column3_reading != 0 && gu8Column4_reading != 0 );
	
	BUZZER_ON();
	GET_KEY_ROW_4x4(&gu8Captured_row);
	GET_KEY_COLUMN_4x4(&gu8Captured_column);
	_delay_ms(50);
	BUZZER_OFF();
	
	u8Entered_character = gu8Key_pad[gu8Captured_row][gu8Captured_column];
	*pu8Pressed_key = u8Entered_character ;
}

extern void GET_KEY_ROW_4x4(uint8_t *pgu8Captured_row)
{
	SET_ROWS_INPUT();
	POWER_ALL_ROWS(); // To deactivate pull up resistors
	
	SET_COLUMNS_OUTPUT();
	GROUND_ALL_COLUMNS();
	
	while (1)
	{
		READ_ROW1(&gu8Row1_reading);
		
		if (gu8Row1_reading == 0)
		{
			*pgu8Captured_row = ROW1 ;
			break;
		}
		else
		{
			
		}
		
		READ_ROW2(&gu8Row2_reading);
		
		if (gu8Row2_reading == 0)
		{
			*pgu8Captured_row = ROW2 ;
			break;
		}
		else
		{
			
		}
		
		READ_ROW3(&gu8Row3_reading);
		
		if (gu8Row3_reading == 0)
		{
			*pgu8Captured_row = ROW3 ;
			break;
		}
		else
		{
			
		}
		
		READ_ROW4(&gu8Row4_reading);
		
		if (gu8Row4_reading == 0)
		{
			*pgu8Captured_row = ROW4 ;
			break;
		}
		else
		{
			
		}

	}
	
	GROUND_ALL_COLUMNS();
	
}

extern void GET_KEY_COLUMN_4x4(uint8_t *pgu8Captured_column)
{
	SET_COLUMNS_INPUT();
	POWER_ALL_COLUMNS(); // To activate pull up resistors
	
	SET_ROWS_OUTPUT();
	GROUND_ALL_ROWS();
	
	while (1)
	{
		READ_COLUMN1(&gu8Column1_reading);
		
		if (gu8Column1_reading == 0)
		{
			*pgu8Captured_column = COLUMN1 ;
			break;
		}
		else
		{
			
		}
		
		READ_COLUMN2(&gu8Column2_reading);
		
		if (gu8Column2_reading == 0)
		{
			*pgu8Captured_column = COLUMN2 ;
			break;
		}
		else
		{
			
		}
		
		READ_COLUMN3(&gu8Column3_reading);
		
		if (gu8Column3_reading == 0)
		{
			*pgu8Captured_column = COLUMN3 ;
			break;
		}
		else
		{
			
		}
		
		READ_COLUMN4(&gu8Column4_reading);
		
		if (gu8Column4_reading == 0)
		{
			*pgu8Captured_column = COLUMN4 ;
			break;
		}
		else
		{
			
		}
		
	}
	
	GROUND_ALL_ROWS();
}