/*
 * AMIT_UTIL.h
 *
 * Created: 5/11/2019 3:10:07 PM
 *  Author: A.Elkady
 */ 


#ifndef AMIT_UTIL_H_
#define AMIT_UTIL_H_

#define UTIL_SET_PIN(PORT_ADDRESS , PIN_NUMBER) ( *( (volatile unsigned int *)(PORT_ADDRESS) ) |= ( 1 << (PIN_NUMBER) ) )
#define UTIL_CLEAR_PIN(PORT_ADDRESS , PIN_NUMBER) ( *( (volatile unsigned int *)(PORT_ADDRESS) ) &= ~ ( 1 << (PIN_NUMBER) ) )
#define UTIL_TOGGLE_PIN(PORT_ADDRESS , PIN_NUMBER) ( *( (volatile unsigned int *)(PORT_ADDRESS) ) ^= ( 1 << (PIN_NUMBER) ) )
#define UTIL_READ_PIN(PORT_ADDRESS , PIN_NUMBER) ( *( (volatile unsigned int *)(PORT_ADDRESS) ) & ( 1 << (PIN_NUMBER) ) )

#endif /* AMIT_UTIL_H_ */