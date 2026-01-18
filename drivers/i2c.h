/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#ifndef I2C_H
#define I2C_H

#include <avr/io.h>
#include <stdint.h>

/* I2C Status Codes */
#define I2C_START_SENT        0x08
#define I2C_REP_START_SENT    0x10
#define I2C_MT_SLA_ACK        0x18
#define I2C_MT_DATA_ACK       0x28
#define I2C_MR_SLA_ACK        0x40
#define I2C_MR_DATA_ACK       0x50
#define I2C_MR_DATA_NACK      0x58

/* API */
void I2C_init(uint32_t sclFreq);
uint8_t I2C_start(uint8_t address);
void I2C_stop(void);
uint8_t I2C_write(uint8_t data);
uint8_t I2C_readACK(void);
uint8_t I2C_readNACK(void);

#endif
