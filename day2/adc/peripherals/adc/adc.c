#include "adc.h"

/* TODO: finish the adc init function */
/* hint: page 495 in the datasheet */
void adc_init(void)
{
    /* configure voltage reference */
    /* configure resolution */
    /* configure adc clock */
    /* select positive input */
    /* enable the adc */
}

/* adc_read: starts conversion and returns result stored in ADC0.RES register */
uint16_t adc_read(void)
{
    /* start conversion */
    ADC0.COMMAND = ADC_STCONV_bm;
    
    /* wait for result */
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));

    /* raise result ready flag */
    ADC0.INTFLAGS = ADC_RESRDY_bm;

    /* return conversion result */
    return ADC0.RES;
}

