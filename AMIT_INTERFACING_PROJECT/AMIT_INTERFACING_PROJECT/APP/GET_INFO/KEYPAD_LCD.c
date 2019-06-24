/*
 * KEYPAD_LCD.c
 *
 * Created: 5/25/2019 5:46:42 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "KEYPAD_LCD.h"

/************************************************************************/
/*          Declaration of global variables from other files            */
/************************************************************************/
extern const unsigned char gu8Key_pad[4][4];
extern volatile uint8_t gu8Password_right;
extern volatile uint8_t gu8ID_right ;

extern signed char c8Actual_ID[MAXIMUM_NUMBER_OF_LETTERS];
extern signed char c8Actual_password[MAXIMUM_NUMBER_OF_LETTERS];
extern char gc8EEPROM_address_of_number_of_entries ;

/************************************************************************/
/*                     Static variables definition                      */
/************************************************************************/
static volatile char gu8Entered_character_ID = 0;
static volatile char gu8Entered_character_password = 0;

static uint8_t gu8Key1_sequence = 0;
static uint8_t gu8Key2_sequence = 0;
static uint8_t gu8Key3_sequence = 0;
static uint8_t gu8Key4_sequence = 0;
static uint8_t gu8Key5_sequence = 0;
static uint8_t gu8Key6_sequence = 0;
static uint8_t gu8Key7_sequence = 0;
static uint8_t gu8Key8_sequence = 0;

static uint8_t gu8Column1_reading = 0;
static uint8_t gu8Column2_reading = 0;
static uint8_t gu8Column3_reading = 0;
static uint8_t gu8Column4_reading = 0;

static uint8_t gu8Row1_reading = 0;
static uint8_t gu8Row2_reading = 0;
static uint8_t gu8Row3_reading = 0;
static uint8_t gu8Row4_reading = 0;

