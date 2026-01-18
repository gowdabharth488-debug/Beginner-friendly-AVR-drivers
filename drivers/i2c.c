/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#include "i2c.h"

#define F_CPU 16000000UL

static uint8_t I2C_getStatus(void)
{
    return (TWSR & 0xF8);
}

void I2C_init(uint32_t sclFreq)
{
    TWSR = 0x00;   // Prescaler = 1
    TWBR = ((F_CPU / sclFreq) - 16) / 2;
    TWCR = (1 << TWEN);
}

uint8_t I2C_start(uint8_t address)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while(!(TWCR & (1 << TWINT)));

    if(I2C_getStatus() != I2C_START_SENT &&
       I2C_getStatus() != I2C_REP_START_SENT)
        return 0;

    TWDR = address;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while(!(TWCR & (1 << TWINT)));

    if(I2C_getStatus() != I2C_MT_SLA_ACK &&
       I2C_getStatus() != I2C_MR_SLA_ACK)
        return 0;

    return 1;
}

uint8_t I2C_write(uint8_t data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while(!(TWCR & (1 << TWINT)));

    return (I2C_getStatus() == I2C_MT_DATA_ACK);
}

uint8_t I2C_readACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while(!(TWCR & (1 << TWINT)));
    return TWDR;
}

uint8_t I2C_readNACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN);
    while(!(TWCR & (1 << TWINT)));
    return TWDR;
}

void I2C_stop(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}
