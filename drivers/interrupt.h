/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile uint16_t count;

void INT0_init(void);
void Timer1_init_1s(void);

#endif

/*
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile uint16_t pulse_count;    // Flow sensor pulses
extern volatile float flow_l_min;        // Result in L/min

void INT0_init(void);
void Timer1_init_1s(void);

#endif
*/



/* 
################################################Example use case of these concepts#########################
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupts.h"

int main(void)
{
    DDRB |= (1 << PB0);   // LED for status (optional)

    INT0_init();          // Flow sensor on INT0
    Timer1_init_1s();     // Timer1 interrupt

    sei();                // Enable global interrupts

    while (1)
    {
        // Example: LED ON if flow detected
        if (flow_l_min > 0.2)
            PORTB |= (1 << PB0);
        else
            PORTB &= ~(1 << PB0);

        // You can send flow_l_min to UART if needed
    }
}
*/