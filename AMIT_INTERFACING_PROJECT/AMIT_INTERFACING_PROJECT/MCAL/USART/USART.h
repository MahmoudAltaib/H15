/*
 * USART.h
 *
 * Created: 6/6/2019 9:11:52 AM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef USART_H_
#define USART_H_

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
		/*                       Definition of USART registers                  */
		/************************************************************************/
		#define USART_CSRC (*((volatile unsigned char *)(0x40)))  // Multiple use with USART_BRRH >> URSEL is set to choose which one will override
		#define USART_BRRH (*((volatile unsigned char *)(0x40)))  // Multiple use with USART_CSRC >> URSEL is set to choose which one will override
		#define USART_BRRL (*((volatile unsigned char *)(0x29)))

		#define USART_DR (*((volatile unsigned char *)(0x2c)))

		#define USART_CSRA (*((volatile unsigned char *)(0x2b)))
		#define USART_CSRB (*((volatile unsigned char *)(0x2a)))

		// CSRA
		#define USART_MPCM 0
		#define USART_U2X 1
		#define USART_PE 2
		#define USART_DOR 3
		#define USART_FE 4
		#define USART_DRE 5
		#define USART_TXC 6
		#define USART_RXC 7
		// CSRB
		#define USART_TXB8 0
		#define USART_RXB8 1
		#define USART_UCSZ2 2
		#define USART_TXEN 3
		#define USART_RXEN 4
		#define USART_DRIE 5
		#define USART_TXCIE 6
		#define USART_RXCIE 7
		// CSRC
		#define USART_CPOL 0
		#define USART_CSZ0 1
		#define USART_CSZ1 2
		#define USART_SBS 3
		#define USART_PM0 4
		#define USART_PM1 5
		#define USART_MSEL 6
		#define USART_RSEL 7
		
		/************************************************************************/
		/*                     USART registers values                           */
		/************************************************************************/
		#define USART_CSR_C_VALUE ((1 << USART_RSEL) | (1 << USART_CSZ0) | (1 << USART_CSZ1))
		#define USART_CSR_B_VALUE ((1 << USART_RXCIE) | (1 << USART_TXCIE) | (1 << USART_DRIE) | (1 << USART_RXEN) | (1 << USART_TXEN))
		#define USART_BRRL_VALUE (0x33)

		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/			
		extern void USART_INIT(void);
		extern void USART_DEINIT(void);
		extern void USART_TRANSMIT(char u8Transmitted_data);
		extern void USART_TRANSMIT_STRING(char *pu8Transmitted_string , char u8Transmitted_string_size);
		extern void USART_RECEIVE(char *pu8Received_data);						
		extern void USART_TRANSMIT_CERTAIN_STRING(char *pu8String , char u8Transmitted_data_size);

	#else
	
		#error "DEFINE PLATFORM"

	#endif

#endif /* USART_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/
