# I2C LCD Driver for LPC2148

This project provides C source code to interface a 16x2 LCD using I2C protocol in 4-bit mode with the LPC2148 ARM7 microcontroller. The LCD is connected via a PCF8574 I2C I/O expander, minimizing the number of GPIO pins required.

## 📌 Features

- LCD initialization using I2C
- 4-bit data communication
- Send commands and data to LCD
- Display strings and characters
- Works with PCF8574 or similar I2C expanders

## 🧠 Requirements

- LPC2148 Microcontroller
- PCF8574 I2C LCD Backpack
- 16x2 LCD display
- Keil uVision / MPLAB / any suitable IDE
- I2C driver functions: `i2c_start()`, `i2c_write()`, `i2c_stop()`

## 🛠 Functions

- `LCD_Init(unsigned char I2C_Add)` - Initializes the LCD with given I2C address
- `LCD_CMD(unsigned char CMD)` - Sends command to LCD
- `LCD_Write_Char(char Data)` - Displays a single character
- `LCD_Write_String(char* Str)` - Displays a string
- `LCD_start(unsigned int Data)` - Sends data over I2C
- `LCD_Write_4Bit(unsigned char Nibble)` - Sends 4-bit data

## 🔌 Connections

| LCD Pin | PCF8574 Pin | Description        |
|---------|-------------|--------------------|
| RS      | P0          | Register Select    |
| RW      | GND         | Write mode only    |
| E       | P2          | Enable             |
| D4-D7   | P4-P7       | Data lines         |
| VCC     | VCC         | +5V                |
| GND     | GND         | Ground             |
| SDA/SCL | MCU Pins    | I2C Lines (P0.2/P0.3 for LPC2148) |

## 🚀 Getting Started

1. Clone this repo:
   ```bash
   git clone https://github.com/Sanketmail3716/I2C-LCD-LPC2148.git
