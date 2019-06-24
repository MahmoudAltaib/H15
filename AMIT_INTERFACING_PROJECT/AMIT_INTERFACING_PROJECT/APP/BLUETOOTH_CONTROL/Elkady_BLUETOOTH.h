/*
 * Elkady_BLUETOOTH.h
 *
 * Created: 6/7/2019 5:38:06 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef Elkady_BLUETOOTH_H_
#define Elkady_BLUETOOTH_H_

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
		#include "ELKADY_SCHEMATIC.h"
				
		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/
		extern void BT_TEST(void);
		extern void BT_TEST_LEDS(void);
		extern void BT_TEST_BUZZER(void);
		extern void BT_TEST_RELAY(void);
		extern void BT_TEST_ADC(void);
		extern void BT_TEST_PWM(void);
		extern void BT_FREE_MODE(void);

		extern void BT_CHECK_FOR_LED1_ON_COMMAND(void);
		extern void BT_CHECK_FOR_LED1_OFF_COMMAND(void);
		extern void BT_CHECK_FOR_LED2_ON_COMMAND(void);
		extern void BT_CHECK_FOR_LED2_OFF_COMMAND(void);
		extern void BT_CHECK_FOR_LED3_ON_COMMAND(void);
		extern void BT_CHECK_FOR_LED3_OFF_COMMAND(void);

		extern void BT_CHECK_FOR_BUZZER_ON_COMMAND(void);
		extern void BT_CHECK_FOR_BUZZER_OFF_COMMAND(void);

		extern void BT_CHECK_FOR_RELAY_ON_COMMAND(void);
		extern void BT_CHECK_FOR_RELAY_OFF_COMMAND(void);

		extern void BT_CHECK_FOR_ADC_TEST_COMMAND(void);

		extern void BT_CHECK_FOR_PWM_TEST_COMMAND(void);

		extern void BT_CHECK_FOR_EXIT_COMMAND(void);

		extern void BT_KHOSTIKA(void);

		extern uint8_t STRING_COMPARE(char *pucBT_received_data , char *pucBT_instructions , uint8_t u8Size);

	#else
	
		#error "DEFINE PLATFORM"

	#endif



#endif /* Elkady_BLUETOOTH_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/