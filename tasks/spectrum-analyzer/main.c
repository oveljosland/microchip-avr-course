/** 
 * @file main.c
 * @author Ove Ljosland
 * @date 2025-03-19
 * @brief spectrum analyzer using kissFFT
*/

/* --- header files --- */
#include <xc.h>
#include <math.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <avr/cpufunc.h>
#include <avr/interrupt.h> 

#include "config.h"
#include "display/ssd1306.h"

#include "filter/kiss_fftr.h"
#include "filter/sine.h"

#include "peripherals/tca/tca.h"
#include "peripherals/adc/adc.h"
#include "peripherals/dac/dac.h"
#include "peripherals/clock/clkctrl.h"
#include "peripherals/usart/usart3.h"
#include "peripherals/data_streamer/data_streamer.h"

/* --- constants --- */
#define N 8
#define NFFT 1<<N
#define T_SAMPLE 125 /* us */

/* --- variables for signal processing --- */
volatile uint16_t x = 0;
volatile uint16_t i = 0; /* change to uint8_t? */
volatile uint16_t j = 0; /* change to uint8_t? */

volatile uint16_t mean_offset = 0;
volatile int32_t sum = 0;
volatile uint8_t rdy = 0;

kiss_fft_scalar cpx_in[NFFT];

/* process input samples */
ISR(TCA0_OVF_vect)
{
    if (!rdy) {
        x = adc_read();
        dac_setval(x);
        sum += x;
        i++;

        if (i >= NFFT) {
            mean_offset = (uint16_t) (sum >> N);
            sum = i = 0;
        }
        x -= mean_offset;
        cpx_in[j++] = (kiss_fft_scalar) x;

        if (j >= NFFT) {
            rdy = 1;
            j = 0;
        }
    } 
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
}


/* main: plot spectrum on external display */
int main(void)
{
    sei(); 
    clkctrl_init();
    tca_init(T_SAMPLE);
    adc_init(0); /* 0: single-ended mode, 1: differential mode */
    dac_init();
    USART3_Initialize();

    //uint8_t retval = 0;
    //retval = SSD1306_Init(SSD1306_ADDR);
    SSD1306_ClearScreen();
    SSD1306_UpdateScreen(SSD1306_ADDR);  

    volatile int out = (NFFT>>1)+1;

    /* kiss_fftr_alloc: nfft, is_inv_fft, 0, 0 */
    kiss_fftr_cfg cfg = kiss_fftr_alloc(NFFT, 0, NULL, NULL);

    kiss_fft_cpx cpx_out[out];

    volatile int16_t watch_real = 4;
    volatile int16_t watch_imag = 35;
    volatile uint32_t pwr;
    volatile uint8_t pwr_db;
    volatile uint16_t cnt = 0;


    while (1) {
        if (rdy) {
            kiss_fftr(cfg, cpx_in, cpx_out);
            rdy = 0;
        }

        SSD1306_ClearScreen();

        for (int n = 0; n < out; n++) {
            cnt = n;        
            watch_real = cpx_out[n].r;
            watch_imag = cpx_out[n].i;

            pwr = cpx_out[n].r * cpx_out[n].r + cpx_out[n].i * cpx_out[n].i;
            pwr = sqrt(pwr);
            pwr_db = (uint8_t)(20*log10f(pwr));
            
            variableWrite_SendFrame(watch_real, watch_imag, cnt, pwr_db);
            SSD1306_DrawLine(MAX_X - n, MAX_X - n, 0, pwr_db);
        }
        SSD1306_UpdateScreen(SSD1306_ADDR);
    }
    kiss_fft_cleanup();
    return 0; 
};


