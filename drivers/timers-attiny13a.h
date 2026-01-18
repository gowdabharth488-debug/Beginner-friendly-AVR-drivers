/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#ifndef TIMER_ATTINY13_H
#define TIMER_ATTINY13_H

#include <avr/io.h>

// ------------------ Timer Modes ------------------
#define TIMER_MODE_NORMAL    0
#define TIMER_MODE_PHASE_PWM 1
#define TIMER_MODE_FAST_PWM  2

// ------------------ Prescalers ------------------
#define TIMER_STOP        0
#define TIMER_PRESCALER_1 1
#define TIMER_PRESCALER_8 2
#define TIMER_PRESCALER_64 3
#define TIMER_PRESCALER_256 4
#define TIMER_PRESCALER_1024 5

// ------------------ PWM Types ------------------
#define PWM_NON_INVERTING 0
#define PWM_INVERTING     1

// ------------------ Timer0 Channels ------------------
#define TIMER0_OC0A 0
#define TIMER0_OC0B 1

// ------------------ Function Prototypes ------------------
void Timer0_init(uint8_t mode, uint8_t prescaler, uint8_t pwm_type, uint8_t channel);
void Timer0_setDuty(uint8_t duty, uint8_t channel);

#endif


/*
################################ EXample use case ########################
#include "timer.h"

int main(void)
{
    // Timer0 Fast PWM OC0A -> PB0, non-inverting, prescaler 64
    Timer0_init(TIMER_MODE_FAST_PWM, TIMER_PRESCALER_64, PWM_NON_INVERTING, TIMER0_OC0A);
    Timer0_setDuty(70, TIMER0_OC0A);
    Timer0_setFrequency(1000, TIMER0_OC0A); // 1 kHz

    // Timer0 Fast PWM OC0B -> PB1, inverting, prescaler 64
    Timer0_init(TIMER_MODE_FAST_PWM, TIMER_PRESCALER_64, PWM_INVERTING, TIMER0_OC0B);
    Timer0_setDuty(50, TIMER0_OC0B);
    Timer0_setFrequency(2000, TIMER0_OC0B); // 2 kHz

    while(1)
    {
        // PWM runs automatically
    }
}

*/