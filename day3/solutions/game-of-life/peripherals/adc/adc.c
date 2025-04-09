#include "adc.h"
#include <avr/io.h>

/* adc_init: initalize adc in single-ended mode */
void adc_init(void)
{
    VREF.ADC0REF |= VREF_REFSEL_VDD_gc;
    ADC0.CTRLA |= ADC_ENABLE_bm | ADC_CONVMODE_SINGLEENDED_gc | ADC_RESSEL_10BIT_gc;
    ADC0.CTRLC = ADC_PRESC_DIV2_gc;
    ADC0.MUXPOS = ADC_MUXPOS_AINx_gc; /** TODO: replace 'x' with the channel you want to use */

    /** TODO: replace 'x' and 'n' with the port and pin you want to read */
    PORTx.PINnCTRL &= ~PORT_ISC_gm;
    PORTx.PINnCTRL |= PORT_ISC_INPUT_DISABLE_gc;
    PORTx.PINnCTRL &= ~PORT_PULLUPEN_bm;
}

uint16_t adc_read(void)
{
    ADC0.COMMAND = ADC_STCONV_bm;
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm))
        ;
    ADC0.INTFLAGS = ADC_RESRDY_bm;
    return ADC0.RES;
}