/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#include "timer_attiny13.h"

// ==================== TIMER0 ====================
void Timer0_init(uint8_t mode, uint8_t prescaler, uint8_t pwm_type, uint8_t channel)
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
        if(channel == TIMER0_OC0A)
        {
            if(pwm_type == PWM_INVERTING)
                TCCR0A |= (1 << COM0A0) | (1 << COM0A1);
            else
                TCCR0A |= (1 << COM0A1);

            DDRB |= (1 << PB0); // OC0A output
        }
        else if(channel == TIMER0_OC0B)
        {
            if(pwm_type == PWM_INVERTING)
                TCCR0A |= (1 << COM0B0) | (1 << COM0B1);
            else
                TCCR0A |= (1 << COM0B1);

            DDRB |= (1 << PB1); // OC0B output
        }
    }

    // Set prescaler
    switch(prescaler)
    {
        case TIMER_PRESCALER_1:    TCCR0B |= (1 << CS00); break;
        case TIMER_PRESCALER_8:    TCCR0B |= (1 << CS01); break;
        case TIMER_PRESCALER_64:   TCCR0B |= (1 << CS01) | (1 << CS00); break;
        case TIMER_PRESCALER_256:  TCCR0B |= (1 << CS02); break;
        case TIMER_PRESCALER_1024: TCCR0B |= (1 << CS02) | (1 << CS00); break;
        default: break;
    }
}

void Timer0_setDuty(uint8_t duty, uint8_t channel)
{
    uint8_t value = (duty * 255UL) / 100;
    if(channel == TIMER0_OC0A) OCR0A = value;
    else if(channel == TIMER0_OC0B) OCR0B = value;
}
