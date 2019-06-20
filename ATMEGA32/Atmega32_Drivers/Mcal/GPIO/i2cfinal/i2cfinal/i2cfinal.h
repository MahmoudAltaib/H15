/*
 * i2cfinal.h
 *
 * Created: 2019-06-20 7:51:29 AM
 *  Author: Ahmed Elkholi
 */ 


#ifndef I2CFINAL_H_
#define I2CFINAL_H_


void i2c_init(void);

void i2c_start(void);

void i2c_write(unsigned char);

void i2c_stop();


#endif /* I2CFINAL_H_ */