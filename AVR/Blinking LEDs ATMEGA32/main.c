/* Name: main.c
 * Author: Ahmed
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* insert your hardware initialization here */
    DDRD |= (1<<DDD5);
    DDRD |= (1<<DDD6);
    DDRD |= (1<<DDD7);

        /* insert your main loop code here */
    while (1)
    {
        PORTD |= (1<<PD5);
        PORTD |= (1<<PD6);
        PORTD |= (1<<PD7);
        PORTD &= ~(1<<PD5);
        _delay_ms(100);
        PORTD &= ~(1<<PD6);
        _delay_ms(100);
        PORTD &= ~(1<<PD7);
        _delay_ms(100);
    }
    return 0;   /* never reached */
}
