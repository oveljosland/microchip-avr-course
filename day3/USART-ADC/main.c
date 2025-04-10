/** 
 * @file main.c
 * @author amund
 * @date 2025-04-10
 * @brief Main function 
*/
#define F_CPU 4000000UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

/*In this task the objective is to initialise the USART3 and ADC to read
a value from the potentiometer on the AVR Curiosity nano explorer card and
print it so a Serial Monitor.*/

#define BAUD_9600         //Define 9600 Baud Rate
#define TX_PORT           PORTB
#define TX_PIN            0
#define ADC_CHANNEL       0x0

void usart_init(unsigned long baud) {
    // Set TX pin as output
    

    // Set baud rate
    

    // Enable transmitter and receiver
    
}

void usart_transmit(char data) {
    // Wait for the transmit buffer to be empty
    while (!(USART3.STATUS & USART_DREIF_bm))
        ;

    // Send data
    USART3.TXDATAL = data;
}

void usart_transmit_string(char *data) {
    while (*data) {
        usart_transmit(*data++);
    }
}

void usart_print_voltage(uint16_t data) {
    data = data >> 2;

    uint8_t voltage_integer = data * 323ul / 100000ul;
    uint8_t voltage_fraction = (data * 323ul % 100000ul) / 1000;

    char uart_str[64] = "";
    sprintf(uart_str, "Voltage: %u.%02u V\r\n", voltage_integer, voltage_fraction);
    usart_transmit_string(uart_str);
}

void adc_init() {
// Selects VDD (the supply voltage) as the reference for the ADC
VREF.ADC0REF =

// Enables the ADC (Analog-to-Digital Converter) module by setting the ADC_ENABLE bit in the CTRLA register
ADC0.CTRLA =

// Sets the ADC prescaler to divide the ADC clock by 8. This affects the sampling rate.
ADC0.CTRLC =

// Selects AIN6 (analog input channel 6) as the positive input for the ADC conversion.
ADC0.MUXPOS =

}

uint16_t adc_read(uint8_t channel)
{
	ADC0.INTFLAGS = ADC_RESRDY_bm;
	ADC0.COMMAND = ADC_STCONV_bm;
	while (!(ADC0.INTFLAGS & ADC_RESRDY_bm))
	{
		
	}
	return ADC0.RES;
}

int main(void) {
    //Initialise the functions here

    
    while (1) {
        uint16_t adc_val = adc_read(ADC_CHANNEL);
        usart_print_voltage(adc_val);
        _delay_ms(500);
    }
}