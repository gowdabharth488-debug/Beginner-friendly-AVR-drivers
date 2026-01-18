/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#include "spi.h"

void SPI_init(const SPI_Config_t *config)
{
    /* Enable SPI */
    SPCR = (1 << SPE);

    if(config->mode == SPI_MASTER)
    {
        SPCR |= (1 << MSTR);
        DDRB |= (1 << PB5) | (1 << PB7) | (1 << PB4); // SCK, MOSI, SS
        DDRB &= ~(1 << PB6);                          // MISO
    }
    else
    {
        DDRB |= (1 << PB6);   // MISO
    }

    /* Clock Mode */
    switch(config->clockMode)
    {
        case SPI_MODE1: SPCR |= (1 << CPHA); break;
        case SPI_MODE2: SPCR |= (1 << CPOL); break;
        case SPI_MODE3: SPCR |= (1 << CPOL) | (1 << CPHA); break;
        default: break;
    }

    /* Clock Rate */
    SPCR |= (config->clockRate << SPR0);
}

uint8_t SPI_transfer(uint8_t data)
{
    SPDR = data;
    while(!(SPSR & (1 << SPIF)));
    return SPDR;
}

void SPI_enable(void)
{
    SPCR |= (1 << SPE);
}

void SPI_disable(void)
{
    SPCR &= ~(1 << SPE);
}
