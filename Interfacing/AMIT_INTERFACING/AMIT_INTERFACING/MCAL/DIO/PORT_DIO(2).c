/*
 * PORT_DIO.c
 *
 * Created: 10/05/2019 09:41:27 
 *  Author: pearl
 */ 


#include "PORT_DIO.h"



/************************************************************************/
/* configure pin as output                                              */
/************************************************************************/

extern void DIO_pinOut (unsigned int portAdd , unsigned int pinNum) 
{
	Util_setPin(portAdd , pinNum) ; 
}

/************************************************************************/
/* configure pin as input                                               */
/************************************************************************/
extern void DIO_pinIn (unsigned int portAdd , unsigned int pinNum) 
{
	Util_clrPin(portAdd , pinNum);
    Util_setPin(portAdd+1 , pinNum) ;	
}


/************************************************************************/
/* read pin                                                             */
/************************************************************************/

extern void DIO_readPin (unsigned int portAdd , unsigned int pinNum , unsigned int *pinValue)
{
	*pinValue = (*(volatile unsigned int *)(portAdd)) & (1 << pinNum) ; 
}

/************************************************************************/
/* write pin                                                            */
/************************************************************************/

extern void DIO_writePin (unsigned int portAdd , unsigned int pinNum , unsigned int pinValue) 
{
	if( pinValue == 1)
	{
		Util_setPin(portAdd , pinNum) ; 
	}
	else
	{
		Util_clrPin(portAdd, pinNum) ; 	
	}
}
