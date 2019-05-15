/*
 * AMIT_SCHEMATIC.h
 *
 * Created: 5/12/2019 12:31:59 AM
 *  Author: A.Elkady
 */ 


#ifndef AMIT_SCHEMATIC_H_
#define AMIT_SCHEMATIC_H_

#define AMIT_KIT_ATMEGA32

#ifdef AMIT_KIT_ATMEGA32

	// LCD
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
	
	#define E_PORT PORT_B
	#define E_DDR DDR_B
	#define E_PIN PIN_B
	#define E_PIN_NUMBER 3
	
	// 7SEGMENT
	#define SEGMENT1_ENABLE_PORT PORT_C
	#define SEGMENT1_ENABLE_DDR DDR_C
	#define SEGMENT1_ENABLE_PIN PIN_C
	#define SEGMENT1_ENABLE_PIN_NUMBER 2
	
	#define SEGMENT2_ENABLE_PORT PORT_C
	#define SEGMENT2_ENABLE_DDR DDR_C
	#define SEGMENT2_ENABLE_PIN PIN_C
	#define SEGMENT2_ENABLE_PIN_NUMBER 3
	
	#define SEGMENT_A_PORT PORT_C
	#define SEGMENT_A_DDR DDR_C
	#define SEGMENT_A_PIN PIN_C
	#define SEGMENT_A_PIN_NUMBER 4
	
	#define SEGMENT_B_PORT PORT_C
	#define SEGMENT_B_DDR DDR_C
	#define SEGMENT_B_PIN PIN_C
	#define SEGMENT_B_PIN_NUMBER 5
	
	#define SEGMENT_C_PORT PORT_C
	#define SEGMENT_C_DDR DDR_C
	#define SEGMENT_C_PIN PIN_C
	#define SEGMENT_C_PIN_NUMBER 6
	
	#define SEGMENT_D_PORT PORT_C
	#define SEGMENT_D_DDR DDR_C
	#define SEGMENT_D_PIN PIN_C
	#define SEGMENT_D_PIN_NUMBER 7
	
	// BUTTONS
	#define BUTTON0_PORT PORT_D
	#define BUTTON0_DDR DDR_D
	#define BUTTON0_PIN PIN_D
	#define BUTTON0_PIN_NUMBER 0
	
	#define BUTTON1_PORT PORT_D
	#define BUTTON1_DDR DDR_D
	#define BUTTON1_PIN PIN_D
	#define BUTTON1_PIN_NUMBER 1
	
	#define BUTTON2_PORT PORT_D
	#define BUTTON2_DDR DDR_D
	#define BUTTON2_PIN PIN_D
	#define BUTTON2_PIN_NUMBER 2
	
	// RELAY
	#define RELAY_PORT PORT_D
	#define RELAY_DDR DDR_D
	#define RELAY_PIN PIN_D
	#define RELAY_PIN_NUMBER 3
	
	// BUZZER
	#define BUZZER_PORT PORT_D
	#define BUZZER_DDR DDR_D
	#define BUZZER_PIN PIN_D
	#define BUZZER_PIN_NUMBER 4
	
	// LEDS
	#define LED1_PORT PORT_D
	#define LED1_DDR DDR_D
	#define LED1_PIN PIN_D
	#define LED1_PIN_NUMBER 5
	
	#define LED2_PORT PORT_D
	#define LED2_DDR DDR_D
	#define LED2_PIN PIN_D
	#define LED2_PIN_NUMBER 6
	
	#define LED3_PORT PORT_D
	#define LED3_DDR DDR_D
	#define LED3_PIN PIN_D
	#define LED3_PIN_NUMBER 7
	
#endif

#endif /* AMIT_SCHEMATIC_H_ */