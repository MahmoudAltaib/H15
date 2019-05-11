/*
 * PORT_DIO.h
 *
 * Created: 5/11/2019 2:14:19 PM
 *  Author: A.Elkady
 */ 


#ifndef PORT_DIO_H_
#define PORT_DIO_H_

#define AMIT_ATMEGA


#ifdef AMIT_ATMEGA

#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/sfr_defs.h>

#else
#error "Define platform"

#endif


extern void DIO_Pin_out(unsigned int uPort_address , unsigned int uPin_number );
extern void DIO_Pin_in(unsigned int uPort_address , unsigned int uPin_number );
extern void DIO_Pin_read(unsigned int uPort_address , unsigned int uPin_number , unsigned int *puPin_value);
extern void DIO_Pin_write(unsigned int uPort_address , unsigned int uPin_number , unsigned int puPin_value);
extern void DIO_Pin_toggle(unsigned int uPort_address , unsigned int uPin_number );

#endif /* PORT_DIO_H_ */