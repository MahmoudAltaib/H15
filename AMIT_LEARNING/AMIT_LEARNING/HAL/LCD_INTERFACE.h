/*
 * LCD_INTERFACE.h
 *
 * Created: 5/17/2019 1:35:46 PM
 *  Author: A.Elkady
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "GPIO/GPIO.h"

#define ATMEGA32

#ifdef ATMEGA32

	#define RW_WRITE 0
	#define RW_READ 1
	
	#define RS_COMMAND 0
	#define RS_DATA 1
	
	#define ENABLE_LOW 0
	#define ENABLE_HIGH 1
	
	#define PULSE_WIDTH 5
	
	// LCD CONNECTIONS
	#define D4_PORT PORT_A
	#define D4_DDR DDR_A
	#define D4_PIN PIN_A
	#define D4_PIN_NUMBER 4

	#define D5_PORT PORT_A
	#define D5_DDR DDR_A
	#define D5_PIN PIN_A
	#define D5_PIN_NUMBER 5

	#define D6_PORT PORT_A
	#define D6_DDR DDR_A
	#define D6_PIN PIN_A
	#define D6_PIN_NUMBER 6

	#define D7_PORT PORT_A
	#define D7_DDR DDR_A
	#define D7_PIN PIN_A
	#define D7_PIN_NUMBER 7

	#define RS_PORT PORT_B
	#define RS_DDR DDR_B
	#define RS_PIN PIN_B
	#define RS_PIN_NUMBER 1

	#define RW_PORT PORT_B
	#define RW_DDR DDR_B
	#define RW_PIN PIN_B
	#define RW_PIN_NUMBER 2

	#define ENABLE_PORT PORT_B
	#define ENABLE_DDR DDR_B
	#define ENABLE_PIN PIN_B
	#define ENABLE_PIN_NUMBER 3
	
	extern void RW_STATE(uint8_t u8State);
	extern void RS_STATE(uint8_t u8State);
	extern void ENABLE_STATE(uint8_t u8State);
	extern void HIGH_TO_LOW_PULSE();
	extern void LCD_COMMAND(uint8_t u8Command);
	extern void LCD_DATA(uint8_t u8Data);
	extern void LCD_DATA_STRING(uint8_t *pu8Data , uint8_t u8Size);
	extern void LCD_INIT();
	extern void LCD_PRINT(unsigned char *puStatement);



#endif

#endif /* LCD_INTERFACE_H_ */