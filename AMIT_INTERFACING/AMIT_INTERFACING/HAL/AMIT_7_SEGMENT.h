/*
 * AMIT_7_SEGMENT.h
 *
 * Created: 5/11/2019 10:15:53 PM
 *  Author: hp
 */ 


#ifndef AMIT_7_SEGMENT_H_
#define AMIT_7_SEGMENT_H_


#include "PORT_DIO.h"

#define AMIT_ATMEGA
#ifdef  AMIT_ATMEGA
#include "avr/sfr_defs.h"
#include "avr/io.h"
#else
#error "DEFINE PLATFORM"
#endif

#define AMIT_SEGMENT_ENABLE1           1u
#define AMIT_DDR_SEGMENT_ENABLE1       DDRC
#define AMIT_PORT_SEGMENT_ENABLE1      PORTC
#define AMIT_PIN_SEGMENT_ENABLE1       2

#define AMIT_SEGMENT_ENABLE2           1u
#define AMIT_DDR_SEGMENT_ENABLE2       DDRC
#define AMIT_PORT_SEGMENT_ENABLE2      PORTC
#define AMIT_PIN_SEGMENT_ENABLE2       3

#define AMIT_SEGMENT_A           0u
#define AMIT_DDR_SEGMENT_A       DDRC
#define AMIT_PORT_SEGMENT_A      PORTC
#define AMIT_PIN_SEGMENT_A       4

#define AMIT_SEGMENT_B           1u
#define AMIT_DDR_SEGMENT_B       DDRC
#define AMIT_PORT_SEGMENT_B      PORTC
#define AMIT_PIN_SEGMENT_B       5

#define AMIT_SEGMENT_C           2u
#define AMIT_DDR_SEGMENT_C       DDRC
#define AMIT_PORT_SEGMENT_C      PORTC
#define AMIT_PIN_SEGMENT_C       6

#define AMIT_SEGMENT_D           3u
#define AMIT_DDR_SEGMENT_D       DDRC
#define AMIT_PORT_SEGMENT_D      PORTC
#define AMIT_PIN_SEGMENT_D       7

extern void SEGMENT_DISPLAY_NUM(unsigned int Num);

#endif /* AMIT_7_SEGMENT_H_ */