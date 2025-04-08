/** 
* @file main.c
* @author oveljosland
* @date 2025-04-02
* @brief sample potentiometer values with adc and print to display 
*/

#define F_CPU 24000000UL

#include <avr/io.h>
#include <stdlib.h>
#include "peripherals/adc/adc.h"
#include "display/ssd1306.h"

int main(void)
{
    SSD1306_Init(SSD1306_ADDR);
    SSD1306_ClearScreen();
    adc_init();

    uint8_t value = 0;

    while (1) {
        SSD1306_ClearScreen();
        for (uint8_t i = 0; i < MAX_X; i++) {     
            value = adc_read();
            SSD1306_DrawLine(i, i, MAX_Y, MAX_Y - value); /* display is flipped */
        }
        SSD1306_UpdateScreen(SSD1306_ADDR);
    }    
    return 0;
};

