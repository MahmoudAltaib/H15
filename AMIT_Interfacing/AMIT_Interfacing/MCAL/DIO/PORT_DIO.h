/*
 * PORT_DIO.h
 *
 * Created: 5/11/2019 2:14:31 PM
 *  Author: dell
 */ 




#ifndef PORT_DIO_H_
#define PORT_DIO_H_
#define  AMIT_ATMEGA
#ifdef AMIT_ATMEGA
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "Define Platform"
#endif
extern void DIO_pinOut(unsigned int PORTADD , unsigned int PIN_NUMBER );
extern void DIO_PinIn(unsigned int PORTADD , unsigned int PIN_NUMBER);
extern void DIO_readPin(unsigned int PORTADD , unsigned int PIN_NUMBER , unsigned int *pinvalue);
extern void DIO_writePin(unsigned int PORTADD , unsigned int PIN_NUMBER , unsigned int pinvalue);





#endif /* PORT_DIO_H_ */