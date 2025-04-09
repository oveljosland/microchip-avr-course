/** 
 * @file tca.h
 * @author Ove Ljosland
 * @date 2025-03-19
*/

#ifndef TCA_H_
#define TCA_H_

#include <avr/io.h>
#include <math.h>

void tca_init(unsigned tsample);
#ifndef F_CPU
#define F_CPU 24000000UL
#endif

#endif