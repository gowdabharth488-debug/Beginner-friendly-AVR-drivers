/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

void ADC_init(void);
uint16_t ADC_read(uint8_t channel);

#endif
