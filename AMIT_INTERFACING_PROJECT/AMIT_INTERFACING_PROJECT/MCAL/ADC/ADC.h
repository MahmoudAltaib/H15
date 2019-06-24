/*
 * ADC.h
 *
 * Created: 5/31/2019 5:24:48 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/

#ifndef ADC_H_
#define ADC_H_

	/************************************************************************/
	/*                  Start of platform definition                        */
	/************************************************************************/
	#define ATMEGA32
	/************************************************************************/
	/*                  End of platform definition                          */
	/************************************************************************/


	#ifdef ATMEGA32

		/************************************************************************/
		/*                               Inclusions                             */
		/************************************************************************/
		#include "GPIO/GPIO.h"
		#include "LCD_INTERFACE.h"

		/************************************************************************/
		/*              Definition of ADC pins parameters                       */
		/************************************************************************/
		#define ADC0_PORT PORT_A
		#define ADC0_DDR DDR_A
		#define ADC0_PIN PIN_A
		#define ADC0_PIN_NUMBER 0

		#define ADC1_PORT PORT_A
		#define ADC1_DDR DDR_A
		#define ADC1_PIN PIN_A
		#define ADC1_PIN_NUMBER 1

		#define ADC_MUX (*((volatile unsigned char *)(0x27)))
		#define ADC_CSRA (*((volatile unsigned char *)(0x26)))
		#define ADC_H (*((volatile unsigned char *)(0x25)))
		#define ADC_L (*((volatile unsigned char *)(0x24)))

		/************************************************************************/
		/*                       ADC definitions                       */
		/************************************************************************/		
		// ADC_MUX
		#define ADC_MUX0 0
		#define ADC_MUX1 1
		#define ADC_MUX2 2
		#define ADC_MUX3 3
		#define ADC_MUX4 4
		#define ADC_LAR 5
		#define ADC_REFS0 6
		#define ADC_REFS1 7
		// ADC_CSRA
		#define ADC_PS0 0
		#define ADC_PS1 1
		#define ADC_PS2 2
		#define ADC_IE 3
		#define ADC_IF 4
		#define ADC_ATE 5
		#define ADC_SC 6
		#define ADC_EN 7
		
		/************************************************************************/
		/*                       ADC registers values                           */
		/************************************************************************/
		#define ADC_CSR_INIT_VALUE ((1 << ADC_EN) | (1 << ADC_PS1) | (1 << ADC_PS2))
		#define ADC0_MUX_VALUE ((1 << ADC_REFS0) )
		#define ADC1_MUX_VALUE ((1 << ADC_REFS0) | (1 << ADC_MUX0))

		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/
		extern void ADC0_INIT(void);
		extern void ADC1_INIT(void);

		extern void ADC_START(void);
		extern void ADC_WAIT_FOR_CONVERSION_END(void);

		extern void ADC0_READ(uint16_t *pu16ADC0_reading);
		extern void ADC1_READ(uint16_t *pu16ADC1_reading);

		extern void ADC0_32_READ(uint32_t *pu32ADC0_reading);
		extern void ADC1_32_READ(uint32_t *pu32ADC1_reading);

		extern void ADC_VALUE_ANALYSE(uint16_t u16ADC_value , uint16_t *u16ADC_array_value);

		extern void ADC_SHOW_VALUE(uint16_t *pu16Value);

	#else
	
		#error "DEFINE PLATFORM"

	#endif

#endif /* ADC_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/