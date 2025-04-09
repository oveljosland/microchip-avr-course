#include "../adc/adc.h"

/* adc_init: initalize adc in single-ended mode */
void adc_init(void)
{
    VREF.ADC0REF |= VREF_REFSEL_VDD_gc; /* select voltage reference */
    ADC0.CTRLA |= ADC_CONVMODE_SINGLEENDED_gc; /* select single-ended mode */
    ADC0.CTRLA |= ADC_RESSEL_10BIT_gc; /* select 10 bit resolution */
    ADC0.CTRLA |= ADC_ENABLE_bm; /* enable adc */
    ADC0.CTRLC = ADC_PRESC_DIV2_gc; /* select prescaling */
    ADC0.MUXPOS = ADC_MUXPOS_AIN0_gc; /* TODO: select microphone as positive input */

    /* TODO: select correct pin for the microphone */
    PORTD.PIN0CTRL &= ~PORT_ISC_gm;
    PORTD.PIN0CTRL |= PORT_ISC_INPUT_DISABLE_gc;
    PORTD.PIN0CTRL &= ~PORT_PULLUPEN_bm;
}

uint16_t adc_read(void)
{
    ADC0.COMMAND = ADC_STCONV_bm;
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm))
        ;
    ADC0.INTFLAGS = ADC_RESRDY_bm;
    return ADC0.RES;
}