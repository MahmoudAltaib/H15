/*
 * PORT_DIO.h
 *
 * Created: 10/05/2019 09:42:14 
 *  Author: pearl
 */ 


#ifndef PORT_DIO_H_
#define PORT_DIO_H_

#include "AmitUtil.h"
#include "stdint.h"
#define AMIT_ATMEGA32
#ifdef AMIT_ATMEGA32
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else 
#error "DEFINE PLATFORM"
#endif 


/************************************************************************/
/* configure pin as output                                              */
/************************************************************************/
extern void DIO_pinOut (unsigned int portAdd , unsigned int pinNum) ; 

/************************************************************************/
/* configure pin as input                                               */
/************************************************************************/
extern void DIO_pinIn (unsigned int portAdd , unsigned int pinNum) ;

/************************************************************************/
/* read pin                                                             */
/************************************************************************/
extern void DIO_readPin (unsigned int portAdd , unsigned int pinNum , unsigned int *pinValue);

/************************************************************************/
/* write pin                                                            */
/************************************************************************/
extern void DIO_writePin (unsigned int portAdd , unsigned int pinNum , unsigned int pinValue) ;

 
 #endif /* PORT_DIO_H_ */