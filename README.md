# 🚀 Advanced AVR SPI & I2C Drivers

## 📌 Overview
This repository contains **advanced, reusable SPI and I2C (TWI) driver implementations**
for **AVR microcontrollers** using **bare-metal Embedded C**.

The drivers are written following **industry-standard embedded firmware practices** with:
- 🧩 Modular `.c` / `.h` separation
- ⚙️ Configuration structures
- 🧠 Hardware register-level control
- 🔌 Clean, scalable APIs

These drivers are suitable for **academic projects, self-learning, interviews, and real embedded products**.

---

## 🎯 Supported Microcontrollers
- ATmega16
- ATmega32
- ATmega328 / ATmega328P
- ATmega2560
- Other AVR devices with SPI and TWI peripherals

---

## 🧠 Features

### 🔹 SPI (Serial Peripheral Interface)
Provides configurable SPI communication supporting:
- 🔁 Master and Slave modes  
- ⏱️ Multiple clock modes (Mode 0–3)  
- ⚡ Clock prescaler selection  
- 📤 Blocking data transfer APIs  

### 🔹 I2C / TWI (Two-Wire Interface)
Provides reliable I2C communication with:
- ▶️ Start and Repeated Start conditions  
- ✅ ACK / ❌ NACK control  
- 📊 Status-based error handling  
- 🧩 Compatibility with EEPROMs, RTCs, and sensors  

### 🔹 ADC (Analog-to-Digital Converter)
Provides ADC functionality including:
- 🎚️ Multiple channel selection  
- 🔋 Configurable reference voltage  
- ⏳ Polling-based ADC conversion  
- 📐 8-bit / 10-bit resolution support  

### 🔹 Timers
Provides timer services such as:
- ⏲️ Timer0, Timer1, and Timer2 support  
- ⏱️ Delay generation  
- 🌊 PWM signal generation  
- ⚙️ Prescaler configuration  

### 🔹 USART (Serial Communication)
Provides serial communication with:
- 📡 Configurable baud rate  
- 📤 Transmit and 📥 Receive APIs  
- ⛓️ Blocking communication mode  
- 🐞 Support for debugging and logging  

### 🔹 Interrupts
Provides interrupt handling support including:
- ⚡ External interrupts (INT0, INT1, INT2)  
- 🌐 Global interrupt enable / disable  
- 🔄 Callback-based ISR handling  
