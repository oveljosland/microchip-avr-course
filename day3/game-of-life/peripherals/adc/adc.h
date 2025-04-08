/** 
 * @file adc.h
 * @author Ove Ljosland
 * @date 2025-03-19
*/

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void adc_init(void);
uint16_t adc_read(void);


#endif