/** 
 * @file main.c
 * @author amund
 * @date 2025-04-08
 * @brief Main function 
 */
 #define F_CPU 4000000UL

 #include <avr/interrupt.h>
 #include <avr/io.h>
 #include <util/delay.h>
 
 // STEP 1:
 // Define two LED pins
 
 
 int main(void) {
     // STEP 2: Set both LEDs as output (hint: dirset)
    
     // STEP 3: Set the first LED as high (hint: portset)
     // Toggle the first LED. Just so that we get that the first LED will be off
     // when the second is on and vice versa
 
     // STEP 4: Set the period of the timer
     // The period of the timer, the value the timer will count up to
     // TCA0 = Timer/Counter type A
     // SINGLE = Normal mode of operation
     // PER = Period
 
     // STEP 5: Enable the timer
     // TCA0 = Timer/Counter type A
     // ENABLE = Enable Timer/Counter
     // SINGLE = Normal mode of operation
     // INTCTRL = Interrupt Control
     // OVF = Overflow Interrupt Enable
     // We enable interrupt on overflow, that is when the timer counts up to the
     // TCA0.SINGLE.PER defined above (reaches the TOP value)
 
     // STEP 6: Set timer frequency
     // CTRLA = Control A
     // CLKSEL = Clock Select
     // DIV256 = Divide by 256  
     // We set the timer frequency to main clock / 256 and enable it
 
     // Enables interrupt. Without this, the ISR will not be called
     sei();
 
     while (1) {}
 }
 
 // Timer overflow interrupt
 ISR(TCA0_OVF_vect) {
     // STEP 7: Toggle LEDs
     // Toggle both LEDs when the timer has overflowed (reached the TOP value)
 
     // STEP 8: Clear interrupt flag when interrupt is triggered
     // We clear the interrupt overflow flag. We need to do this in order to
     // 'tell' the CPU that we have 'acknowledged' the interrupt and can move on
 }
 
 
 
 