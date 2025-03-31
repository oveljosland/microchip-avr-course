#include "../dac/dac.h"

void dac_init(void)
{
    PORTD.PIN6CTRL &= ~PORT_ISC_gm;
    PORTD.PIN6CTRL |= PORT_ISC_INPUT_DISABLE_gc;
    PORTD.PIN6CTRL &= ~PORT_PULLUPEN_bm;
    VREF.DAC0REF |= VREF_REFSEL_VDD_gc;
    DAC0.CTRLA = DAC_ENABLE_bm | DAC_OUTEN_bm;
} 

void dac_setval(uint16_t v)
{
    DAC0.DATAL = (v & 0x03) << 6;
    DAC0.DATAH = v >> 2;
} 