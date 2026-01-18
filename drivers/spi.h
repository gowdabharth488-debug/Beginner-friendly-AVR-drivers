/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#ifndef SPI_H
#define SPI_H

#include <avr/io.h>
#include <stdint.h>

/* SPI Mode */
typedef enum {
    SPI_MASTER,
    SPI_SLAVE
} SPI_Mode_t;

/* Clock Polarity & Phase */
typedef enum {
    SPI_MODE0,   // CPOL=0, CPHA=0
    SPI_MODE1,   // CPOL=0, CPHA=1
    SPI_MODE2,   // CPOL=1, CPHA=0
    SPI_MODE3    // CPOL=1, CPHA=1
} SPI_ClockMode_t;

/* Clock Prescaler */
typedef enum {
    SPI_CLK_DIV4,
    SPI_CLK_DIV16,
    SPI_CLK_DIV64,
    SPI_CLK_DIV128
} SPI_ClockRate_t;

/* SPI Configuration Structure */
typedef struct {
    SPI_Mode_t mode;
    SPI_ClockMode_t clockMode;
    SPI_ClockRate_t clockRate;
} SPI_Config_t;

/* API */
void SPI_init(const SPI_Config_t *config);
uint8_t SPI_transfer(uint8_t data);
void SPI_enable(void);
void SPI_disable(void);

#endif
