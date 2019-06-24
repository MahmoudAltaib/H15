/*
 * ELKADY_BLUETOOTH.c
 *
 * Created: 6/7/2019 5:38:15 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "Elkady_BLUETOOTH.h"

/************************************************************************/
/*                     Static variables definition                      */
/************************************************************************/
static uint16_t u16ADC0_value[4] = {0};
static uint16_t u16ADC1_value[4] = {0};
	
static char c8BT_received_data[10] = {0};
	
static char c8Statement_LED1_ON[] = "led1_on";
static char c8Statement_LED1_OFF[] = "led1_of";
static char c8Statement_LED2_ON[] = "led2_on";
static char c8Statement_LED2_OFF[] = "led2_of";
static char c8Statement_LED3_ON[] = "led3_on";
static char c8Statement_LED3_OFF[] = "led3_of";

static char c8Statement_BUZZER_ON[] = "buzz_on";
static char c8Statement_BUZZER_OFF[] = "buzz_of";
static char c8Statement_RELAY_ON[] = "rela_on";
static char c8Statement_RELAY_OFF[] = "rela_of";
static char c8Statement_ADC_TEST[] = "adc_test";
static char c8Statement_PWM_TEST[] = "pwm_test";
static char c8Statement_EXIT[] = "esc_now";
static char c8Statement_PALIZ[] = "paliz";
	
static char u8Data = 0 ;
static char u8PWM_data = 0 ;

volatile static uint8_t u8Comparsion_result = 0;

static uint8_t u8End = 0 ;
static uint8_t u8End_ADC = 0 ;
static uint8_t u8Free_mode_end = 0;

static uint16_t u16ADC0_reading= 0;
static uint16_t u16ADC1_reading= 0;

static uint8_t u8Button2_reading = 0;
static uint8_t u8KHOSTIKA = 0 ;


/************************************************************************/
/*                          Functions definitions                       */
/************************************************************************/	


extern void BT_TEST(void)
{	
	USART_INIT();  // For bluetooth
	
	USART_TRANSMIT_CERTAIN_STRING("AMIT_LEARNING\n" , 15);
	USART_TRANSMIT_CERTAIN_STRING("Please choose an operation :\n",30);
	USART_TRANSMIT_CERTAIN_STRING("1) Test LEDS \n" , 15);
	USART_TRANSMIT_CERTAIN_STRING("2) Test BUZZER\n" , 16);
	USART_TRANSMIT_CERTAIN_STRING("3) Test RELAY\n" , 15);
	USART_TRANSMIT_CERTAIN_STRING("4) Test ADC\n" , 13);
	USART_TRANSMIT_CERTAIN_STRING("5) PWM\n" , 8);
	USART_TRANSMIT_CERTAIN_STRING("6) FREE MODE\n" , 14);
	
	do
	{
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING(" AMIT__LEARNING" , 15);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("Open BT to start" , 16);
		
		USART_RECEIVE(&u8Data);
	
		if (u8Data == '1')
		{
			BT_TEST_LEDS();
		}
	
		else if (u8Data == '2')
		{
			BT_TEST_BUZZER();
		}
	
		else if (u8Data == '3')
		{
			BT_TEST_RELAY();
		}
	
		else if (u8Data == '4')
		{
			BT_TEST_ADC();
		}
	
		else if (u8Data == '5')
		{
			BT_TEST_PWM();
		}
		
		else if (u8Data == '6')
		{
			BT_FREE_MODE();
		}
		
	} while (u8End == 0);

}

extern uint8_t STRING_COMPARE(char *pucBT_received_data , char *pucBT_instructions , uint8_t u8Size)
{
	uint8_t u8Count = 0 ;
	uint8_t u8Number_of_correct_checks = 0;
	
	for (u8Count = 0 ; u8Count < u8Size ; u8Count ++)
	{
		if (pucBT_received_data[u8Count] == pucBT_instructions[u8Count])
		{
			u8Number_of_correct_checks ++ ;
		} 
		else
		{
			break;
		}
	}
	
	if (u8Number_of_correct_checks == u8Size)
	{
		return 1 ;
	} 
	else
	{
		return 0 ;
	}
}

