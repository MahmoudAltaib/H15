/*
 * PORT_DIO.h
 *
 * Created: 5/11/2019 1:58:58 PM
 *  Author: hp
 */ 


#ifndef PORT_DIO_H_
#define PORT_DIO_H_
#include <inttypes.h>
#define AMIT_ATMEGA
#ifdef AMIT_ATMEGA
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "Platform is not defined"
#endif

extern void DIO_pinOUT(unsigned int port_address, unsigned int pin_number);

extern void DIO_pinIN(unsigned int port_address, unsigned int pin_number);

extern void DIO_pinWRITE(unsigned int port_address, unsigned int pin_number, unsigned int value);

extern void DIO_pinREAD(unsigned int port_address, unsigned int pin_number, unsigned int * pin_value);

extern void DIO_pinTOGGLE(unsigned int port_address, unsigned int pin_number);

#endif /* PORT_DIO_H_ */