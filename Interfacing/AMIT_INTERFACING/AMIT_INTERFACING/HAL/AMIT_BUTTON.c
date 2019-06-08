/*
 * AMIT_BUTTON.c
 *
 * Created: 11-May-19 5:54:23 PM
 *  Author: acer
 */ 
#include "AMIT_BUTTON.h"

#define F_CPU 16000000
#include "util/delay.h"

extern void Button_Read (unsigned int ButtonNum  , unsigned int *ButtonVal)
{
	unsigned int u16TmpState = 0 ;
	unsigned int u8Cnt  = 0 ;
	unsigned int u32pressed = 0;
	unsigned int u32released = 0;
	switch(ButtonNum)
	{
		case AMIT_BUTT0 :
		{
		DIO_PININ (AMIT_DDR_BUTT0 , AMIT_PIN_BUTT0) ;
		for (u8Cnt = 0 ; u8Cnt < 500 ; u8Cnt++)
		{
			DIO_READPIN( AMIT_PORT_BUTT0 , AMIT_PIN_BUTT0 , &u16TmpState );
			if(u16TmpState == 0 )
			{
				u32pressed++ ;
			}
			else
			{
				u32released++ ;
			}
			if (u32pressed >=150 && u32pressed <160) 
			{
				*ButtonVal =1; //push
				u32released = 0;
			}
			else if (u32pressed > 160 && u32released == 0)
			{
				*ButtonVal = 2;					//hold
			}
			else if (u32pressed > 160 && u32released <150)
			{
				*ButtonVal = 3; //pre-release
			}
			else if (u32released >=150)
			{
				*ButtonVal = 0; //released
			}
			break ;
		}
		}
		
		
		
		case AMIT_BUTT1 :
		{
		DIO_PININ (AMIT_DDR_BUTT1 , AMIT_PIN_BUTT1) ;
		for (u8Cnt = 0 ; u8Cnt < 500 ; u8Cnt++)
		{
			DIO_READPIN( AMIT_PORT_BUTT1 , AMIT_PIN_BUTT1 , &u16TmpState );
		if(u16TmpState == 0 )
		{
			u32pressed++ ;
		}
		else
		{
			u32released++ ;
		}
		if (u32pressed >=150 && u32pressed <160)
		{
			*ButtonVal =1; //push
			u32released = 0;
		}
		else if (u32pressed > 160 && u32released == 0)
		{
			*ButtonVal = 2;					//hold
		}
		else if (u32pressed > 160 && u32released <150)
		{
			*ButtonVal = 3; //pre-release
		}
		else if (u32released >=150)
		{
			*ButtonVal = 0; //released
		}
		break ;
		}
	    }
	
		
		
		case AMIT_BUTT2 :
		{
		DIO_PININ(AMIT_DDR_BUTT2 , AMIT_PIN_BUTT2) ;
		for (u8Cnt = 0 ; u8Cnt < 500 ; u8Cnt++)
		{
		if(u16TmpState == 0 )
		{
			u32pressed++ ;
		}
		else
		{
			u32released++ ;
		}
		if (u32pressed >=150 && u32pressed <160)
		{
			*ButtonVal =1; //push
			u32released = 0;
		}
		else if (u32pressed > 160 && u32released == 0)
		{
			*ButtonVal = 2;					//hold
		}
		else if (u32pressed > 160 && u32released <150)
		{
			*ButtonVal = 3; //pre-release
		}
		else if (u32released >=150)
		{
			*ButtonVal = 0; //released
		}
		break;
		}
		}
	}
	
}