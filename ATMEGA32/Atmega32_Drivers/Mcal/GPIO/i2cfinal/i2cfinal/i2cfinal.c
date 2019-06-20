/*
 * i2cfinal.c
 *
 * Created: 2019-06-20 7:51:12 AM
 *  Author: Ahmed Elkholi
 */ 

#include <avr/io.h>
#include <i2cfinal.h>

void i2c_init(void)
{
	TWSR=0x00;
	TWBR=0x47;
	TWCR=0x04;
}
void i2c_start(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}
void i2c_write(unsigned char A)
{
 TWDR=A;
 TWCR=(1<<TWEN)|(1<<TWINT);
 	while((TWCR&(1<<TWINT))==0);
}
void i2c_stop()
{
	TWCR=(1<<TWEN)|(1<<TWCR)|(1<<TWSTO);
	};

