/*
 * Amit_Button.c
 *
 * Created: 11/05/2019 05:16:24 
 *  Author: pearl
 */ 

#include "Amit_Button.h"
#include "util/delay.h"

/************************************************************************/
/*                                                                      */
/************************************************************************/

extern void Button_Read (unsigned int buttonNum  , unsigned int *buttonVal)
{
  
	unsigned int u16TmpState = 0 ;
    unsigned char u8Cnt  = 0 ; 
   switch(buttonNum)
   {
		case AMIT_BUTT0 :
           DIO_pinIn(AMIT_DDR_BUTT0 , AMIT_PIN_BUTT0) ; 
			for (u8Cnt = 0 ; u8Cnt < 2 ; u8Cnt++)
			{
               DIO_readPin(AMIT_PORT_BUTT0 , AMIT_PIN_BUTT0 , &u16TmpState );
               if(u16TmpState == 0 )
               {
	               *buttonVal = 0 ;
               }
               else
               {
	               *buttonVal = 1 ;
               }
              _delay_ms(100) ;  
			}
               
           break ; 
        case AMIT_BUTT1 :
           DIO_pinIn(AMIT_DDR_BUTT1 , AMIT_PIN_BUTT1) ;
           for (u8Cnt = 0 ; u8Cnt < 2 ; u8Cnt++)
           {
	           DIO_readPin(AMIT_PORT_BUTT1 , AMIT_PIN_BUTT1 , &u16TmpState );
	           _delay_us(1000) ;
           }
           *buttonVal = u16TmpState ;
           break ;
		case AMIT_BUTT2 :
           DIO_pinIn(AMIT_DDR_BUTT2 , AMIT_PIN_BUTT2) ;
           for (u8Cnt = 0 ; u8Cnt < 2 ; u8Cnt++)
           {
	           DIO_readPin(AMIT_PORT_BUTT2 , AMIT_PIN_BUTT2 , &u16TmpState );
	           _delay_us(1000) ;
           }
           *buttonVal = u16TmpState ;
  		   break ;
        default:
           break ; 
   }
}