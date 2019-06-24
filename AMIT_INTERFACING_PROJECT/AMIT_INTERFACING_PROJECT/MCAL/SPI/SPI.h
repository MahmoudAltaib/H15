/*
 * SPI.h
 *
 * Created: 6/12/2019 6:35:34 PM
 *  Author: A.Elkady
 */ 

/************************************************************************/
/*                   Start of header file guard                         */
/************************************************************************/
#ifndef SPI_H_
#define SPI_H_

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
		/*                    Definition of SPI registers                       */
		/************************************************************************/
		#define SPI_SR (*((volatile unsigned char *)(0x2e)))
		#define SPI_CR (*((volatile unsigned char *)(0x2d)))
		#define SPI_DR (*((volatile unsigned char *)(0x2f)))

		#define SPI_SS_PORT PORT_B
		#define SPI_SS_PIN PIN_B
		#define SPI_SS_DDR DDR_B
		#define SPI_SS_PIN_Number 4

		#define SPI_MOSI_PORT PORT_B
		#define SPI_MOSI_PIN PIN_B
		#define SPI_MOSI_DDR DDR_B
		#define SPI_MOSI_PIN_Number 5

		#define SPI_MISO_PORT PORT_B
		#define SPI_MISO_PIN PIN_B
		#define SPI_MISO_DDR DDR_B
		#define SPI_MISO_PIN_Number 6

		#define SPI_SCK_PORT PORT_B
		#define SPI_SCK_PIN PIN_B
		#define SPI_SCK_DDR DDR_B
		#define SPI_SCK_PIN_Number 7
		
		// SPI_CR
		#define SPI_R0 0
		#define SPI_R1 1
		#define SPI_CPHA 2
		#define SPI_CPOL 3
		#define SPI_MSTR 4
		#define SPI_DORD 5
		#define SPI_ENABLE 6
		#define SPI_INT_ENABLE 7
		
		// SPI_SR
		#define SPI_2x 0
		#define SPI_WCOL 6
		#define SPI_FLAG 7

		/************************************************************************/
		/*                     SPI registers values                             */
		/************************************************************************/		
		#define SPI_CR_MASTER_VALUE ((1 << SPI_R0) | (1 << SPI_DORD) | (1 << SPI_ENABLE) | (1 << SPI_MSTR))
		#define SPI_CR_SLAVE_VALUE ((1 << SPI_ENABLE))

		/************************************************************************/
		/*                      Functions prototypes                            */
		/************************************************************************/
		extern void SPI_MASTER_INIT(void);
		extern void SPI_SLAVE_INIT(void);

		extern void SPI_DEINIT(void);

		extern void SPI_MASTER_TRANSMIT(unsigned char u8Data);
		extern void SPI_MASTER_TRANSMIT_STRING(unsigned char *pu8Data , uint8_t u8Size);

		extern void SPI_SLAVE_TRANSMIT(unsigned char u8Data);
		extern void SPI_SLAVE_TRANSMIT_STRING(unsigned char *pu8Data , uint8_t u8Size);

		extern void SPI_MASTER_RECEIVE(unsigned char *pu8Received_data);
		extern void SPI_MASTER_RECEIVE_STRING(unsigned char *pu8Received_data , uint8_t u8Size);

		extern void SPI_SLAVE_RECEIVE(unsigned char *pu8Received_data);
		extern void SPI_SLAVE_RECEIVE_STRING(unsigned char *pu8Received_data , uint8_t u8Size);

	#else
	
		#error "DEFINE PLATFORM"

	#endif

#endif /* SPI_H_ */
/************************************************************************/
/*                       End of header file guard                       */
/************************************************************************/