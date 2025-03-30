/** 
* @file main.c
* @author oveljosland
* @date 2025-03-03
* @brief toggle on-board LED0 with button SW0
*/

#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
 
/* main: use the on-board button to toggle the on-board LED */
int main(void)
{
    PORTB.DIRCLR = /* TODO: set button as input */
    PORTB.DIRSET = /* TODO: set LED as output */
    /* TODO: enable internal pullup for button */
 
    while (1) {
        /* TODO: check the status of button */
    }
}