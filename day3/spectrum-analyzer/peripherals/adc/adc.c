#include "../adc/adc.h"

/* adc_init: initalize adc in single-ended mode */
void adc_init(void)
{
    VREF.ADC0REF |= VREF_REFSEL_VDD_gc;        /* select voltage reference */
    ADC0.CTRLA |= ADC_CONVMODE_SINGLEENDED_gc; /* select single-ended mode */
    ADC0.CTRLA |= ADC_RESSEL_10BIT_gc;         /* select 10 bit resolution */
    ADC0.CTRLA |= ADC_ENABLE_bm;               /* enable adc */
    ADC0.CTRLC = ADC_PRESC_DIV2_gc;            /* select prescaling */

    /** TODO: replace 'x' with the correct channel for the microphone */
    ADC0.MUXPOS = ADC_MUXPOS_AINx_gc;

    /** TODO: replace 'n' and 'x' with the correct port and pin for the microphone */
    /* hint: take a close look at the Explorer board. */
    PORTn.PINxCTRL &= ~PORT_ISC_gm;
    PORTn.PINxCTRL |= PORT_ISC_INPUT_DISABLE_gc;
    PORTn.PINxCTRL &= ~PORT_PULLUPEN_bm;
}

uint16_t adc_read(void)
{
    ADC0.COMMAND = ADC_STCONV_bm;
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm))
        ;
    ADC0.INTFLAGS = ADC_RESRDY_bm;
    return ADC0.RES;
}