/*
 * KEYPAD_INTERFACE.c
 *
 * Created: 5/24/2019 9:38:37 AM
 *  Author: A.Elkady
 */ 

#include "KEYPAD_INTERFACE.h"

extern void POWER_ROW1()
{
	Pin_set(ROW1_PORT , ROW1_PIN_NUMBER);
}

extern void POWER_ROW2()
{
	Pin_set(ROW2_PORT , ROW2_PIN_NUMBER);
}

extern void POWER_ROW3()
{
	Pin_set(ROW3_PORT , ROW3_PIN_NUMBER);
}

extern void POWER_ROW4()
{
	Pin_set(ROW4_PORT , ROW4_PIN_NUMBER);
}

extern void POWER_ALL_ROWS()
{
	POWER_ROW1();
	POWER_ROW2();
	POWER_ROW3();
	POWER_ROW4();
}

extern void GROUND_ALL_ROWS()
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

extern void SET_ROWS_INPUT()
{
	Pin_mode(ROW1_PORT , ROW1_DDR , ROW1_PIN_NUMBER , INPUT);
	Pin_mode(ROW2_PORT , ROW2_DDR , ROW2_PIN_NUMBER , INPUT);
	Pin_mode(ROW3_PORT , ROW3_DDR , ROW3_PIN_NUMBER , INPUT);
	Pin_mode(ROW4_PORT , ROW4_DDR , ROW4_PIN_NUMBER , INPUT);

}

extern void SET_ROWS_OUTPUT()
{
	Pin_mode(ROW1_PORT , ROW1_DDR , ROW1_PIN_NUMBER , OUTPUT);
	Pin_mode(ROW2_PORT , ROW2_DDR , ROW2_PIN_NUMBER , OUTPUT);
	Pin_mode(ROW3_PORT , ROW3_DDR , ROW3_PIN_NUMBER , OUTPUT);
	Pin_mode(ROW4_PORT , ROW4_DDR , ROW4_PIN_NUMBER , OUTPUT);

}

extern void POWER_COLUMN1()
{
	Pin_set(COLUMN1_PORT , COLUMN1_PIN_NUMBER);
}

extern void POWER_COLUMN2()
{
	Pin_set(COLUMN2_PORT , COLUMN2_PIN_NUMBER);
}

extern void POWER_COLUMN3()
{
	Pin_set(COLUMN3_PORT , COLUMN3_PIN_NUMBER);
}

extern void POWER_COLUMN4()
{
	Pin_set(COLUMN4_PORT , COLUMN4_PIN_NUMBER);
}

extern void POWER_ALL_COLUMNS()
{
	POWER_COLUMN1();
	POWER_COLUMN2();
	POWER_COLUMN3();
	POWER_COLUMN4();
}

extern void GROUND_ALL_COLUMNS()
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

extern void SET_COLUMNS_INPUT()
{
	Pin_mode(COLUMN1_PORT , COLUMN1_DDR , COLUMN1_PIN_NUMBER , INPUT);
	Pin_mode(COLUMN2_PORT , COLUMN2_DDR , COLUMN2_PIN_NUMBER , INPUT);
	Pin_mode(COLUMN3_PORT , COLUMN3_DDR , COLUMN3_PIN_NUMBER , INPUT);
	Pin_mode(COLUMN4_PORT , COLUMN4_DDR , COLUMN4_PIN_NUMBER , INPUT);
}

extern void SET_COLUMNS_OUTPUT()
{
	Pin_mode(COLUMN1_PORT , COLUMN1_DDR , COLUMN1_PIN_NUMBER , OUTPUT);
	Pin_mode(COLUMN2_PORT , COLUMN2_DDR , COLUMN2_PIN_NUMBER , OUTPUT);
	Pin_mode(COLUMN3_PORT , COLUMN3_DDR , COLUMN3_PIN_NUMBER , OUTPUT);
	Pin_mode(COLUMN4_PORT , COLUMN4_DDR , COLUMN4_PIN_NUMBER , OUTPUT);
}

extern void ACTIVATE_PULL_UP_RESISTORS()
{
	Pin_set(COLUMN1_PORT , COLUMN1_PIN_NUMBER);
	Pin_set(COLUMN2_PORT , COLUMN2_PIN_NUMBER);
	Pin_set(COLUMN3_PORT , COLUMN3_PIN_NUMBER);
	Pin_set(COLUMN4_PORT , COLUMN4_PIN_NUMBER);
}
