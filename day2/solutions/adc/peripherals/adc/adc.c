#include "adc.h"

/* adc_init: initialize the adc */
void adc_init(void)
{
    VREF.ADC0REF |= VREF_REFSEL_VDD_gc;
    ADC0.CTRLA |= ADC_CONVMODE_SINGLEENDED_gc;

    ADC0.CTRLA = ADC_ENABLE_bm | ADC_RESSEL_10BIT_gc;
    ADC0.CTRLC = ADC_PRESC_DIV2_gc;
    ADC0.MUXPOS = ADC_MUXPOS_AIN6_gc;

    PORTD.PIN6CTRL &= ~PORT_ISC_gm;
    PORTD.PIN6CTRL |= PORT_ISC_INPUT_DISABLE_gc;
    PORTD.PIN6CTRL &= ~PORT_PULLUPEN_bm;
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

