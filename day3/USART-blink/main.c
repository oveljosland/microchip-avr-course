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

#define BAUD_9600         ((4UL * F_CPU) / 9600)
#define TX_PORT           PORTB
#define TX_PIN            0
#define ADC_CHANNEL       0x0

void usart_init(unsigned long baud) {
    // Set TX pin as output
    PORTB.DIRSET = (1 << TX_PIN); // Set PB0 (TX) as output

    // Set baud rate
    USART3.BAUD = (uint16_t)baud;

    // Enable transmitter and receiver
    USART3.CTRLB |= USART_TXEN_bm | USART_RXEN_bm;
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
	VREF.ADC0REF = VREF_REFSEL_VDD_gc;
	ADC0.CTRLA = ADC_ENABLE_bm;
	ADC0.CTRLC = ADC_PRESC_DIV8_gc;
	ADC0.MUXPOS = ADC_MUXPOS_AIN6_gc;
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
    usart_init(BAUD_9600);
    adc_init();

    while (1) {
        uint16_t adc_val = adc_read(ADC_CHANNEL);
        usart_print_voltage(adc_val);
        _delay_ms(500);
    }
}