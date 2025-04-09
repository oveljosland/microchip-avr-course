/** 
* @file main.c
* @author oveljosland
* @date 2025-04-03
* @brief conway's game of life
*/

/** INFO: This program implements Conway's Game of Life.
* Game of Life is a '0-player game' where cells evolve over time
* based on a set of rules. The game takes place on a grid of cells,
* where each cell can be in one of two states, alive or dead.
* The evolution of the grid is determined by the initial state
* (the seed), and proceeds in discrete steps (generations), with each cell's next
* state determined by the states of its eight neighbors.
*  
* Example: Cell X has 3 live neighbouring cells.
*  0 0 1
*  1 X 0
*  0 1 0
*
* Rules:
*   1. Any live cell with fewer than two live neighbors dies (underpopulation).
*   2. Any live cell with two or three live neighbors lives on to the next generation.
*   3. Any live cell with more than three live neighbors dies (overpopulation).
*   4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction).
*
* The program updates the grid based on these rules to simulate life cycles.
* 
* TODO: Implement the rules above in the 'grid_update' function.
*
* TODO: If you have tried running the program more than once, you may have noticed that
*       the outcome is exactly the same every time. This is because Game of Life is
*       deterministic; the outcome will remain the same if the seed remains
*       the same. This is also true for the 'rand' function in 'grid_init'.
*       Therefore, to get a different initial pattern each time we run the program,
*       we need to seed the random number generator with a changing value. Using the
*       current time is usually a good idea, however, since the microcontroller has no
*       concept of time, we have to figure out something else.
*       
*       hint: noise.
*       
*       Look for these lines:
*           uint16_t seed = 0;
*           srand(seed);
*/


#define F_CPU 24000000UL

#include "display/ssd1306.h"
#include "peripherals/adc/adc.h"
#include <stdlib.h>
#include <util/delay.h>
 
//#define SCREEN_WIDTH 128 /* only works on half of the display for some reason */
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

/* grid_draw: draw the cells on the grid */
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

/* count_neighbours: count neighbouring cells */
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

/* grid_update: update grid for the next generation */
void grid_update(void) {
    for (uint8_t y = 0; y < GRID_HEIGHT; y++) {
        for (uint8_t x = 0; x < GRID_WIDTH; x++) {
            uint8_t neighbors = count_neighbors(x, y);
            if (grid[y][x] && (neighbors < 2 || neighbors > 3))
                /** TODO: the cell dies from under/overpopulation :( */
            else if (!grid[y][x] && neighbors == 3)
                /** TODO: the cell becomes alive! */
            else
                /** TODO: the cell stays the same */
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

    /** TODO: seed the random number generator with a changing value */
    /* another hint: peripherals */

    uint16_t seed = 0  /** TODO: replace the seed */
    srand(seed);

    grid_init();

    SSD1306_ClearScreen();
    SSD1306_DrawLine(0, MAX_X, 15, 15);
    SSD1306_DrawLine(0, MAX_X, 47, 47);
    SSD1306_SetPosition(32, 3);
    SSD1306_DrawString("Conway's");
    SSD1306_SetPosition(7, 4);
    SSD1306_DrawString("Game of Life");
    SSD1306_UpdateScreen(SSD1306_ADDR);
    _delay_ms(3000);

    while (1) {
        SSD1306_ClearScreen();
        grid_draw();
        grid_update();
        SSD1306_UpdateScreen(SSD1306_ADDR);
    }
}
 