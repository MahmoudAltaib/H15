/*
 * PORT_DIO.c
 *
 * Created: 5/11/2019 2:10:19 PM
 *  Author: A.Elkady
 */ 
#include "PORT_DIO.h"
#include "AMIT_UTIL.h"

extern void DIO_Pin_out(unsigned int uPort_address , unsigned int uPin_number )
{
	UTIL_SET_PIN(uPort_address , uPin_number);
}

extern void DIO_Pin_in(unsigned int uPort_address , unsigned int uPin_number )
{
	UTIL_CLEAR_PIN(uPort_address , uPin_number);
	UTIL_SET_PIN(uPort_address +1 , uPin_number);
}

extern void DIO_Pin_read(unsigned int uPort_address , unsigned int uPin_number , unsigned int *puPin_value)
{
	unsigned int Temp = UTIL_READ_PIN(uPort_address , uPin_number);
	*puPin_value = Temp;
}

extern void DIO_Pin_write(unsigned int uPort_address , unsigned int uPin_number , unsigned int uPin_value)
{
	if (uPin_value ==0)
	{
		UTIL_CLEAR_PIN(uPort_address , uPin_number);	
	}
	else
	{
		UTIL_SET_PIN(uPort_address , uPin_number);
	}
}

extern void DIO_Pin_toggle(unsigned int uPort_address , unsigned int uPin_number )
{
	UTIL_TOGGLE_PIN(uPort_address , uPin_number);
}