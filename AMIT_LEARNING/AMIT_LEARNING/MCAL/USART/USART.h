/*
 * USART.h
 *
 * Created: 6/6/2019 9:11:52 AM
 *  Author: A.Elkady
 */ 

#ifndef USART_H_
#define USART_H_

#define ATMEGA32

#ifdef ATMEGA32

#include "AMIT_SCHEMATIC.h"

#define USART_CSRC (*((volatile unsigned char *)(0x40)))  // Multiple use with USART_BRRH >> URSEL is set to choose which one will override
#define USART_BRRH (*((volatile unsigned char *)(0x40)))  // Multiple use with USART_CSRC >> URSEL is set to choose which one will override
#define USART_BRRL (*((volatile unsigned char *)(0x29)))

#define USART_DR (*((volatile unsigned char *)(0x2c)))

#define USART_CSRA (*((volatile unsigned char *)(0x2b)))
#define USART_CSRB (*((volatile unsigned char *)(0x2a)))

#define USART_RXC 7
#define USART_TXC 6
#define USART_DRE 5

extern void USART_INIT();
extern void USART_DEINIT();
extern void USART_TRANSMIT(char u8Transmitted_data);
extern void USART_TRANSMIT_STRING(char *pu8Transmitted_string , char u8Transmitted_string_size);
extern void USART_RECEIVE(char *pu8Received_data);						
extern void USART_TRANSMIT_CERTAIN_STRING(char *pu8String , char u8Transmitted_data_size);

#endif

#endif /* USART_H_ */

