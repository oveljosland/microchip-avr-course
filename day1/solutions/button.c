/** 
 * @file button.c
 * @author oveljosland
 * @date 2025-03-03
 * @brief toggle on-board LED0 with button SW0
 */

#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    PORTB.DIRCLR = PIN2_bm; /* set SW0 as input */
    PORTB.DIRSET = PIN3_bm; /* set LED0 as output */
    PORTB.PIN2CTRL |= PORT_PULLUPEN_bm; /* enable internal pullup for SW0 */

    while (1) {
        /* check the status of SW0 */
        if (PORTB.IN & PIN2_bm)
            PORTB.OUTSET = PIN3_bm; /* LED0 on */
        else
            PORTB.OUTCLR = PIN3_bm; /* LED0 off */
    }
}
