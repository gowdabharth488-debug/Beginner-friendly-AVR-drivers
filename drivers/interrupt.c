/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#include "interrupts.h"

volatile uint16_t count = 0;

// -------------------- INT0 ISR --------------------
ISR(INT0_vect)
{
    count++;        // Increase count on every external interrupt
}

// -------------------- TIMER1 ISR (1 Second) --------------------
ISR(TIMER1_COMPA_vect)
{
    // Add sensor-based logic here
    // Example:
    // if (count > 100) { do something; }

    // Reset count every 1 second (optional)
    // count = 0;
}

// -------------------- INT0 SETUP --------------------
void INT0_init(void)
{
    MCUCR |= (1 << ISC01);   // Falling edge on INT0
    GICR  |= (1 << INT0);    // Enable INT0 interrupt
}

// -------------------- TIMER1 SETUP --------------------
void Timer1_init_1s(void)
{
    TCCR1B |= (1 << WGM12);       // CTC mode
    OCR1A = 15624;                // 1 second at 16MHz, prescaler 1024
    TIMSK |= (1 << OCIE1A);       // Enable compare interrupt
    TCCR1B |= (1 << CS12) | (1 << CS10);  // Start timer, prescaler 1024
}


/*
#include "interrupts.h"

volatile uint16_t pulse_count = 0;
volatile float flow_l_min = 0;

// -------- INT0 ISR: Count flow pulses --------
ISR(INT0_vect)
{
    pulse_count++;
}

// -------- TIMER1 ISR: Every 1 second --------
ISR(TIMER1_COMPA_vect)
{
    // Convert pulses/sec to L/min
    // Formula for YF-S201: L/min = Hz / 7.5
    flow_l_min = (float)pulse_count / 7.5;

    pulse_count = 0;   // Reset for next second
}

// ---- Initialize INT0 for flow pulse input ----
void INT0_init(void)
{
    MCUCR |= (1 << ISC01);    // Falling edge interrupt
    GICR  |= (1 << INT0);     // Enable INT0
}

// ---- Timer1: 1 second interrupt ----
void Timer1_init_1s(void)
{
    TCCR1B |= (1 << WGM12);          // CTC mode
    OCR1A = 15624;                   // 1 second
    TIMSK |= (1 << OCIE1A);          // Enable interrupt
    TCCR1B |= (1 << CS12) | (1 << CS10);   // Prescaler 1024
}

*/