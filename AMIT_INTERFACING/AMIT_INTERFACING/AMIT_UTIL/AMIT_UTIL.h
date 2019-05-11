/*
 * AMIT_UTIL.h
 *
 * Created: 5/11/2019 2:54:52 PM
 *  Author: hp
 */ 


#ifndef AMIT_UTIL_H_
#define AMIT_UTIL_H_

#define UTIL_SETPIN(PORT_ADDRESS,PIN_NUMBER) ( (*((volatile unsigned int *)(PORT_ADDRESS))) |= (1<<(PIN_NUMBER)) )

#define UTIL_CLEARPIN(PORT_ADDRESS,PIN_NUMBER) ( (*((volatile unsigned int *)(PORT_ADDRESS))) &= (~(1<<(PIN_NUMBER))) )

#define UTIL_TOGGLEPIN(PORT_ADDRESS,PIN_NUMBER) ( (*((volatile unsigned int *)(PORT_ADDRESS))) ^= ((1<<(PIN_NUMBER))) )




#endif /* AMIT_UTIL_H_ */