extern void BT_TEST_LEDS(void)
{
	LCD_CLEAR();
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_CERTAIN_STRING("Testing LEDS..." , 15);
	
	USART_TRANSMIT_CERTAIN_STRING("Testing LEDS...\n" , 17);
	
	LEDS_FLASH();
}
extern void BT_TEST_BUZZER(void)
{
	LCD_CLEAR();
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_CERTAIN_STRING("Testing BUZZER.." , 16);
	
	USART_TRANSMIT_CERTAIN_STRING("Testing BUZZER...\n" , 19);
	
	BUZZER_FLICKER();
}
extern void BT_TEST_RELAY(void)
{
	LCD_CLEAR();
	
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA_CERTAIN_STRING("Testing RELAY.." , 15);
	
	USART_TRANSMIT_CERTAIN_STRING("Testing RELAY...\n" , 18);
	
	RELAY_FLICKER();
}
extern void BT_TEST_ADC(void)
{
	LCD_CLEAR();
	
	do
	{
		ADC0_READ(&u16ADC0_reading);
		ADC1_READ(&u16ADC1_reading);
		
		u16ADC0_reading = u16ADC0_reading *  5 ;  // mv  
		u16ADC1_reading = u16ADC1_reading *  5 ;  // mv
		
		ADC_VALUE_ANALYSE(u16ADC0_reading , u16ADC0_value);
		ADC_VALUE_ANALYSE(u16ADC1_reading , u16ADC1_value);
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("ADC0 :  ", 8);
		ADC_SHOW_VALUE(u16ADC0_value);
		LCD_CERTAIN_DATA('v');

		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("ADC1 :  ", 8);
		ADC_SHOW_VALUE(u16ADC1_value);
		LCD_CERTAIN_DATA('v');
		
		BUTTON2_READ(&u8Button2_reading);
		
		if (u8Button2_reading != 0 )
		{
			u8End_ADC ++;
		}
		else
		{
			
		}
		_delay_ms(200);
		
	} while (u8End_ADC == 0);
	
}
extern void BT_TEST_PWM(void)
{
	T1_PWM_INIT();
	
	USART_TRANSMIT_CERTAIN_STRING("Choose a duty cycle :\n" , 23);
	USART_TRANSMIT_CERTAIN_STRING("1) 25%\n" , 8);
	USART_TRANSMIT_CERTAIN_STRING("2) 50%\n" , 8);
	USART_TRANSMIT_CERTAIN_STRING("3) 75%\n" , 8);
	USART_TRANSMIT_CERTAIN_STRING("4) 100%\n" , 9);
	USART_TRANSMIT_CERTAIN_STRING("5) ESC\n" , 8);
	
	do
	{
		USART_RECEIVE(&u8PWM_data);
		
		if (u8PWM_data == '1')
		{
			T1_PWM_DUTY_CYCLE(25 , 25);
		}
		else if (u8PWM_data == '2')
		{
			T1_PWM_DUTY_CYCLE(50 , 50);
		}
		else if (u8PWM_data == '3')
		{
			T1_PWM_DUTY_CYCLE(75 , 75);
		}
		else if (u8PWM_data == '4')
		{
			T1_PWM_DUTY_CYCLE(100 , 100);
		}
		
	} while (u8PWM_data != '5');
	
	T1_PWM_DEINIT();
	
	USART_TRANSMIT_CERTAIN_STRING("\n" , 2);
	USART_TRANSMIT_CERTAIN_STRING("Choose another operation\n" , 26);
}
extern void BT_FREE_MODE(void)
{		
	uint8_t u8Count = 0 ;

	do 
	{
		u8KHOSTIKA = 0 ;
		
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("You are now" , 11);
		
		LCD_COMMAND(SECOND_LINE_START);
		LCD_DATA_CERTAIN_STRING("    in free mode" , 16);
		
		USART_TRANSMIT_CERTAIN_STRING("You are now in free mode\n" , 26);
		USART_TRANSMIT_CERTAIN_STRING("Please enter an instruction\n" , 29);
		
		for (u8Count = 0 ; u8Count < 7 ; u8Count ++)
		{
			USART_RECEIVE(&c8BT_received_data[u8Count]);
		}		
		
		BT_CHECK_FOR_LED1_ON_COMMAND();
		BT_CHECK_FOR_LED1_OFF_COMMAND();
		BT_CHECK_FOR_LED2_ON_COMMAND();
		BT_CHECK_FOR_LED2_OFF_COMMAND();
		BT_CHECK_FOR_LED3_ON_COMMAND();
		BT_CHECK_FOR_LED3_OFF_COMMAND();
		BT_CHECK_FOR_BUZZER_ON_COMMAND();
		BT_CHECK_FOR_BUZZER_OFF_COMMAND();
		BT_CHECK_FOR_RELAY_ON_COMMAND();
		BT_CHECK_FOR_RELAY_OFF_COMMAND();
		BT_CHECK_FOR_ADC_TEST_COMMAND();
		BT_CHECK_FOR_PWM_TEST_COMMAND();
		BT_CHECK_FOR_EXIT_COMMAND();
	
	} while (u8Free_mode_end == 0);
}

