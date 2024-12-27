# Arithmetic Operations Game

This repository contains the source code for an **Arduino-based** device that helps 
kids learn and practice fundamental arithmetic operations (addition, subtraction, multiplication, and division).

## Demo

[![Video demo](https://img.youtube.com/vi/YfFxL7r7WMo/0.jpg)](https://www.youtube.com/watch?v=YfFxL7r7WMo)

https://www.youtube.com/watch?v=YfFxL7r7WMo


## Adjusting the difficulty

The difficulty can be adjusted in each one of the "Operation" classes:

| Operation                            | Current                    |
|--------------------------------------|----------------------------|
| [Addition](Addition.cpp)             | (0 to 10) + (0 to 10)      |
| [Subtraction](Subtraction.cpp)       | (1 to 10) - (0 to minuend) |
| [Multiplication](Multiplication.cpp) | (1 to 2) * (0 to 10)       |
| [Division](Division.cpp)             | (0 to 20) / (2 to 9)       |

## Hardware required

- Arduino Uno board or compatible
- 16x2 LCD Screen (compatible with Hitachi HD44780 driver)
- 10k ohm potentiometer
- 220 ohm resistor
- 4x4 matrix keypad

## Arduino Libraries

- https://docs.arduino.cc/libraries/liquidcrystal/
- https://docs.arduino.cc/libraries/keyboard/