/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/
extern void GET_LOGIN_INFO(void)
{
	/************************************************************************/
	/*               Local variables of GET_LOGIN_INFO function             */
	/************************************************************************/
	uint8_t u8Count1 = 0;
	uint8_t u8Count2 = 0;
	uint8_t u8Comparison_result = 0 ;
	uint8_t u8Temp_character = 0;
	
	char c8Entered_password[MAXIMUM_NUMBER_OF_LETTERS] = {0};
	char c8Entered_ID[MAXIMUM_NUMBER_OF_LETTERS] = {0};
	
	/************************************************************************/
	/*               Initialization of used global variables                */
	/************************************************************************/	
	gu8Entered_character_ID = 0;
	gu8Entered_character_password = 0;
	gu8Password_right = 0;
	gu8ID_right = 0;
	
	/************************************************************************/
	/*                            LCD printing                              */
	/************************************************************************/
	LCD_CLEAR();
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_CERTAIN_STRING("ID : ", 5);
	
	LCD_COMMAND(SHIFT_CURSOR_POSITION_LEFT);
	
	/************************************************************************/
	/* Loop1 : Do loop to continue entry operation till pressing Enter key  */
	/************************************************************************/
	do
	{
		/************************************************************************/
		/* Loop2 : For loop to enter a number of characters                     */
		/************************************************************************/
		for (u8Count1 = 0; u8Count1 < MAXIMUM_NUMBER_OF_LETTERS; u8Count1 ++)
		{	
			u8Temp_character = 0;
			
			/************************************************************************/
			/* Loop 3 : For loop to change the entered character to the system      */
			/************************************************************************/
			for (u8Count2 = 0 ; u8Count2 < MAXIMUM_NUMBER_OF_KEY_SEQUENCE ; u8Count2 ++)
			{
				GET_PRESSED_KEY(&u8Temp_character);
				
				if (u8Temp_character == 's' || u8Temp_character == 'o')
				{
					break;
				}
				
				else
				{
					ANALYZE_PRESS(u8Temp_character);  // This function directly affects gu8Entered_character_ID
					
					LCD_DATA(gu8Entered_character_ID);
					
					LCD_COMMAND(SHIFT_CURSOR_POSITION_LEFT);
				}
				
			} 
			/************************************************************************/
			/* Loop3 : End of loop 3                                                */
			/************************************************************************/
			
			c8Entered_ID[u8Count1] = gu8Entered_character_ID ;
			
			if (u8Temp_character == 'o') // 'o' is Enter
			{
				break ;
			}
			else if (u8Temp_character == 's') // 's' is Shift
			{	
				LCD_COMMAND(SHIFT_CURSOR_POSITION_RIGHT);
				continue;
			}
			else
			{
			}
				
		}
		/************************************************************************/
		/* Loop 2 : End of loop 2                                               */
		/************************************************************************/
		break;
		
	} while (gu8Entered_character_ID != 'o');
	/************************************************************************/
	/* Loop 1 : End of loop 1                                               */
	/************************************************************************/
	
	
	
	
	/************************************************************************/
	/*                            LCD Printing                              */
	/************************************************************************/
	LCD_COMMAND(SECOND_LINE_START);

	LCD_DATA_CERTAIN_STRING("PASS: ",6);
	
	LCD_COMMAND(SHIFT_CURSOR_POSITION_LEFT);
	
	/************************************************************************/
	/* Loop1 : Do loop to continue entry operation till pressing Enter key  */
	/************************************************************************/
	do
	{
		/************************************************************************/
		/* Loop2 : For loop to enter a number of characters                     */
		/************************************************************************/
		
		for (u8Count1 = 0;u8Count1 < MAXIMUM_NUMBER_OF_LETTERS; u8Count1 ++)
		{
			GET_PRESSED_KEY(&u8Temp_character);
					
			if (u8Temp_character == 'o')
			{
				break;
			}
			else
			{
			}
					
			LCD_DATA('*');
					
			c8Entered_password[u8Count1] = u8Temp_character ;
		}
		/************************************************************************/
		/* Loop 2 : End of loop 2                                               */
		/************************************************************************/
		break;
			
	} while (u8Temp_character != 'o');
	
	/************************************************************************/
	/* Loop 1 : End of loop 1                                               */
	/************************************************************************/
	
	
	/************************************************************************/
	/* ID & Password check                                                       */
	/************************************************************************/		
	u8Comparison_result = COMPARE_LOGIN_INFO(c8Entered_ID , c8Entered_password);
	
	
	/************************************************************************/
	/* Decision to make whether the received data is right or not           */
	/************************************************************************/
	
	
	/************************************************************************/
	/*             If the entered data is right (registered)                */
	/************************************************************************/
	if (u8Comparison_result != 0)
	{
		gu8ID_right ++ ;
		gu8Password_right ++ ;
		
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("Ok ..!!" , 7);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("Unlocking .." , 12);
		
		BUZZER_ON();
		_delay_ms(300);
		BUZZER_OFF();
	} 
	/************************************************************************/
	/*             If the entered data is  not right ( not registered )     */
	/************************************************************************/
	else
	{
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("WRONG ID/PASS !!" , 16);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("Try Again ......", 16);
		
		BUZZER_FLICKER();
	}
	
}

