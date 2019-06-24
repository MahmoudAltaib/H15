/*
 * TWI.h
 *
 * Created: 6/14/2019 2:21:30 PM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef TWI_H_
#define TWI_H_

	/************************************************************************/
	/*                  Start of platform definition                        */
	/************************************************************************/
	#define ATMEGA32
	/************************************************************************/
	/*                  End of platform definition                          */
	/************************************************************************/
	
	#ifdef ATMEGA32

		/************************************************************************/
		/*                               Inclusions                             */
		/************************************************************************/		
		#include "ELKADY_SCHEMATIC.h"

		/************************************************************************/
		/*                    Definition of TWI registers                       */
		/************************************************************************/		
		#define TWI_CR (*((volatile unsigned char *)(0x56)))
		#define TWI_DR (*((volatile unsigned char *)(0x23)))
		#define TWI_AR (*((volatile unsigned char *)(0x22)))
		#define TWI_SR (*((volatile unsigned char *)(0x21)))
		#define TWI_BR (*((volatile unsigned char *)(0x20)))

		// TWI_CR
		#define TWI_INT   7
		#define TWI_EA    6
		#define TWI_STA   5 
		#define TWI_STO   4
		#define TWI_WC    3
		#define TWI_EN    2
		#define TWI_IE    0
		// TWI_SR
		#define TWI_S7 7
		#define TWI_S6 6
		#define TWI_S5 5
		#define TWI_S4 4
		#define TWI_S3 3
		#define TWI_PS1 1
		#define TWI_PS0 0
		//TWI_AR
		#define TWI_A6 7
		#define TWI_A5 6
		#define TWI_A4 5
		#define TWI_A3 4
		#define TWI_A2 3
		#define TWI_A1 2
		#define TWI_A0 1
		#define TWI_GCE 0
		
		/************************************************************************/
		/*                     TWI registers values                             */
		/************************************************************************/
		#define TWI_SR_VALUE ((1 << TWI_PS0) )
		#define TWI_BR_VALUE (80)  // 100KHz
		#define TWI_MASTER_START_VALUE ((1 << TWI_INT) | (1 << TWI_EN) | (1 << TWI_STA))
		#define TWI_MASTER_STOP_VALUE ((1 << TWI_INT) | (1 << TWI_EN) | (1 << TWI_STO))
		
		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/				
		extern void TWI_INIT();
		extern void TWI_START();
		extern void TWI_STOP();
		extern void TWI_TRANSMIT(unsigned char u8Data);
		extern void TWI_RECEIVE_ACK(unsigned char *pu8Received_data);
		extern void TWI_RECEIVE_NOACK(unsigned char *pu8Received_data);
		extern void TWI_TRANSMIT_STRING(unsigned char *pu8Data , uint8_t u8Size);
		extern void TWI_RECEIVE_STRING(unsigned char *pu8Received_data , uint8_t u8Size);
		
		
	#else
		
		#error Define_platform
		
	#endif
	
#endif /* TWI_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/