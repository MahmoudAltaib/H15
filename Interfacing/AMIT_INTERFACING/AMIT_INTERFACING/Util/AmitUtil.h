/*
 * AmitUtil.h
 *
 * Created: 10/05/2019 09:55:32
 *  Author: pearl
 */ 


#ifndef AMITUTIL_H_
#define AMITUTIL_H_

#ifndef Util_setPin
#define Util_setPin(PORTADD , PINNUM)       ((*((volatile unsigned int *)(PORTADD))) |= (1 << (PINNUM)))
#endif 

#ifndef Util_clrPin
#define Util_clrPin(PORTADD , PINNUM)      ((*((volatile unsigned int *)(PORTADD))) &= ~(1 << (PINNUM)))
#endif 

#ifndef Util_toglePin
#define Util_toglePin(PORTADD , PINNUM)    ((*((volatile unsigned int *)(PORTADD))) ^= (1 << (PINNUM)))
#endif


#endif /* AMITUTIL_H_ */