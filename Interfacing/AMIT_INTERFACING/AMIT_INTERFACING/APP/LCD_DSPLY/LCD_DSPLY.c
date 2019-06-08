/*
 * LCD_DSPLY.c
 *
 * Created: 31-May-19 2:58:29 AM
 *  Author: acer
 */ 

#include "LCD_DSPLY.h"
#include "PORT_DIO.h"

extern void LCD_CMND (unsigned char cmnd)
{
	*((volatile unsigned int *)(LCD_Data_Port))= cmnd & 0xf0;
	DIO_WRITEPIN(PORTB,1,0);
	DIO_WRITEPIN(PORTB,2,0);
	
	
	DIO_WRITEPIN(PORTB,3,1);
	_delay_us (500);
	DIO_WRITEPIN(PORTB,3,0);
	_delay_us (500);
	*((volatile unsigned int *)(LCD_Data_Port)) = cmnd << 4 ;
	DIO_WRITEPIN(PORTB,3,1);
	_delay_us (500);
	DIO_WRITEPIN(PORTB,3,0);
	_delay_us (500);
		
}
extern void LCD_Data (unsigned char data)
{
	*((volatile unsigned int *)(LCD_Data_Port))= data & 0xF0;
	DIO_WRITEPIN(PORTB,1,1);
	DIO_WRITEPIN(PORTB,2,0);
	DIO_WRITEPIN(PORTB,3,1);
	_delay_us (150);
	DIO_WRITEPIN(PORTB,3,0);
	_delay_us (150);
	*((volatile unsigned int *)(LCD_Data_Port)) = data << 4 ;
	DIO_WRITEPIN(PORTB,3,1);
	_delay_us (150);
	DIO_WRITEPIN(PORTB,3,0);
	_delay_us (150);
}
extern void LCD_Init (void)
{
		DIO_PINOUT(DDRB,1);
		DIO_PINOUT(DDRB,2);
		DIO_PINOUT(DDRB,3);
		DIO_PINOUT(DDRA,4);
		DIO_PINOUT(DDRA,5);
		DIO_PINOUT(DDRA,6);
		DIO_PINOUT(DDRA,7);
	DIO_WRITEPIN(PORTB,3,0);
	_delay_us(2000);
	LCD_CMND(0x33);
	_delay_us(100);
	LCD_CMND(0x32);
	_delay_us(100);
	LCD_CMND(0x28);
	_delay_us(100);
	LCD_CMND(0x0e);
	_delay_us(100);
	LCD_CMND(0x01);
	_delay_us(2000);
			
			
	
	//*((volatile unsigned int *)(LCD_CMND_PORT)) = 0xFF ;//
	/**((volatile unsigned int *)(LCD_Data_Port)) = 0x00 ;

	
	DIO_WRITEPIN(PORTB,3,0);
	LCD_CMND(0x38);
	LCD_CMND(0x03);
	LCD_CMND(0x01);*/
	
	
	
}
extern void LCD_gotoXY (unsigned char x, unsigned char y)
{
	unsigned char FirstCharAdrs [] = {0x80 , 0xC0};
		LCD_CMND(FirstCharAdrs[x-1] + y-1);
		_delay_us (150);
}
extern void LCD_Print (char * str)
{
	unsigned char i = 0;
	while (str[i] != 0) 
	{
		LCD_Data(str[i]);
		i++;
	}
}