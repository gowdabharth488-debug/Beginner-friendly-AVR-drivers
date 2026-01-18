/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#ifndef TIMER_ATMEGA328P_H
#define TIMER_ATMEGA328P_H

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

// ------------------ Timer1 Channels ------------------
#define TIMER1_OC1A 0
#define TIMER1_OC1B 1

// ------------------ Function Prototypes ------------------
void Timer0_init(uint8_t mode, uint8_t prescaler, uint8_t pwm_type);
void Timer0_setDuty(uint8_t duty);

void Timer1_init(uint8_t mode, uint8_t prescaler, uint8_t pwm_type, uint8_t channel);
void Timer1_setDuty(uint8_t duty, uint8_t channel);

void Timer2_init(uint8_t mode, uint8_t prescaler, uint8_t pwm_type);
void Timer2_setDuty(uint8_t duty);

#endif


/*
#############################  Example use case ###############################
#include "timer.h"

int main(void)
{
    // Timer0 -> PB3 (OC0)
    Timer0_init(TIMER_MODE_FAST_PWM, TIMER_PRESCALER_64, PWM_NON_INVERTING);
    Timer0_setDuty(50);

    // Timer1 -> PB1 (OC1A)
    Timer1_init(TIMER_MODE_FAST_PWM, TIMER_PRESCALER_64, PWM_NON_INVERTING, TIMER1_OC1A);
    Timer1_setDuty(75, TIMER1_OC1A);

    // Timer1 -> PB2 (OC1B)
    Timer1_init(TIMER_MODE_FAST_PWM, TIMER_PRESCALER_64, PWM_NON_INVERTING, TIMER1_OC1B);
    Timer1_setDuty(30, TIMER1_OC1B);

    // Timer2 -> PD3 (OC2)
    Timer2_init(TIMER_MODE_FAST_PWM, TIMER_PRESCALER_64, PWM_NON_INVERTING);
    Timer2_setDuty(60);

    while(1)
    {
        // PWM runs automatically
    }
}

*/