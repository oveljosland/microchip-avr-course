/** 
* @file main.c
* @author oveljosland
* @date 2025-04-02
* @brief sample potentiometer values with adc and print to display 
*/

#define F_CPU 24000000UL

#include <avr/io.h>
#include <avr/xmega.h>
#include <stdint.h>

#include "peripherals/adc/adc.h"
#include "display/ssd1306.h"

int main(void)
{
    _PROTECTED_WRITE(CLKCTRL.OSCHFCTRLA, CLKCTRL_FRQSEL_24M_gc); // Set clock to 24MHz

    SSD1306_Init(SSD1306_ADDR);
    SSD1306_ClearScreen();

    // Finish the adc_init() function in the 'peripherals' folder and call it here
    adc_init();

    uint16_t value = 0;
    uint8_t values[MAX_X]; // Buffer to hold the 128 latest ADC reads

    while (1) {
        // Read from adc
        value = adc_read();
        // Try scaling the adc readings to fit the OLED display
        value = value >> 4; // Bit shift right 4 times to divide by 16
        // Add value to last index of buffer
        values[MAX_X-1] = (uint8_t)value;

        SSD1306_ClearScreen();

        // Draw the buffered values as lines on the display
        for (uint8_t i = 1; i < MAX_X; i++) {
            SSD1306_DrawLine(i-1, i-1, MAX_Y, MAX_Y - values[i-1]); // Display start with 0,0 at top left
            values[i-1] = values[i]; // Shift the values buffer to the left
        }
        SSD1306_UpdateScreen(SSD1306_ADDR);
    }    
    return 0;
};

