/** 
 * @file dac.h
 * @author Ove Ljosland
 * @date 2025-03-19
*/

#ifndef DAC_H_
#define DAC_H_

#include <avr/io.h>

#define DAC_BITNESS 10
#define DAC_MAX_VAL (1<<DAC_BITNESS)-1

void dac_init(void);
void dac_setval(uint16_t v);

#endif