/*
 * ADC.c
 *
 * Created: 5/31/2019 5:24:56 AM
 *  Author: A.Elkady
 */ 

#include "ADC.h"

extern void ADC0_INIT()
{
	ADC_CSRA = 0x86 ;
	ADC_MUX = 0x40 ;
}

extern void ADC1_INIT()
{
	ADC_CSRA = 0x86 ;
	ADC_MUX = 0x41 ;
}

extern void ADC_START()
{
	ADC_CSRA |= (1<<ADC_SC);
}

extern void ADC_WAIT_FOR_CONVERSION_END()
{
	while (((ADC_CSRA) & (1 << ADC_IF )) == 0);
}

extern void ADC0_READ(uint16_t *pu16ADC0_reading)
{
	uint16_t u16ADCL_reading = 0;
	uint16_t u16ADCH_reading = 0;
	uint16_t u16ADC0_reading = 0;
	ADC0_INIT();
	
	ADC_START();
	ADC_WAIT_FOR_CONVERSION_END();
	
	_delay_us(30);
		
	u16ADCL_reading = (int)ADC_L ;
	u16ADCH_reading = (int)ADC_H ;
	
	u16ADC0_reading = u16ADCL_reading | (u16ADCH_reading << 8);
	
	*pu16ADC0_reading = u16ADC0_reading ;
}

extern void ADC1_READ(uint16_t *pu16ADC1_reading)
{
	uint16_t u16ADCL_reading = 0;
	uint16_t u16ADCH_reading = 0;
	uint16_t u16ADC1_reading = 0;

	ADC1_INIT();
	
	ADC_START();
	ADC_WAIT_FOR_CONVERSION_END();
	
	_delay_us(30);

	u16ADCL_reading = (int)ADC_L ;
	u16ADCH_reading = (int)ADC_H ;
	
	u16ADC1_reading = u16ADCL_reading | (u16ADCH_reading << 8);
	
	*pu16ADC1_reading = u16ADC1_reading ;
}

extern void ADC0_32_READ(uint32_t *pu32ADC0_reading)
{
	uint32_t u32ADCL_reading = 0;
	uint32_t u32ADCH_reading = 0;
	uint32_t u32ADC0_reading = 0;
	ADC0_INIT();
	
	ADC_START();
	ADC_WAIT_FOR_CONVERSION_END();
	
	_delay_us(30);
	
	u32ADCL_reading = (int)ADC_L ;
	u32ADCH_reading = (int)ADC_H ;
	
	u32ADC0_reading = u32ADCL_reading | (u32ADCH_reading << 8);
	
	*pu32ADC0_reading = u32ADC0_reading ;
}

extern void ADC1_32_READ(uint32_t *pu32ADC1_reading)
{
	uint32_t u32ADCL_reading = 0;
	uint32_t u32ADCH_reading = 0;
	uint32_t u32ADC1_reading = 0;
	
	ADC1_INIT();
	
	ADC_START();
	ADC_WAIT_FOR_CONVERSION_END();
	
	_delay_us(30);
	
	u32ADCL_reading = (int)ADC_L ;
	u32ADCH_reading = (int)ADC_H ;
	
	u32ADC1_reading = u32ADCL_reading | (u32ADCH_reading << 8);
	
	*pu32ADC1_reading = u32ADC1_reading ;
}


extern void ADC_VALUE_ANALYSE(uint16_t u16ADC_value , uint16_t *pu16ADC_array_value)
{
	uint8_t u8Count = 0;
	
	uint16_t u16Temp_value = u16ADC_value;
	
	for (u8Count = 0 ; u8Count < 4 ; u8Count ++)
	{
		pu16ADC_array_value[u8Count] = (u16Temp_value % 10) + '0' ;
		u16Temp_value /= 10 ;
	}
	
}

extern void ADC_SHOW_VALUE(uint16_t *pu16Value)
{
	LCD_DATA(pu16Value[3]);
	LCD_DATA('.');
	
	LCD_DATA(pu16Value[2]);
	LCD_DATA(pu16Value[1]);
	LCD_DATA(pu16Value[0]);
}

