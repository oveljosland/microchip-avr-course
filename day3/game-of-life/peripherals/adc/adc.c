#include "adc.h"
#include <avr/io.h>

/* adc_init: initalize adc in differential mode (optional). */
void adc_init(void)
{
    VREF.ADC0REF |= VREF_REFSEL_VDD_gc;
    ADC0.CTRLA |= ADC_ENABLE_bm | ADC_CONVMODE_SINGLEENDED_gc | ADC_RESSEL_10BIT_gc;
    ADC0.CTRLC = ADC_PRESC_DIV2_gc;
    ADC0.MUXPOS = ADC_MUXPOS_AIN0_gc;

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