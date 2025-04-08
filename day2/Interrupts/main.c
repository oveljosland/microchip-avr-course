/** 
 * @file main.c
 * @author amund
 * @date 2025-04-08
 * @brief Main function 
 */
 #define F_CPU 24000000UL

 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include <util/delay.h>
 
 
 // --- Interrupt Service Routine for PORTB ---
 ISR(PORTB_PORT_vect) {
    /*Write your code here*/
    // Toggle LED on PB3
    // Debounce
    // Clear interrupt flag for PB2 only
 }
 
 int main(void) {
    /*Write your code here*/     
    // Enable global interrupts
 
    // Configure PB3 as output (LED)
    
 
    // Configure PB2 as input with pull-up and interrupt on falling edge
     
 
     while (1) {
         // Main loop does nothing, waits for interrupt
     }
 }
 