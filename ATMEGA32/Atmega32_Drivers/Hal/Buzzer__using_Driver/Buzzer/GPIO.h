/*
 * GPIO.h
 *
 * Created: 2019-06-11 9:35:24 PM
 *  Author: Ahmed Elkholi
 */ 


#ifndef GPIO_H_
#define GPIO_H_


#define F_CPU 12000000ul
#include <inttypes.h>
#include <util/delay.h>

#define ATMEGA32

#ifdef ATMEGA32

#define PORT_A 0x3B
#define DDR_A 0x3A
#define PIN_A 0x39

#define PORT_B 0x38
#define DDR_B 0x37
#define PIN_B 0x36

#define PORT_C 0x35
#define DDR_C 0x34
#define PIN_C 0x33

#define PORT_D 0x32
#define DDR_D 0x31
#define PIN_D 0x30

#define INPUT 0
#define OUTPUT 1


#endif

extern void Pin_set(unsigned int PORT_address , uint8_t  Pin_index);
extern void Pin_reset(unsigned int PORT_address , uint8_t Pin_index);
extern void Pin_toggle(unsigned int PORT_address , uint8_t Pin_index);
extern void Pin_mode(unsigned int PORT_address ,unsigned int DDR_address , uint8_t Pin_index , uint8_t Pin_state);
extern void Pin_read(unsigned int PIN_address , uint8_t Pin_index , volatile uint8_t *pointer_reading);


#endif /* GPIO_H_ */


