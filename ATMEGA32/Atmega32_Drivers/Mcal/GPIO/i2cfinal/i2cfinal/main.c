/*
 * i2cfinal.c
 *
 * Created: 2019-06-20 7:50:41 AM
 * Author : Ahmed Elkholi
 */ 

#include <avr/io.h>



   int main(void)
   {
	   i2c_init();
	   i2c_start();
	   i2c_write(0b11010000);
	   i2c_write(0b11110000);
	   i2c_stop();
	   while(1);
	   return 0;
   }




