/*
 * ADC.h
 *
 * Created: 5/31/2019 5:24:48 AM
 *  Author: A.Elkady
 */ 


#ifndef ADC_H_
#define ADC_H_

#define ATMEGA32

#ifdef ATMEGA32

#include "GPIO/GPIO.h"
#include "LCD_INTERFACE.h"

#define ADC0_PORT PORT_A
#define ADC0_DDR DDR_A
#define ADC0_PIN PIN_A
#define ADC0_PIN_NUMBER 0

#define ADC1_PORT PORT_A
#define ADC1_DDR DDR_A
#define ADC1_PIN PIN_A
#define ADC1_PIN_NUMBER 1

#define ADC_MUX (*((volatile unsigned int *)(0x27)))
#define ADC_CSRA (*((volatile unsigned int *)(0x26)))
#define ADC_H (*((volatile unsigned int *)(0x25)))
#define ADC_L (*((volatile unsigned int *)(0x24)))

#define ADC_SC 6
#define ADC_IF 4

extern void ADC0_INIT();
extern void ADC1_INIT();

extern void ADC_START();
extern void ADC_WAIT_FOR_CONVERSION_END();

extern void ADC0_READ(uint16_t *pu16ADC0_reading);
extern void ADC1_READ(uint16_t *pu16ADC1_reading);

extern void ADC0_32_READ(uint32_t *pu32ADC0_reading);
extern void ADC1_32_READ(uint32_t *pu32ADC1_reading);

extern void ADC_VALUE_ANALYSE(uint16_t u16ADC_value , uint16_t *u16ADC_array_value);

extern void ADC_SHOW_VALUE(uint16_t *pu16Value);

#endif

#endif /* ADC_H_ */