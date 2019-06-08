/*
 * Amit_Led.c
 *
 * Created: 11/05/2019 05:08:17 
 *  Author: pearl
 */ 

#include "Amit_Led.h"


/************************************************************************/
/*                                                                      */
/************************************************************************/
extern void Led_ON (unsigned int ledNum)
{
   switch (ledNum) 
   {
     case AMIT_LEDNUM_0 :
          DIO_pinOut(AMIT_DDR_LED0 , AMIT_PIN_LED0); 
          DIO_writePin(AMIT_PORT_LED0 , AMIT_PIN_LED0 , LEDON) ; 
          break ;
     case AMIT_LEDNUM_1 :
          DIO_pinOut(AMIT_DDR_LED1 , AMIT_PIN_LED1);
          DIO_writePin(AMIT_PORT_LED1 , AMIT_PIN_LED1 , LEDON) ;
          break ;
     case AMIT_LEDNUM_2 :
          DIO_pinOut(AMIT_DDR_LED2 , AMIT_PIN_LED2);
          DIO_writePin(AMIT_PORT_LED2 , AMIT_PIN_LED2 , LEDON) ;
          break ;
     default :
      break ;
   }

}

/************************************************************************/
/*                                                                      */
/************************************************************************/
extern void Led_OFF (unsigned int ledNum)
{

	switch (ledNum)
	{
		case AMIT_LEDNUM_0 :
			DIO_pinOut(AMIT_DDR_LED0 , AMIT_PIN_LED0);
			DIO_writePin(AMIT_PORT_LED0 , AMIT_PIN_LED0 , LEDOFF) ;
			break ;
		case AMIT_LEDNUM_1 :
			DIO_pinOut(AMIT_DDR_LED1 , AMIT_PIN_LED1);
			DIO_writePin(AMIT_PORT_LED1 , AMIT_PIN_LED1 , LEDOFF) ;
			break ;
		case AMIT_LEDNUM_2 :
			DIO_pinOut(AMIT_DDR_LED2 , AMIT_PIN_LED2);
			DIO_writePin(AMIT_PORT_LED2 , AMIT_PIN_LED2 , LEDOFF) ;
			break ;
		default :
			break ;
	}
}


/************************************************************************/
/*                                                                      */
/************************************************************************/
extern void Led_Togg (unsigned int ledNum)
{
	switch (ledNum)
	{
		case AMIT_LEDNUM_0 :
			DIO_pinOut(AMIT_DDR_LED0 , AMIT_PIN_LED0);
	        Util_toglePin(AMIT_PORT_LED0 , AMIT_PIN_LED0) ; 
			break ;
		case AMIT_LEDNUM_1 :
			DIO_pinOut(AMIT_DDR_LED1 , AMIT_PIN_LED1);
            Util_toglePin(AMIT_PORT_LED1 , AMIT_PIN_LED1) ;
			break ;
		case AMIT_LEDNUM_2 :
			DIO_pinOut(AMIT_DDR_LED2 , AMIT_PIN_LED2);
            Util_toglePin(AMIT_PORT_LED2 , AMIT_PIN_LED2) ;
			break ;
		default :
			break ;
	}
}