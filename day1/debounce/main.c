/** 
 * @file main.c
 * @author ove
 * @date 2025-03-27
 * @brief debounce button 
 */

 #include <avr/io.h>
 #include <util/delay.h>
 

 /* define CPU clock frequency */

 /* define LED pin (optional) */

int main(void)
{
    /* PORTn.DIR: set direction */
    /* PORTn.OUT: set value */
    /* PORTn.IN: read value of pins */


    /* tip: to set a bit to 0, use REG &= ~(1 << BIT_POS) */
    /* tip: to set a bit to 1, use REG |= (1 << BIT_POS) */
    /* this is called 'read-modify-write' */

    /* TODO: set up LED0 and button SW0, don't forget the pull-up! */

    while (1) {
        /* TODO: check if the button is pressed */
        /* TODO: toggle the LED with the button */
        
        /* the button should function as a traditional light switch */
    }

    return 0;
};