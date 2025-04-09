/** 
 * @file main.c
 * @author oveljosland
 * @date 2025-03-19
 * @brief spectrum analyzer using kissFFT and SSD1306 OLED display
*/

/**
* INFO: This program computes the Fast Fourier Transform (FFT) of
* the samples from the ADC. In this task you will configure the ADC
* to sample audio from the microphone on the Explorer board, and print
* the power spectrum to the display.
* 
* TODO:
* 1. Finish the 'adc_init' function in 'peripherals/adc/adc.c'
*
* 2. Figure out how to print to the display.
*
* 3. Test the program by using your voice or find a 'frequency sweep' video on YouTube
*    and point your phone speakers to the mic on the Explorer board. When running the
*    frequency sweep, you should observe a frequency component moving upward on the
*    horizontal axis of the spectrum.
*
* 4. Extra: try changing the sampling period T_SAMPLE to see the effects of aliasing.
*
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
#include "peripherals/clk/clk.h"
#include "peripherals/usart/usart3.h"

/* (unused) for streaming to data visualizer */
#include "peripherals/data_streamer/data_streamer.h"

/* --- constants --- */
#define N 8
#define NFFT 1<<N /* FFT block length */

/* try changing the sampling period to see the effects of aliasing */
#define T_SAMPLE 125 /* microseconds */


/* --- variables for signal processing --- */
volatile uint16_t x = 0;
volatile uint16_t i = 0;
volatile uint16_t j = 0;

volatile uint16_t mean_offset = 0;
volatile int32_t sum = 0;
volatile uint8_t rdy = 0;

kiss_fft_scalar cpx_in[NFFT]; /* sample buffer */


/* ISR: process input samples */
ISR(TCA0_OVF_vect)
{
    if (!rdy) {
        x = adc_read();
        sum += x;
        i++;

        if (i >= NFFT) {
            mean_offset = (uint16_t) (sum >> N);
            sum = i = 0;
        }
        x -= mean_offset; /* remove DC component */
        cpx_in[j++] = (kiss_fft_scalar) x;

        if (j >= NFFT) {
            rdy = 1; /* buffer filled */
            j = 0;
        }
    } 
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
}


/* main: plot signal spectrum on external display */
int main(void)
{
    sei(); 
    clk_init();
    tca_init(T_SAMPLE);
    adc_init();
    uint8_t ret = SSD1306_Init(SSD1306_ADDR);

    volatile int out = (NFFT>>1)+1;

    kiss_fftr_cfg cfg = kiss_fftr_alloc(NFFT, 0, NULL, NULL);
    kiss_fft_cpx cpx_out[out];

    volatile uint32_t pwr;
    volatile uint8_t pwr_bs; /* bit shifted */

    while (1) {
        if (rdy) {
            kiss_fftr(cfg, cpx_in, cpx_out);
            rdy = 0;
        }
        SSD1306_ClearScreen();

        for (uint8_t n = 0; n < out; n++) {
  
            /* power spectrum: |H(w)|^2 = Re(w)^2 + Im(w)^2 */
            pwr = cpx_out[n].r * cpx_out[n].r + cpx_out[n].i * cpx_out[n].i;

            /*
            * because of the limited processing power of the CPU,
            * we will scale the spectrum linearly by bit shifting, 
            * avoiding the costly square root and log10 operation.
            * 
            * the proper way to do it would be this,
            * uint8_t pwr_db = 20*log10f(sqrt(pwr))
            */

            pwr_bs = (uint8_t) pwr >> 2;

            /** TODO: plot 'pwr_bs' on the display. */
            /* hint: take a look at the header file 'display/ssd1306.h'. */
            SSD1306_DrawLine(n, n, /* y0 */, /* y1 */); 
        }
        SSD1306_UpdateScreen(SSD1306_ADDR);
    }
    kiss_fft_cleanup();
    return 0; 
};

