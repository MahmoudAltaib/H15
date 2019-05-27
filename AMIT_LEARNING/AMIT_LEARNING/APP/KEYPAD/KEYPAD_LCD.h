/*
 * KEYPAD_LCD.h
 *
 * Created: 5/25/2019 5:47:15 AM
 *  Author: A.Elkady
 */ 


#ifndef KEYPAD_LCD_H_
#define KEYPAD_LCD_H_

#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3

#define COLUMN1 0
#define COLUMN2 1
#define COLUMN3 2
#define COLUMN4 3

#include "KEYPAD_INTERFACE.h"
#include "AMIT_SCHEMATIC.h"
#include "BUTTON_INTERFACE.h"

#define MAXIMUM_NUMBER_OF_LETTERS 6

extern void KEYPAD_WITH_LCD();

extern void GET_KEY_ROW(uint8_t *pu8Captured_row);
extern void GET_KEY_COLUMN(uint8_t *pu8Captured_column);

#endif /* KEYPAD_LCD_H_ */