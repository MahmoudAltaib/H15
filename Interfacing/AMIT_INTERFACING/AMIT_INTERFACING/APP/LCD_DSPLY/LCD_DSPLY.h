/*
 * LCD_DSPLY.h
 *
 * Created: 31-May-19 2:58:47 AM
 *  Author: acer
 */ 


#ifndef LCD_DSPLY_H_
#define LCD_DSPLY_H_
#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <Util/delay.h>
#include "PORT_DIO.h"
#define LCD_CMND_PORT (PORTB)
#define LCD_CMND_DDR  (DDRB)
#define LCD_CMND_PIN  (PINB)
#define LCD_Data_Port (PORTA)
#define LCD_Data_DDR  (DDRA)
#define LCD_Data_Pin  (PINA)
#define LCD_RS 1
#define LCD_RW 2
#define LCD_EN 3

extern void LCD_CMND (unsigned char cmnd);
extern void LCD_Data (unsigned char data);
extern void LCD_Init (void);
extern void LCD_gotoXY (unsigned char x, unsigned char y);
extern void LCD_Print (char * str);



#endif /* LCD_DSPLY_H_ */