/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <stdint.h>

void UART_init(uint32_t baud);// Initialize UART with given baud rate
void USART_Transmit(char data);// Transmit a single character
void USART_SendString(char *str);// Send a string through UART
char USART_Receive(void);// Receive a single character (blocking)
uint8_t UART_available(void);// Check if data is available (non-blocking)
char UART_read(void);// Read received character (non-blocking)

#endif
//#ifndef --> #define --> #endif ensures your header file is only included once to avoid errors.

/*
example main code 1:

int main(void)
{
    char c;

    UART_init(9600);                      // Initialize UART
    USART_SendString("UART Ready!\r\n"); // Send welcome message

    while (1)
    {
        // Check if a byte is received
        if (UART_available())        
        {
            c = UART_read();          // Read the byte
            USART_Transmit(c);        // Echo it back
        }
    }
}

example main code 1:
#define F_CPU 16000000UL
#include <avr/io.h>
#include <string.h>
#include "uart.h"

#define LED_PIN PC0  // LED connected to PC0

int main(void)
{
    char c;
    char command[20];   // buffer for command
    uint8_t idx = 0;    // index in buffer

    // Set LED pin as output
    DDRC |= (1 << LED_PIN);

    // Initialize UART
    UART_init(9600);

    // Welcome message
    USART_SendString("UART Command Ready!\r\n");

    while (1)
    {
        // Check if a byte has arrived
        if (UART_available())
        {
            c = UART_read();         // Read byte
            USART_Transmit(c);       // Echo back

            // End of command (Enter key)
            if (c == '\r' || c == '\n')
            {
                command[idx] = '\0'; // terminate string

                // Compare command
                if (strcmp(command, "LED ON") == 0)
                {
                    PORTC |= (1 << LED_PIN);  // Turn LED ON
                    USART_SendString("LED TURNED ON\r\n");
                }
                else if (strcmp(command, "LED OFF") == 0)
                {
                    PORTC &= ~(1 << LED_PIN); // Turn LED OFF
                    USART_SendString("LED TURNED OFF\r\n");
                }
                else
                {
                    USART_SendString("Unknown Command\r\n");
                }

                idx = 0;  // reset buffer for next command
            }
            else
            {
                // Store character in buffer
                if (idx < sizeof(command)-1)
                    command[idx++] = c;
            }
        }
    }
}

*/