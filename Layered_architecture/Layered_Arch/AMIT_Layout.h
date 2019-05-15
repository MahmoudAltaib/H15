/*
 * AMIT_Layout.h
 *
 * Created: 5/10/2019 11:21:39 PM
 *  Author: A.Elkady
 */ 

#ifndef AMIT_Layout 
#define AMIT_Layout 

#define AMIT_HAL

#ifdef AMIT_HAL 

enum Port_A
{
	LCD_D4 = 4,  
	LCD_D5 = 5,
	LCD_D6 = 6,
	LCD_D7 = 7
};

enum Port_B
{
	LCD_RS = 1,
	LCD_RW = 2,
	LCD_E = 3
};

enum Port_C
{
	SEG1_ENABLE = 2,
	SEG2_ENABLE = 3,
	SEG_DECODER_A = 4,
	SEG_DECODER_B = 5,
	SEG_DECODER_C = 6,
	SEG_DECODER_D = 7
};

enum Port_D
{
	PUSH_BUTTON0 = 0,
	PUSH_BUTTON1 = 1,
	PUSH_BUTTON2 = 2,
	AMIT_RELAY = 3,
	AMIT_BUZZER = 4,
	AMIT_LED1 = 5,
	AMIT_LED2 = 6,
	AMIT_LED3 = 7
};

#endif
#endif