/*
 * LCD_HELLO.c
 *
 * Created: 5/20/2019 7:25:31 PM
 *  Author: A.Elkady
 */ 

#include "LCD_HELLO.h"

static unsigned char u8Statement1[16] = {"  AMIT LEARNING "};
static unsigned char u8Statement2[16] = {"Hello World !!.."};
	
uint8_t u8Statement1_size = sizeof(u8Statement1);
uint8_t u8Statement2_size = sizeof(u8Statement2);
	
static uint8_t u8Button0_reading = 0;
static uint8_t u8Button1_reading = 0;
static uint8_t u8Button2_reading = 0;

extern void LCD_HELLO()
{
	LCD_COMMAND(CLEAR_DISPLAY);
	_delay_us(2000);
	LCD_COMMAND(SHIFT_CURSOR_RIGHT);
	_delay_us(100);
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_STRING(u8Statement1 , u8Statement1_size);
	
	LCD_COMMAND(SECOND_LINE_START);
	LCD_DATA_STRING(u8Statement2 , u8Statement2_size);
	
	do
	{
		BUTTON0_READ(&u8Button0_reading);
		BUTTON1_READ(&u8Button1_reading);
		BUTTON2_READ(&u8Button2_reading);
		
	} while ((u8Button0_reading == 0) & (u8Button1_reading == 0) & (u8Button2_reading == 0) );
	
	
}
