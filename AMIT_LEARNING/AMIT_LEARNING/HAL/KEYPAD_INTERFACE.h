/*
 * KEYPAD_INTERFACE.h
 *
 * Created: 5/24/2019 9:38:44 AM
 *  Author: A.Elkady
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "GPIO/GPIO.h"

#define ROW1_PORT PORT_C
#define ROW1_DDR DDR_C
#define ROW1_PIN PIN_C
#define ROW1_PIN_NUMBER 4

#define ROW2_PORT PORT_C
#define ROW2_DDR DDR_C
#define ROW2_PIN PIN_C
#define ROW2_PIN_NUMBER 5

#define ROW3_PORT PORT_C
#define ROW3_DDR DDR_C
#define ROW3_PIN PIN_C
#define ROW3_PIN_NUMBER 6

#define ROW4_PORT PORT_C
#define ROW4_DDR DDR_C
#define ROW4_PIN PIN_C
#define ROW4_PIN_NUMBER 7

#define COLUMN1_PORT PORT_C
#define COLUMN1_DDR DDR_C
#define COLUMN1_PIN PIN_C
#define COLUMN1_PIN_NUMBER 0

#define COLUMN2_PORT PORT_C
#define COLUMN2_DDR DDR_C
#define COLUMN2_PIN PIN_C
#define COLUMN2_PIN_NUMBER 1

#define COLUMN3_PORT PORT_C
#define COLUMN3_DDR DDR_C
#define COLUMN3_PIN PIN_C
#define COLUMN3_PIN_NUMBER 2

#define COLUMN4_PORT PORT_C
#define COLUMN4_DDR DDR_C
#define COLUMN4_PIN PIN_C
#define COLUMN4_PIN_NUMBER 3

#define NUMBER_OF_KEYPAD_CHECKS 150

extern void POWER_ALL_ROWS();
extern void GROUND_ALL_ROWS();

extern void POWER_ROW1();
extern void POWER_ROW2();
extern void POWER_ROW3();
extern void POWER_ROW4();

extern void READ_ROW1(uint8_t *pu8Reading);
extern void READ_ROW2(uint8_t *pu8Reading);
extern void READ_ROW3(uint8_t *pu8Reading);
extern void READ_ROW4(uint8_t *pu8Reading);

extern void SET_ROWS_INPUT();
extern void SET_ROWS_OUTPUT();

extern void POWER_ALL_COLUMNS();
extern void GROUND_ALL_COLUMNS();

extern void POWER_COLUMN1();
extern void POWER_COLUMN2();
extern void POWER_COLUMN3();
extern void POWER_COLUMN4();

extern void READ_COLUMN1(uint8_t *pu8Reading);
extern void READ_COLUMN2(uint8_t *pu8Reading);
extern void READ_COLUMN3(uint8_t *pu8Reading);
extern void READ_COLUMN4(uint8_t *pu8Reading);

extern void SET_COLUMNS_INPUT();
extern void SET_COLUMNS_OUTPUT();

extern void ACTIVATE_PULL_UP_RESISTORS();

#endif /* KEYPAD_INTERFACE_H_ */