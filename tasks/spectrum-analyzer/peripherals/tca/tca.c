#include "../tca/tca.h"

void tca_init(unsigned tsample)
{
    /* variable accounting for deviations in counter period, found through empirical testing */
    static float period_error_compensation = 0;
    period_error_compensation = 0.129*pow(tsample,-0.32)*tsample;
    
    /* enable timer overflow interrupt */
	TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;
	
    /* enabling the timer in 16-bit mode with a clock frequency equal to F_CPU/1 */
	TCA0.SINGLE.CTRLA = TCA_SINGLE_ENABLE_bm | TCA_SINGLE_CLKSEL_DIV1_gc; 
    
    /* configuring the timer period (how long it should count) */
	TCA0.SINGLE.PERBUF = (uint16_t)(F_CPU*((float)tsample/(1000000*1)))-period_error_compensation;
}