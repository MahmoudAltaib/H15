/*
 * AMIT_LED.h
 *
 * Created: 5/11/2019 4:52:10 PM
 *  Author: A.Elkady
 */ 


#ifndef AMIT_LED_H_
#define AMIT_LED_H_

#include "PORT_DIO.h"

#define AMIT_DDR_LED1 DDRD
#define AMIT_PORT_LED1 PORTD
#define AMIT_LED1_NUM 5

#define AMIT_DDR_LED2 DDRD
#define AMIT_PORT_LED1 PORTD
#define AMIT_LED2_NUM 6

#define AMIT_DDR_LED3 DDRD
#define AMIT_PORT_LED1 PORTD
#define AMIT_LED3_NUM 7

extern void LED_ON(unsigned int LED_Num);

#endif /* AMIT_LED_H_ */