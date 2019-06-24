/*
 * AMIT_BLUETOOTH.h
 *
 * Created: 6/7/2019 5:38:06 AM
 *  Author: A.Elkady
 */ 


#ifndef AMIT_BLUETOOTH_H_
#define AMIT_BLUETOOTH_H_

#define ATMEGA32

#ifdef ATMEGA32

#include "AMIT_SCHEMATIC.h"

extern void AMIT_BT_TEST();
extern void BT_TEST_LEDS();
extern void BT_TEST_BUZZER();
extern void BT_TEST_RELAY();
extern void BT_TEST_ADC();
extern void BT_TEST_PWM();
extern void BT_FREE_MODE();

extern void BT_CHECK_FOR_LED1_ON_COMMAND();
extern void BT_CHECK_FOR_LED1_OFF_COMMAND();
extern void BT_CHECK_FOR_LED2_ON_COMMAND();
extern void BT_CHECK_FOR_LED2_OFF_COMMAND();
extern void BT_CHECK_FOR_LED3_ON_COMMAND();
extern void BT_CHECK_FOR_LED3_OFF_COMMAND();

extern void BT_CHECK_FOR_BUZZER_ON_COMMAND();
extern void BT_CHECK_FOR_BUZZER_OFF_COMMAND();

extern void BT_CHECK_FOR_RELAY_ON_COMMAND();
extern void BT_CHECK_FOR_RELAY_OFF_COMMAND();

extern void BT_CHECK_FOR_ADC_TEST_COMMAND();

extern void BT_CHECK_FOR_PWM_TEST_COMMAND();

extern void BT_CHECK_FOR_EXIT_COMMAND();

extern void BT_KHOSTIKA();

extern uint8_t BT_STRING_COMPARE(char *pucBT_received_data , char *pucBT_instructions , uint8_t u8Size);

#endif



#endif /* AMIT_BLUETOOTH_H_ */