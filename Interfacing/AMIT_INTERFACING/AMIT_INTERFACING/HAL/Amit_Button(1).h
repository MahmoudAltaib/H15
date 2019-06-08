/*
 * Amit_Button.h
 *
 * Created: 11/05/2019 05:15:35 ص
 *  Author: pearl
 */ 


#ifndef AMIT_BUTTON_H_
#define AMIT_BUTTON_H_

#include "PORT_DIO.h"

#define AMIT_ATMEGA32
#ifdef  AMIT_ATMEGA32
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "DEFINE PLATFORM"
#endif


#define AMIT_BUTT0             0u
#define AMIT_DDR_BUTT0       (DDRD)
#define AMIT_PORT_BUTT0      (PIND)
#define AMIT_PIN_BUTT0       (PIND0)


#define AMIT_BUTT1             1u
#define AMIT_DDR_BUTT1       (DDRD)
#define AMIT_PORT_BUTT1      (PIND)
#define AMIT_PIN_BUTT1       (PIND1)



#define AMIT_BUTT2             2u
#define AMIT_DDR_BUTT2       (DDRD)
#define AMIT_PORT_BUTT2      (PIND)
#define AMIT_PIN_BUTT2       (PIND2)



/************************************************************************/
/*                                                                      */
/************************************************************************/

extern void Button_Read (unsigned int buttonNum  , unsigned int *buttonVal);


#endif /* AMIT_BUTTON_H_ */