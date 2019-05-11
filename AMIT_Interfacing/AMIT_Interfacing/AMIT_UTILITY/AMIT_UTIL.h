/*
 * AMIT_UTIL.h
 *
 * Created: 5/11/2019 3:10:23 PM
 *  Author: dell
 */ 


#ifndef AMIT_UTIL_H_
#define AMIT_UTIL_H_

#define UTIL_SETPIN(PORTADD , PIN_NUMBER) (((*((volatile unsigned int *)(PORTADD))))|=(1<<(PIN_NUMBER)))
#define UTIL_CLRPIN(PORTADD , PIN_NUMBER) (((*((volatile unsigned int *)(PORTADD)))) &= ~(1<<(PIN_NUMBER)))
#define UTIL_TOGGLEPIN(PORTADD , PIN_NUMBER) (((*((volatile unsigned int *)(PORTADD)))) ^= (1<<(PIN_NUMBER)))




#endif /* AMIT_UTIL_H_ */