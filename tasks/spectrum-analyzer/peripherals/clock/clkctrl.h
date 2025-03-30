/** 
 * @file clkctrl.h
 * @author Ove Ljosland
 * @date 2025-03-19
*/

#ifndef CLKCTRL_H_
#define CLKCTRL_H_

#include <xc.h>
#include <avr/cpufunc.h>

void clkctrl_init(void);
#ifndef F_CPU
#define F_CPU 24000000UL
#endif

#endif /* CLKCTRL_H_ */