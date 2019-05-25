/*
 * AMIT_INTERFACING.c
 *
 * Created: 5/11/2019 1:49:00 PM
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#define AMIT_ATMEGA
#include "MCAL/DIO/PORT_DIO.h"
#include <avr/io.h>
#include <inttypes.h>
#include "HAL/AMIT_SCHEMATIC.h"
#include "MCAL/TIMER0/TIMER0.h"

int main(void)
{  

    /* Replace with your application code */
    while (1) 
{	
Led_ON(AMIT_LEDNUM_0);
T0_Delay_ms(500);
Led_OFF(AMIT_LEDNUM_0);
T0_Delay_ms(500);


}

}