extern void GET_KEY_ROW(uint8_t *pgu8Captured_row)
{
	/************************************************************************/
	/*                Preparing row detection operation                     */
	/************************************************************************/
	SET_ROWS_INPUT();
	POWER_ALL_ROWS(); // To activate pull up resistors
	
	SET_COLUMNS_OUTPUT();
	GROUND_ALL_COLUMNS();
	
	/************************************************************************/
	/* Temporarily infinite loop that exits when the right row is detected  */
	/************************************************************************/
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

extern void GET_KEY_COLUMN(uint8_t *pgu8Captured_column)
{
	/************************************************************************/
	/*                Preparing column detection operation                  */
	/************************************************************************/

	SET_COLUMNS_INPUT();
	POWER_ALL_COLUMNS(); // To activate pull up resistors
	
	SET_ROWS_OUTPUT();
	GROUND_ALL_ROWS();
	
	/************************************************************************/
	/*Temporarily infinite loop that exits when the right column is detected*/
	/************************************************************************/
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

extern void ANALYZE_PRESS(uint8_t u8Temp_character )
{
	
	if (u8Temp_character == '2')
	{	
		// Resetting the upcoming seven variables is necessary to start from the right sequence for the other buttons
		gu8Key2_sequence = 0;
		gu8Key3_sequence = 0;
		gu8Key4_sequence = 0;
		gu8Key5_sequence = 0;
		gu8Key6_sequence = 0;
		gu8Key7_sequence = 0;
		gu8Key8_sequence = 0;
		
		if (gu8Key1_sequence == 0)
		{
			gu8Entered_character_ID = 'A';
			gu8Key1_sequence ++ ;
		}
		else if (gu8Key1_sequence == 1)
		{
			gu8Entered_character_ID = 'B';
			gu8Key1_sequence ++ ;
		}
		else if (gu8Key1_sequence == 2)
		{
			gu8Entered_character_ID = 'C';
			gu8Key1_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '3')
	{	
		gu8Key1_sequence = 0;
		gu8Key3_sequence = 0;
		gu8Key4_sequence = 0;
		gu8Key5_sequence = 0;
		gu8Key6_sequence = 0;
		gu8Key7_sequence = 0;
		gu8Key8_sequence = 0;
		
		if (gu8Key2_sequence == 0)
		{
			gu8Entered_character_ID = 'D';
			gu8Key2_sequence ++ ;
		}
		else if (gu8Key2_sequence == 1)
		{
			gu8Entered_character_ID = 'E';
			gu8Key2_sequence ++ ;
		}
		else if (gu8Key2_sequence == 2)
		{
			gu8Entered_character_ID = 'F';
			gu8Key2_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '4')
	{	
		gu8Key2_sequence = 0;
		gu8Key1_sequence = 0;
		gu8Key4_sequence = 0;
		gu8Key5_sequence = 0;
		gu8Key6_sequence = 0;
		gu8Key7_sequence = 0;
		gu8Key8_sequence = 0;
		
		if (gu8Key3_sequence == 0)
		{
			gu8Entered_character_ID = 'G';
			gu8Key3_sequence ++ ;
		}
		else if (gu8Key3_sequence == 1)
		{
			gu8Entered_character_ID = 'H';
			gu8Key3_sequence ++ ;
		}
		else if (gu8Key3_sequence == 2)
		{
			gu8Entered_character_ID = 'I';
			gu8Key3_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '5')
	{
		gu8Key2_sequence = 0;
		gu8Key3_sequence = 0;
		gu8Key1_sequence = 0;
		gu8Key5_sequence = 0;
		gu8Key6_sequence = 0;
		gu8Key7_sequence = 0;
		gu8Key8_sequence = 0;
		
		if (gu8Key4_sequence == 0)
		{
			gu8Entered_character_ID = 'J';
			gu8Key4_sequence ++ ;
		}
		else if (gu8Key4_sequence == 1)
		{
			gu8Entered_character_ID = 'K';
			gu8Key4_sequence ++ ;
		}
		else if (gu8Key4_sequence == 2)
		{
			gu8Entered_character_ID = 'L';
			gu8Key4_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '6')
	{
		gu8Key2_sequence = 0;
		gu8Key3_sequence = 0;
		gu8Key4_sequence = 0;
		gu8Key1_sequence = 0;
		gu8Key6_sequence = 0;
		gu8Key7_sequence = 0;
		gu8Key8_sequence = 0;
		
		if (gu8Key5_sequence == 0)
		{
			gu8Entered_character_ID = 'M';
			gu8Key5_sequence ++ ;
		}
		else if (gu8Key5_sequence == 1)
		{
			gu8Entered_character_ID = 'N';
			gu8Key5_sequence ++ ;
		}
		else if (gu8Key5_sequence == 2)
		{
			gu8Entered_character_ID = 'O';
			gu8Key5_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '7')
	{
		gu8Key2_sequence = 0;
		gu8Key3_sequence = 0;
		gu8Key4_sequence = 0;
		gu8Key5_sequence = 0;
		gu8Key1_sequence = 0;
		gu8Key7_sequence = 0;
		gu8Key8_sequence = 0;
		
		if (gu8Key6_sequence == 0)
		{
			gu8Entered_character_ID = 'P';
			gu8Key6_sequence ++ ;
		}
		else if (gu8Key6_sequence == 1)
		{
			gu8Entered_character_ID = 'Q';
			gu8Key6_sequence ++ ;
		}
		else if (gu8Key6_sequence == 2)
		{
			gu8Entered_character_ID = 'R';
			gu8Key6_sequence ++ ;
		}
		else if (gu8Key6_sequence == 3)
		{
			gu8Entered_character_ID = 'S';
			gu8Key6_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '8')
	{
		gu8Key2_sequence = 0;
		gu8Key3_sequence = 0;
		gu8Key4_sequence = 0;
		gu8Key5_sequence = 0;
		gu8Key6_sequence = 0;
		gu8Key1_sequence = 0;
		gu8Key8_sequence = 0;
		
		if (gu8Key7_sequence == 0)
		{
			gu8Entered_character_ID = 'T';
			gu8Key7_sequence ++ ;
		}
		else if (gu8Key7_sequence == 1)
		{
			gu8Entered_character_ID = 'U';
			gu8Key7_sequence ++ ;
		}
		else if (gu8Key7_sequence == 2)
		{
			gu8Entered_character_ID = 'V';
			gu8Key7_sequence = 0 ;
		}
	}
	
	else if (u8Temp_character == '9')
	{
		gu8Key2_sequence = 0;
		gu8Key3_sequence = 0;
		gu8Key4_sequence = 0;
		gu8Key5_sequence = 0;
		gu8Key6_sequence = 0;
		gu8Key7_sequence = 0;
		gu8Key1_sequence = 0;
		
		if (gu8Key8_sequence == 0)
		{
			gu8Entered_character_ID = 'W';
			gu8Key8_sequence ++ ;
		}
		else if (gu8Key8_sequence == 1)
		{
			gu8Entered_character_ID = 'X';
			gu8Key8_sequence ++ ;
		}
		else if (gu8Key8_sequence == 2)
		{
			gu8Entered_character_ID = 'Y';
			gu8Key8_sequence ++ ;
		}
		else if (gu8Key8_sequence == 3)
		{
			gu8Entered_character_ID = 'Z';
			gu8Key8_sequence = 0 ;
		}
	}
	else
	{
		
	}
}

extern void SIGN_UP(void)
{
	/************************************************************************/
	/*               Local variables of GET_LOGIN_INFO function             */
	/************************************************************************/
	uint8_t u8Count1 = 0;
	uint8_t u8Count2 = 0;
	uint8_t u8Password_check = 0;
	uint8_t u8Temp_character = 0;
	
	char c8Entered_password_1[MAXIMUM_NUMBER_OF_LETTERS] = {0};
	char c8Entered_password_2[MAXIMUM_NUMBER_OF_LETTERS] = {0};
	char c8Entered_ID[MAXIMUM_NUMBER_OF_LETTERS] = {0};
	
	/************************************************************************/
	/*               Initialization of used global variables                */
	/************************************************************************/
	gu8Entered_character_ID = 0;
	gu8Entered_character_password = 0;
	gu8Password_right = 0;
	gu8ID_right = 0;
	
	/************************************************************************/
	/*                            LCD printing                              */
	/************************************************************************/
	LCD_CLEAR();
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_CERTAIN_STRING("Enter username :", 16);
	
	LCD_COMMAND(SECOND_LINE_START);	
	/************************************************************************/
	/* Loop1 : Do loop to continue entry operation till pressing Enter key  */
	/************************************************************************/
	do
	{
		/************************************************************************/
		/* Loop2 : For loop to enter a number of characters                     */
		/************************************************************************/
		for (u8Count1 = 0; u8Count1 < MAXIMUM_NUMBER_OF_LETTERS; u8Count1 ++)
		{
			u8Temp_character = 0;
			
			/************************************************************************/
			/* Loop 3 : For loop to change the entered character to the system      */
			/************************************************************************/
			for (u8Count2 = 0 ; u8Count2 < MAXIMUM_NUMBER_OF_KEY_SEQUENCE ; u8Count2 ++)
			{
				GET_PRESSED_KEY(&u8Temp_character);
				
				if (u8Temp_character == 's' || u8Temp_character == 'o')
				{
					break;
				}
				
				else
				{
					ANALYZE_PRESS(u8Temp_character);  // This function directly affects gu8Entered_character_ID
					
					LCD_DATA(gu8Entered_character_ID);
					
					LCD_COMMAND(SHIFT_CURSOR_POSITION_LEFT);
				}
				
			}
			/************************************************************************/
			/* Loop3 : End of loop 3                                                */
			/************************************************************************/
			
			c8Entered_ID[u8Count1] = gu8Entered_character_ID ;
			
			if (u8Temp_character == 'o') // 'o' is Enter
			{
				break ;
			}
			else if (u8Temp_character == 's') // 's' is Shift
			{
				LCD_COMMAND(SHIFT_CURSOR_POSITION_RIGHT);
				continue;
			}
			else
			{
			}
			
		}
		/************************************************************************/
		/* Loop 2 : End of loop 2                                               */
		/************************************************************************/
		break;
		
	} while (gu8Entered_character_ID != 'o');
	/************************************************************************/
	/* Loop 1 : End of loop 1                                               */
	/************************************************************************/


	/************************************************************************/
	/*                            LCD Printing                              */
	/************************************************************************/
	
	LCD_CLEAR();
	LCD_COMMAND(FIRST_LINE_START);

	LCD_DATA_CERTAIN_STRING("Enter password :" , 16);
	
	LCD_COMMAND(SECOND_LINE_START);
	
	/************************************************************************/
	/* Loop1 : Do loop to continue entry operation till pressing Enter key  */
	/************************************************************************/
	do
	{
		/************************************************************************/
		/* Loop2 : For loop to enter a number of characters                     */
		/************************************************************************/
		
		for (u8Count1 = 0;u8Count1 < MAXIMUM_NUMBER_OF_LETTERS; u8Count1 ++)
		{
			GET_PRESSED_KEY(&u8Temp_character);
			
			if (u8Temp_character == 'o')
			{
				break;
			}
			else
			{
			}
			
			LCD_DATA('*');
			
			c8Entered_password_1[u8Count1] = u8Temp_character ;
		}
		/************************************************************************/
		/* Loop 2 : End of loop 2                                               */
		/************************************************************************/
		break;
		
	} while (u8Temp_character != 'o');
	
	/************************************************************************/
	/* Loop 1 : End of loop 1                                               */
	/************************************************************************/
	
		/************************************************************************/
		/*                            LCD Printing                              */
		/************************************************************************/
		
		LCD_CLEAR();
		LCD_COMMAND(FIRST_LINE_START);

		LCD_DATA_CERTAIN_STRING("Repeat password:" , 16);
		
		LCD_COMMAND(SECOND_LINE_START);
		
	/************************************************************************/
	/* Loop1 : Do loop to continue entry operation till pressing Enter key  */
	/************************************************************************/
	do
	{
		/************************************************************************/
		/* Loop2 : For loop to enter a number of characters                     */
		/************************************************************************/
			
		for (u8Count1 = 0;u8Count1 < MAXIMUM_NUMBER_OF_LETTERS; u8Count1 ++)
		{
			GET_PRESSED_KEY(&u8Temp_character);
				
			if (u8Temp_character == 'o')
			{
				break;
			}
			else
			{
			}
				
			LCD_DATA('*');
				
			c8Entered_password_2[u8Count1] = u8Temp_character ;
		}
		/************************************************************************/
		/* Loop 2 : End of loop 2                                               */
		/************************************************************************/
		break;
			
	} while (u8Temp_character != 'o');
		
	/************************************************************************/
	/* Loop 1 : End of loop 1                                               */
	/************************************************************************/

	
	/************************************************************************/
	/* Password check                                                       */
	/************************************************************************/
	for (u8Count1 = 0 ;u8Count1 < MAXIMUM_NUMBER_OF_LETTERS ; u8Count1 ++)
	{
		if (c8Entered_password_1[u8Count1] == c8Entered_password_2[u8Count1])
		{
			u8Password_check ++;
		}
		else
		{
		}
	}
	
	/************************************************************************/
	/* Decision to make if the received data is right or not                */
	/************************************************************************/
	
	
	/************************************************************************/
	/*             If the entered data is right (registered)                */
	/************************************************************************/
	if (u8Password_check == MAXIMUM_NUMBER_OF_LETTERS)
	{
		
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("Ok ..!!" , 7);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("ID saved" , 8);
		
		BUZZER_ON();
		_delay_ms(300);
		BUZZER_OFF();
		
		INTERNAL_EEPROM_ENTER_ID(c8Entered_ID) ;
		INTERNAL_EEPROM_ENTER_PASSWORD(c8Entered_password_1);
		
		gc8EEPROM_address_of_number_of_entries ++ ;
		INTERNAL_EEPROM_WRITE(EEPROM_ADDRESS_OF_NUMBER_OF_ENTRIES , gc8EEPROM_address_of_number_of_entries);

	}
	/************************************************************************/
	/*             If the entered data is  not right ( not registered )     */
	/************************************************************************/
	else
	{
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("No pass. match" , 14);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("Try Again ......", 16);
		
		BUZZER_FLICKER();
	}
	
}

extern uint8_t COMPARE_LOGIN_INFO(char *pc8ID , char *pc8Password)
{
	uint8_t u8Count1 = 0 ;
	uint8_t u8ID_comparison_result = 0 ;
	uint8_t u8Password_comparison_result = 0 ;
	char c8ID[10] = {0};
	char c8Password[10] = {0};
	
	for (u8Count1 = 0 ; u8Count1 < 10 ; u8Count1 ++)
	{
		INTERNAL_EEPROM_READ_STRING((uint16_t) (20 + (u8Count1 * 10)) , c8ID );
		INTERNAL_EEPROM_READ_STRING((uint16_t) (30 + (u8Count1 * 10)) , c8Password );
		
		u8ID_comparison_result = STRING_COMPARE(c8ID , pc8ID , 10);
		u8Password_comparison_result = STRING_COMPARE(c8Password , pc8Password , 10);
		
		if (u8ID_comparison_result != 0 && u8Password_comparison_result != 0 )
		{
			return 1 ;
		} 
		else
		{
		}
	}
	return 0 ;
}

extern uint8_t SIGN_UP_OR_IN_PAGE(void)
{
	uint8_t u8Press_value = 0 ;

	LCD_CLEAR();
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_CERTAIN_STRING("1) SIGN UP" , 10);
	
	LCD_COMMAND(SECOND_LINE_START);
	LCD_DATA_CERTAIN_STRING("2) SIGN IN" , 10);
	
	GET_PRESSED_KEY(&u8Press_value);

	if (u8Press_value == '1' )
	{
		return 1 ;
	} 
	else if (u8Press_value == '2')
	{
		return 2 ;
	}
	else
	{
		return 0 ;
	}
	
}

extern uint8_t KIT_OR_BT_CONTROL()
{
	uint8_t u8Press_value = 0 ;
	
	LCD_CLEAR();
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_CERTAIN_STRING("1) KIT CONTROL" , 14);
	
	LCD_COMMAND(SECOND_LINE_START);
	LCD_DATA_CERTAIN_STRING("2) BT CONTROL" , 13);
	
	GET_PRESSED_KEY(&u8Press_value);

	if (u8Press_value == '1' )
	{
		return 1 ;
	}
	else if (u8Press_value == '2')
	{
		return 2 ;
	}
	else
	{
		return 0 ;
	}
}

extern void INFO_CONTROL()
{
	uint8_t u8Sign_up_or_in = 0 ;
	
	u8Sign_up_or_in = SIGN_UP_OR_IN_PAGE();
	
	if (u8Sign_up_or_in == 1)
	{
		SIGN_UP();
	} 
	else if (u8Sign_up_or_in == 2)
	{
		GET_LOGIN_INFO();
	}
	else
	{
		
	}
}

extern void KIT_CONTROL()
{
	uint8_t u8Kit_or_BT = 0 ;
	
	u8Kit_or_BT = KIT_OR_BT_CONTROL();
	
	if (u8Kit_or_BT == 1)
	{
		LCD_TEST();
	} 
	else if (u8Kit_or_BT == 2)
	{
		BT_TEST();
	}
	else
	{
		
	}
}
