/*
 * AMIT_UTL.h
 *
 * Created: 11-May-19 4:10:18 PM
 *  Author: acer
 */ 


#ifndef AMIT_UTL_H_
#define AMIT_UTL_H_
#define UTL_SET_PIN(PORT_ADR , PIN_NMR ) (((*((volatile unsigned int *)(PORT_ADR)))) |= (1<<(PIN_NMR)))
#define UTL_CLR_PIN(PORT_ADR , PIN_NMR ) (((*((volatile unsigned int *)(PORT_ADR)))) &= ~(1<<(PIN_NMR)))
#define UTL_TOGGLE_PIN(PORT_ADR , PIN_NMR ) (((*((volatile unsigned int *)(PORT_ADR)))) ^= (1<<(PIN_NMR)))





#endif /* AMIT_UTL_H_ */