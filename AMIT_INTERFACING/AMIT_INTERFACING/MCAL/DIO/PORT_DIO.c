/*
 * PORT_DIO.c
 *
 * Created: 5/11/2019 1:54:31 PM
 *  Author: hp
 */ 
#include "PORT_DIO.h"
#include "AMIT_UTIL.h"

extern void DIO_pinOUT(unsigned int port_address, unsigned int pin_number)
{
UTIL_SETPIN(port_address,pin_number);
}
extern void DIO_pinIN(unsigned int port_address, unsigned int pin_number)
{
 UTIL_CLEARPIN(port_address,pin_number);
 UTIL_SETPIN(port_address + 1,pin_number); //Activate pull up resistor of this pin (port address + 1 is the address of the specified port based in the address of the DDRx sent)

}
extern void DIO_pinWRITE(unsigned int port_address, unsigned int pin_number, unsigned int value)
{
 if(value == 0)
 {
   UTIL_CLEARPIN(port_address, pin_number);
 }
 else
 {
   UTIL_SETPIN(port_address, pin_number);
 }
 
}

extern void DIO_pinTOGGLE(unsigned int port_address, unsigned int pin_number)
{
	UTIL_TOGGLEPIN(port_address,pin_number);
}

extern void DIO_pinREAD(unsigned int port_address, unsigned int pin_number, unsigned int * pin_value)
{    
	 //PV= port_address & (1<<pin_number);
	*pin_value = (*((volatile unsigned int *)(port_address))) & (1<<pin_number);
	
	
	
}