extern void BT_CHECK_FOR_LED1_ON_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_LED1_ON , 7);
	
	if (u8Comparsion_result == 1)
	{
		BT_KHOSTIKA();
		if (u8KHOSTIKA == 4)
		{
			USART_TRANSMIT_CERTAIN_STRING("k\n",3);
			
			LCD_CLEAR();
			
			LCD_COMMAND(FIRST_LINE_START);
			LCD_DATA('k');
			
			LED_ON(LED1);
			_delay_ms(1000);			
		}
		else
		{
			USART_TRANSMIT_CERTAIN_STRING("La brdo hahbem\n", 16);
			
			LCD_CLEAR();
			
			LCD_COMMAND(FIRST_LINE_START);
			LCD_DATA_CERTAIN_STRING("La brdo hahbem" , 14);
			
			_delay_ms(4000);
		}
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_LED1_OFF_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_LED1_OFF , 7);
	
	if (u8Comparsion_result == 1)
	{
		LED_OFF(LED1);
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_LED2_ON_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_LED2_ON , 7);
	
	if (u8Comparsion_result == 1)
	{
		LED_ON(LED2);
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_LED2_OFF_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_LED2_OFF , 7);
	
	if (u8Comparsion_result == 1)
	{
		LED_OFF(LED2);
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_LED3_ON_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_LED3_ON, 7);
	
	if (u8Comparsion_result == 1)
	{
		LED_ON(LED3);
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_LED3_OFF_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_LED3_OFF , 7);
	
	if (u8Comparsion_result == 1)
	{
		LED_OFF(LED3);
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_BUZZER_ON_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_BUZZER_ON , 7);
	
	if (u8Comparsion_result == 1)
	{
		BUZZER_ON();
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_BUZZER_OFF_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_BUZZER_OFF , 7);
	
	if (u8Comparsion_result == 1)
	{
		BUZZER_OFF();
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_RELAY_ON_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_RELAY_ON , 7);
	
	if (u8Comparsion_result == 1)
	{
		RELAY_ON();
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_RELAY_OFF_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_RELAY_OFF , 7);
	
	if (u8Comparsion_result == 1)
	{
		RELAY_OFF();
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_ADC_TEST_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_ADC_TEST , 7);
	
	if (u8Comparsion_result == 1)
	{
		BT_TEST_ADC();
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_PWM_TEST_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_PWM_TEST , 7);
	
	if (u8Comparsion_result == 1)
	{
		BT_TEST_PWM();
	}
	else
	{
	}
}
extern void BT_CHECK_FOR_EXIT_COMMAND(void)
{
	u8Comparsion_result = 0;
	u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_EXIT , 7);
	
	if (u8Comparsion_result == 1)
	{
		u8Free_mode_end ++ ;
	}
	else
	{
	}
}

extern void BT_KHOSTIKA(void)
{
	uint8_t u8Count1 = 0 ;
	uint8_t u8Count2 = 0 ;
	
	for (u8Count1 = 0 ; u8Count1 < 4 ; u8Count1 ++)
	{
		u8Comparsion_result = 0;
		
		USART_TRANSMIT_CERTAIN_STRING("La\n", 4);
		
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("La" , 2);
		
		for (u8Count2 = 0 ; u8Count2 < 5 ; u8Count2 ++)
		{
			USART_RECEIVE(&c8BT_received_data[u8Count2]);
		}
		USART_TRANSMIT_CERTAIN_STRING(c8BT_received_data , 5);
		USART_TRANSMIT_CERTAIN_STRING("\n" , 2);
		
		LCD_CLEAR();
		
		LCD_COMMAND(FIRST_LINE_START);
		LCD_DATA_CERTAIN_STRING("PALIZ" , 5);
		_delay_ms(1000);
		
		u8Comparsion_result = STRING_COMPARE(c8BT_received_data , c8Statement_PALIZ , 5);
		
		if (u8Comparsion_result == 1)
		{
			u8KHOSTIKA ++ ;
		}
		else
		{
		}
	}
		
}