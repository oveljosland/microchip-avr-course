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
 
void grid_init(void)
{
    for (uint8_t y = 0; y < GRID_SIZE; y++) {
        for (uint8_t x = 0; x < GRID_SIZE; x++) {
            grid[y][x] = rand() % 2; /* Q: is this random? Why / why not? */
        }
    }
}

void grid_draw(void)
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

uint8_t count_neighbors(uint8_t x, uint8_t y) {
    int8_t dx, dy;
    uint8_t n = 0;
    for (dy = -1; dy <= 1; dy++) {
        for (dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int8_t nx = x + dx;
            int8_t ny = y + dy;
            if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE) {
                n += grid[ny][nx];
            }
        }
    }
    return n;
}

void grid_update(void) {
    for (uint8_t y = 0; y < GRID_SIZE; y++) {
        for (uint8_t x = 0; x < GRID_SIZE; x++) {
            uint8_t neighbors = count_neighbors(x, y);
            if (grid[y][x] && (neighbors < 2 || neighbors > 3))
                next[y][x] = 0; /* die */
            else if (!grid[y][x] && neighbors == 3)
                next[y][x] = 1; /* become alive */
            else
                next[y][x] = grid[y][x]; /* stay the same */
        }
    }
    
    for (uint8_t y = 0; y < GRID_SIZE; y++) {
        for (uint8_t x = 0; x < GRID_SIZE; x++) {
            grid[y][x] = next[y][x];
            next[y][x] = 0; /* clear grid */
        }
    }
}


int main(void)
{
    SSD1306_Init(SSD1306_ADDR);
    srand(1);
    grid_init();
 
    while (1) {
        grid_draw();
        grid_update();
       _delay_ms(50);
    }
}
 