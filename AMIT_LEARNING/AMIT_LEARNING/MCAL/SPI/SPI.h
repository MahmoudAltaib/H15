/*
 * SPI.h
 *
 * Created: 6/12/2019 6:35:34 PM
 *  Author: A.Elkady
 */ 


#ifndef SPI_H_
#define SPI_H_

#define ATMEGA32

#ifdef ATMEGA32

#include "AMIT_SCHEMATIC.h"

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

#define SPI_FLAG 7

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

#endif

#endif /* SPI_H_ */