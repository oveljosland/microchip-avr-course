/** 
 * @file main.c
 * @author ove
 * @date 2025-04-03
 * @brief conway's game of life 
 */

#include "display/ssd1306.h"
#include <util/delay.h>
#include <stdlib.h>
 
#define N 1
#define M 5
 
#define CELL_SIZE 1 << N
#define GRID_SIZE 32
 
uint8_t grid[GRID_SIZE][GRID_SIZE];
uint8_t next[GRID_SIZE][GRID_SIZE];
 
void grid_init()
{
    for (uint8_t y = 0; y < GRID_SIZE; y++) {
        for (uint8_t x = 0; x < GRID_SIZE; x++) {
            grid[y][x] = rand() % 2; /* Q: is this random? Why / why not? */
        }
    }
}

void grid_draw()
{
    SSD1306_ClearScreen();
    for (uint8_t y = 0; y < GRID_SIZE; y++) {
        for (uint8_t x = 0; x < GRID_SIZE; x++) {
            if (grid[y][x]) {
                for (uint8_t dy = 0; dy < CELL_SIZE; dy++) {
                    for (uint8_t dx = 0; dx < CELL_SIZE; dx++) {
                        SSD1306_DrawPixel((x << N) + dx, (y << N) + dy);
                    }
                }
            }
        }
    }
    SSD1306_UpdateScreen(SSD1306_ADDR);
}

int main(void)
{
    SSD1306_Init(SSD1306_ADDR);
    srand(1);
    grid_init();
 
    while (1) {
       _delay_ms(50);
    }
}
 