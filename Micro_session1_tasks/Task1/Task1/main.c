/* LED ON
 * Work1.c
 *
 * Created: 5/4/2019 2:18:46 PM
 * Author : A.Elkady
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	_SFR_IO8(0x11) |= (1<<5);
	_SFR_IO8(0x11) |= (1<<6);
	_SFR_IO8(0x11) |= (1<<7);
    _SFR_IO8(0x12) &= ~(1<<5);
    _SFR_IO8(0x12) &= ~(1<<6);
    _SFR_IO8(0x12) &= ~(1<<7);
    
    while (1) 
    {
		 _SFR_IO8(0x12)  |= (1<<5);
		 _delay_ms(200);
		_SFR_IO8(0x12) &= ~(1<<5);
		 _delay_ms(200);
		_SFR_IO8(0x12) |= (1<<6);
		 _delay_ms(200);
		_SFR_IO8(0x12) &= ~(1<<6);
		 _delay_ms(200);
		_SFR_IO8(0x12) |= (1<<7);
		 _delay_ms(200);
		_SFR_IO8(0x12) &= ~(1<<7);
		 _delay_ms(200);
	}
}

