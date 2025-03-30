/** 
* @file main.c
* @author oveljosland
* @date 2025-03-03
* @brief blink onboard LED0
*/

#define F_CPU 4000000UL
#include <avr/io.h>
#include "util/delay.h"


int main(void)
{
    PORTB.DIRSET = PIN3_bm;

    while (1) {
        PORTB.OUTSET = PIN3_bm;
        _delay_ms(1000);
        PORTB.OUTCLR = PIN3_bm;
        _delay_ms(1000);
    }
    return 0;
};


//Alternative solution:
/*
PORTB.OUT |= 1 << 0b0001000;
_delay_ms(1000);
PORTB.OUT &= ~(1 << 0b0001000);
_delay_ms(1000);
*/
