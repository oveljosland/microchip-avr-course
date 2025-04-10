/** 
* @file main.c
* @author oveljosland
* @date 2025-04-02
* @brief use the adc to sample sensor data 
*/

#define F_CPU 24000000UL

#include <avr/io.h>
#include <avr/xmega.h>
#include <stdint.h>

#include "peripherals/adc/adc.h"
#include "display/ssd1306.h"


int main(void)
{
    _PROTECTED_WRITE(CLKCTRL.OSCHFCTRLA, CLKCTRL_FRQSEL_24M_gc); // Clock set to 24MHz
    
    SSD1306_Init(SSD1306_ADDR);
    SSD1306_ClearScreen();
    uint8_t value = 0;

    /* TODO: finish the adc_init() function in the 'peripherals' folder */
    /* TODO: (optional) initialize other sensors */

    while (1) {
        /* read from adc */
        value = adc_read();
        /* tip: try mapping the adc readings to the LEDs or OLED display */

        /* hint: take a look at the datasheet and the hardware user guide */
        
        SSD1306_ClearScreen();
        for (uint8_t i = 0; i < MAX_X; i++) {     
            value = adc_read();
            SSD1306_DrawLine(i, i, MAX_Y, MAX_Y - value); /* display is flipped */
        }
        SSD1306_UpdateScreen(SSD1306_ADDR);
    }    
    return 0;
};
