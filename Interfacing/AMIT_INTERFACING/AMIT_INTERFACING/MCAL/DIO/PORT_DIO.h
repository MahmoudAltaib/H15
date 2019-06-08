/*
 * PORT_DIO.h
 *
 * Created: 11-May-19 3:14:19 PM
 *  Author: acer
 */ 

#define AMIT_ATMEGA
#ifndef PORT_DIO_H_
#define PORT_DIO_H_
#ifdef AMIT_ATMEGA
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "Define Platform"
#endif
extern void DIO_PINOUT (unsigned int PORT_ADR , unsigned int PIN_NMBR);
extern void DIO_PININ (unsigned int PORT_ADR , unsigned int PIN_NMBR);
extern void DIO_READPIN (unsigned int PORT_ADR , unsigned int PIN_NMBR , unsigned int * PIN_VALUE);
extern void DIO_WRITEPIN (unsigned int PORT_ADR, unsigned int PIN_NMBR, unsigned int PIN_VALUE);




#endif /* PORT_DIO_H_ */