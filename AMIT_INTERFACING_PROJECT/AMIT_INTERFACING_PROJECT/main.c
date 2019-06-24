/*
 * AMIT_INTERFACING_PROJECT.c
 *
 * Created: 6/17/2019 7:45:18 AM
 * Author : A.Elkady
 */ 

/************************************************************************/
/*                               Inclusions                             */
/************************************************************************/
#include "ELKADY_SCHEMATIC.h"

/************************************************************************/
/*                         Declarations & Definitions                   */
/************************************************************************/
volatile uint8_t gu8ID_right = 0;
volatile uint8_t gu8Password_right = 0;

char c8Temp = 0 ;
char gc8EEPROM_address_of_number_of_entries = 0 ;

signed char c8Actual_ID[MAXIMUM_NUMBER_OF_LETTERS] = {'A','E','L','K','A','D','Y'};
signed char c8Actual_password[MAXIMUM_NUMBER_OF_LETTERS] = {'3','5','5','2','3','9'};
	
const unsigned char gu8Key_pad[4][4] = {{'o','s','B','A'},
										{'#','9','6','3'},
										{'0','8','5','2'},
										{'*','7','4','1'}};

char c8ID[10] = {0} ;	
char c8Password[10] = {0};	
											
uint8_t u8Data = 0;											
/************************************************************************/
/*                           Calling main                               */
/************************************************************************/											
											
int main(void)
{		
/************************************************************************/
/*                        I/O Configurations                            */
/************************************************************************/
	Pin_mode(LED1_PORT , LED1_DDR , LED1_PIN_NUMBER , OUTPUT);
	Pin_mode(LED2_PORT , LED2_DDR , LED2_PIN_NUMBER , OUTPUT);
	Pin_mode(LED3_PORT , LED3_DDR , LED3_PIN_NUMBER , OUTPUT);
	Pin_mode(BUZZER_PORT , BUZZER_DDR , BUZZER_PIN_NUMBER , OUTPUT);
	Pin_mode(RELAY_PORT , RELAY_DDR , RELAY_PIN_NUMBER , OUTPUT);
	
	Pin_mode(BUTTON2_PORT , BUTTON2_DDR , BUTTON2_PIN_NUMBER , INPUT);
	Pin_mode(ADC0_PORT , ADC0_DDR , ADC0_PIN_NUMBER , INPUT);
	Pin_mode(ADC1_PORT , ADC1_DDR , ADC1_PIN_NUMBER , INPUT);

/************************************************************************/
/*                      Peripherals initialization                      */
/************************************************************************/
	LCD_INIT();
	LCD_CLEAR();
	LCD_COMMAND(FIRST_LINE_START);
	LCD_DATA('a');
/************************************************************************/
/*                Reading the address of the number of entries          */
/************************************************************************/

INTERNAL_EEPROM_READ(EEPROM_ADDRESS_OF_NUMBER_OF_ENTRIES , &c8Temp);

	if (c8Temp == 0xFF) //This means that the EEPROM has been erased 
	{
	gc8EEPROM_address_of_number_of_entries = 0 ;
	INTERNAL_EEPROM_WRITE(EEPROM_ADDRESS_OF_NUMBER_OF_ENTRIES , 0);
	} 
	else
	{
	INTERNAL_EEPROM_READ(EEPROM_ADDRESS_OF_NUMBER_OF_ENTRIES , &gc8EEPROM_address_of_number_of_entries);
	
	}


/************************************************************************/
/*                      Continuous operation                            */
/************************************************************************/
				
	while (1)
	{	
		/*if (gu8ID_right != 0 && gu8Password_right != 0)
		{
			KIT_CONTROL();
		} 
		else
		{
			INFO_CONTROL();
		}*/
		GET_PRESSED_KEY(&u8Data);		
	}
	return 0 ;
}
