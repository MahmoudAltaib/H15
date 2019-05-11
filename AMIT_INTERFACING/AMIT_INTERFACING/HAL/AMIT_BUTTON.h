/*
 * AMIT_BUTTON.h
 *
 * Created: 5/11/2019 4:41:02 PM
 *  Author: hp
 */ 


#ifndef AMIT_BUTTON_H_
#define AMIT_BUTTON_H_

#ifndef F_CPU
#define F_CPU 16000000u
#endif

#include "PORT_DIO.h"

#define AMIT_ATMEGA
#ifdef  AMIT_ATMEGA
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "DEFINE PLATFORM"
#endif

#define AMIT_BUTTON0           0u
#define AMIT_DDR_BUTTON0       DDRD
#define AMIT_PORT_BUTTON0      PIND
#define AMIT_PIN_BUTTON0       0


#define AMIT_BUTTON1           1u
#define AMIT_DDR_BUTTON1       DDRD
#define AMIT_PORT_BUTTON1      PIND
#define AMIT_PIN_BUTTON1       1



#define AMIT_BUTTON2           2u
#define AMIT_DDR_BUTTON2       DDRD
#define AMIT_PORT_BUTTON2      PIND
#define AMIT_PIN_BUTTON2       2

extern void READ_BUTTON(unsigned int button_Num  , unsigned int *button_Val);

#endif /* AMIT_BUTTON_H_ */