/*
 * LCD_INTERFACE.c
 *
 * Created: 5/17/2019 1:36:16 PM
 *  Author: A.Elkady
 */ 

#include "LCD_INTERFACE.h"

extern void RW_STATE(uint8_t u8State)
{
	Pin_mode(RW_PORT, RW_DDR , RW_PIN_NUMBER , OUTPUT);

	if (u8State == RW_WRITE)
	{
		Pin_reset(RW_PORT , RW_PIN_NUMBER);
	}
	else if (u8State == RW_READ)
	{
		Pin_set(RW_PORT , RW_PIN_NUMBER);
	}
	else
	{
		
	}
}

extern void RS_STATE(uint8_t u8State)
{
	Pin_mode(RS_PORT, RS_DDR , RS_PIN_NUMBER , OUTPUT);

	if (u8State == RS_COMMAND)
	{
		Pin_reset(RS_PORT , RS_PIN_NUMBER);
	}
	else if (u8State == RS_DATA)
	{
		Pin_set(RS_PORT , RS_PIN_NUMBER);
	}
	else
	{
		
	}
}

extern void ENABLE_STATE(uint8_t u8State)
{
	Pin_mode(ENABLE_PORT, ENABLE_DDR , ENABLE_PIN_NUMBER , OUTPUT);

	if (u8State == ENABLE_LOW)
	{
		Pin_reset(ENABLE_PORT , ENABLE_PIN_NUMBER);
	}
	else if (u8State == ENABLE_HIGH)
	{
		Pin_set(ENABLE_PORT , ENABLE_PIN_NUMBER);
	}
	else
	{
		
	}
}

extern void HIGH_TO_LOW_PULSE()
{
	ENABLE_STATE(ENABLE_HIGH);
	_delay_us(PULSE_WIDTH);
	ENABLE_STATE(ENABLE_LOW);
	_delay_us(20);  
}

extern void LCD_COMMAND(uint8_t u8Command)
{
	*((unsigned int *)(D4_PORT)) =(*((unsigned int *)(D4_PORT)) & 0x0F) | (u8Command & 0xF0) ;
	RS_STATE(RS_COMMAND);
	RW_STATE(RW_WRITE);
	HIGH_TO_LOW_PULSE();
	
	 *((unsigned int *)(D4_PORT)) = u8Command << 4;
	 HIGH_TO_LOW_PULSE();
}

extern void LCD_DATA(uint8_t u8Data)
{
	*((unsigned int *)(D4_PORT)) = (*((unsigned int *)(D4_PORT)) & 0x0F) | (u8Data & 0xF0) ;
	RS_STATE(RS_DATA);
	RW_STATE(RW_WRITE);
	HIGH_TO_LOW_PULSE();
	
	*((unsigned int *)(D4_PORT)) = u8Data << 4;
	HIGH_TO_LOW_PULSE();
}

extern void LCD_DATA_STRING(uint8_t *pu8Data , uint8_t u8Size)
{
	uint8_t u8Count = 0;
	
	for (u8Count = 0; u8Count < u8Size - 1 ; u8Count ++)
	{
		LCD_DATA(pu8Data[u8Count]);
	}
	LCD_COMMAND(SHIFT_CURSOR_POSITION_RIGHT);
}

extern void LCD_CERTAIN_DATA(char u8Data)
{
	*((unsigned int *)(D4_PORT)) = (*((unsigned int *)(D4_PORT)) & 0x0F) | (u8Data & 0xF0) ;
	RS_STATE(RS_DATA);
	RW_STATE(RW_WRITE);
	HIGH_TO_LOW_PULSE();
	
	*((unsigned int *)(D4_PORT)) = u8Data << 4;
	HIGH_TO_LOW_PULSE();
}

extern void LCD_DATA_CERTAIN_STRING(char *pu8Data , uint8_t u8Size)
{
	uint8_t u8Count = 0;
	
	for (u8Count = 0; u8Count < u8Size ; u8Count ++)
	{
		LCD_CERTAIN_DATA(pu8Data[u8Count]);
	}
	
}

extern void LCD_INIT()
{
	Pin_mode(RW_PORT, RW_DDR , RW_PIN_NUMBER , OUTPUT);
	Pin_mode(RS_PORT, RS_DDR , RS_PIN_NUMBER , OUTPUT);
	Pin_mode(ENABLE_PORT, ENABLE_DDR , ENABLE_PIN_NUMBER , OUTPUT);
	
	Pin_mode(D4_PORT, D4_DDR , D4_PIN_NUMBER , OUTPUT);
	Pin_mode(D5_PORT, D5_DDR , D5_PIN_NUMBER , OUTPUT);
	Pin_mode(D6_PORT, D6_DDR , D6_PIN_NUMBER , OUTPUT);
	Pin_mode(D7_PORT, D7_DDR , D7_PIN_NUMBER , OUTPUT);
	
	ENABLE_STATE(ENABLE_LOW);
	_delay_us(2000);
	
	LCD_COMMAND(INITIALIZE_COMMAND_1); 
	_delay_us(100);
	LCD_COMMAND(INITIALIZE_COMMAND_2); 
	_delay_us(100);
	LCD_COMMAND(BIT_MODE4); 
	_delay_us(100);
	LCD_COMMAND(DISPLAY_ON_CURSOR_BLINKING); 
	_delay_us(100);
	LCD_COMMAND(CLEAR_DISPLAY); 
	_delay_us(2000);
	LCD_COMMAND(SHIFT_CURSOR_RIGHT); 
	_delay_us(100);
	
}

