#include "../clock/clkctrl.h"


/* clkconfig: initializes main clock frequency */
void clkctrl_init(void)
{
   /* set OSCHF clock to 24 MHz */
   ccp_write_io ((uint8_t *) & CLKCTRL.OSCHFCTRLA,
       CLKCTRL_FRQSEL_24M_gc | CLKCTRL_AUTOTUNE_bm);

    //ccp_write_io((void*)&CLKCTRL.MCLKCTRLB, 0x00); /* 20 Mhz */
}