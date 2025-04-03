/** 
 * @file main.c
 * @author ove
 * @date 2025-04-03
 * @brief conway's game of life 
 */

#include "display/ssd1306.h"
#include <stdlib.h>
#include <util/delay.h>
 
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 64

#define N 1
#define CELL_SIZE 1 << N

#define GRID_WIDTH (uint8_t)(SCREEN_WIDTH >> N)
#define GRID_HEIGHT (uint8_t)(SCREEN_HEIGHT >> N)

uint8_t grid[GRID_WIDTH][GRID_HEIGHT];
uint8_t next[GRID_WIDTH][GRID_HEIGHT];
 
void grid_init(void)
{
    for (uint8_t y = 0; y < GRID_HEIGHT; y++) {
        for (uint8_t x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = rand() % 2;
        }
    }
}

void grid_draw(void)
{
    for (uint8_t y = 0; y < GRID_HEIGHT; y++) {
        for (uint8_t x = 0; x < GRID_WIDTH; x++) {
            if (grid[y][x]) {
                for (uint8_t dy = 0; dy < CELL_SIZE; dy++) {
                    for (uint8_t dx = 0; dx < CELL_SIZE; dx++) {
                        SSD1306_DrawPixel((x << N) + dx, (y << N) + dy);
                    }
                }
            }
        }
    }
}

uint8_t count_neighbors(uint8_t x, uint8_t y) {
    int8_t dx, dy;
    uint8_t n = 0;
    for (dy = -1; dy <= 1; dy++) {
        for (dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int8_t nx = x + dx;
            int8_t ny = y + dy;
            if (nx >= 0 && nx < GRID_WIDTH && ny >= 0 && ny < GRID_HEIGHT) {
                n += grid[ny][nx];
            }
        }
    }
    return n;
}

void grid_update(void) {
    for (uint8_t y = 0; y < GRID_HEIGHT; y++) {
        for (uint8_t x = 0; x < GRID_WIDTH; x++) {
            uint8_t neighbors = count_neighbors(x, y);
            if (grid[y][x] && (neighbors < 2 || neighbors > 3))
                next[y][x] = 0; /* die */
            else if (!grid[y][x] && neighbors == 3)
                next[y][x] = 1; /* become alive */
            else
                next[y][x] = grid[y][x]; /* stay the same */
        }
    }
    
    for (uint8_t y = 0; y < GRID_HEIGHT; y++) {
        for (uint8_t x = 0; x < GRID_WIDTH; x++) {
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

    SSD1306_ClearScreen();
    SSD1306_DrawLine(0, MAX_X, 15, 15);
    SSD1306_DrawLine(0, MAX_X, 47, 47);
    SSD1306_SetPosition(32, 3);
    SSD1306_DrawString("Conway's");
    SSD1306_SetPosition(7, 4);
    SSD1306_DrawString("Game of Life");
    SSD1306_UpdateScreen(SSD1306_ADDR);
    _delay_ms(10000);

    while (1) {
        SSD1306_ClearScreen();
        grid_draw();
        SSD1306_UpdateScreen(SSD1306_ADDR);
        grid_update();
    }
}
 