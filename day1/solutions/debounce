#define F_CPU 24000000UL
#include <util/delay.h>
#include <avr/io.h>

// STEP 1: Define pins
// The pins are found in the data sheet and on the board
// LED
// Define the pin for the LED here
#define LED0 3

// Button
// Define the pin for the button here
#define SW0 2

// Hints:
// PORTx.DIR: set direction (input or output) - 1 is output, 0 is input
// PORTx.OUT: set value of pins (1 or 0)
// PORTx.IN: read the value of pins
// PORTx.OUTTGL: toggle output pin value

// LED: 1 -> LED is off, 0 -> LED is on
// SW: 1 -> Button is open, 0 -> button is pressed

// Set to 1: REG |= (1 << BIT_POS)
// Set to 0: REG &= (1 << BIT_POS)


int button_state = 0;

int main(void) {
    // STEP 2: Set up LED and BUTTON pins
    // Set the LED pin as output here
    PORTB.DIR |= (1<<LED0);
    
    // Set the button as input here
    PORTB.DIR &= ~(1 << SW0);
    
    // STEP 3: Enable pull-up for BUTTON pin
    // Set button pin as pull-up
    PORTB.PIN2CTRL |= PORT_PULLUPEN_bm;
    
    // Runs continuously
    while (1) {
        // STEP 4: Toggle LED on BUTTON press
        // Check if button is pressed, but this time you want to toggle the
        // light instead of turning it on/off (hint: OUTTGL or XOR) Add a
        // button-pressed-state so that you don't have to hold the button to
        // turn on the light, but so that you instead toggle between light
        // on/off when the button is pressed (like a light switch): When the
        // button is not pressed the light should hold its current state.
        
        while (1) {
         // Check if button is pressed
         if (!(PORTB.IN & (1 << SW0))){
             if (button_state == 0){
             // Toggle LED if BUTTON press
             PORTB.OUTTGL = (1 << LED0);
             button_state = 1;
             } 
         } else{
             button_state = 0;
         }
         _delay_ms(1);
        }
    }
    
    return 0;
}
