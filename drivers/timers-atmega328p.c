/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#include "timer_atmega328p.h"

// ==================== TIMER0 ====================
void Timer0_init(uint8_t mode, uint8_t prescaler, uint8_t pwm_type)
{
    TCCR0A = 0;
    TCCR0B = 0;

    switch(mode)
    {
        case TIMER_MODE_FAST_PWM:
            TCCR0A |= (1 << WGM00) | (1 << WGM01);
            break;
        case TIMER_MODE_PHASE_PWM:
            TCCR0A |= (1 << WGM00);
            break;
        case TIMER_MODE_NORMAL:
        default:
            break;
    }

    if(mode >= TIMER_MODE_PHASE_PWM)
    {
        if(pwm_type == PWM_INVERTING)
            TCCR0A |= (1 << COM0A0) | (1 << COM0A1);
        else
            TCCR0A |= (1 << COM0A1);

        DDRB |= (1 << PB3); // OC0 output
    }

    // Set prescaler
    TCCR0B |= prescaler;
}

void Timer0_setDuty(uint8_t duty)
{
    OCR0A = (duty * 255UL) / 100;
}

// ==================== TIMER1 ====================
void Timer1_init(uint8_t mode, uint8_t prescaler, uint8_t pwm_type, uint8_t channel)
{
    TCCR1A = 0;
    TCCR1B = 0;

    switch(mode)
    {
        case TIMER_MODE_FAST_PWM:
            TCCR1A |= (1 << WGM10) | (1 << WGM11);
            break;
        case TIMER_MODE_PHASE_PWM:
            TCCR1A |= (1 << WGM10);
            break;
        case TIMER_MODE_NORMAL:
        default:
            break;
    }

    if(mode >= TIMER_MODE_PHASE_PWM)
    {
        if(channel == TIMER1_OC1A)
        {
            if(pwm_type == PWM_INVERTING)
                TCCR1A |= (1 << COM1A0) | (1 << COM1A1);
            else
                TCCR1A |= (1 << COM1A1);

            DDRD |= (1 << PD5); // OC1A
        }
        else if(channel == TIMER1_OC1B)
        {
            if(pwm_type == PWM_INVERTING)
                TCCR1A |= (1 << COM1B0) | (1 << COM1B1);
            else
                TCCR1A |= (1 << COM1B1);

            DDRD |= (1 << PD4); // OC1B
        }
    }

    TCCR1B |= prescaler;
}

void Timer1_setDuty(uint8_t duty, uint8_t channel)
{
    uint16_t value = (duty * 1023UL) / 100;
    if(channel == TIMER1_OC1A) OCR1A = value;
    else if(channel == TIMER1_OC1B) OCR1B = value;
}

// ==================== TIMER2 ====================
void Timer2_init(uint8_t mode, uint8_t prescaler, uint8_t pwm_type)
{
    TCCR2A = 0;
    TCCR2B = 0;

    switch(mode)
    {
        case TIMER_MODE_FAST_PWM:
            TCCR2A |= (1 << WGM20) | (1 << WGM21);
            break;
        case TIMER_MODE_PHASE_PWM:
            TCCR2A |= (1 << WGM20);
            break;
        case TIMER_MODE_NORMAL:
        default:
            break;
    }

    if(mode >= TIMER_MODE_PHASE_PWM)
    {
        if(pwm_type == PWM_INVERTING)
            TCCR2A |= (1 << COM2A0) | (1 << COM2A1);
        else
            TCCR2A |= (1 << COM2A1);

        DDRD |= (1 << PD7); // OC2 output
    }

    TCCR2B |= prescaler;
}

void Timer2_setDuty(uint8_t duty)
{
    OCR2A = (duty * 255UL) / 100;
}
