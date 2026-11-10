EXPERIMENT DETAILS
EXP: CONTINUOUS ASSESMENT 7

DATE: 

NAME OF EXP: 8051 GPIO Interface

HARDWARE SETUP / PLATFORM: AT89S52 development kit (8051 core, 11.0592 MHz crystal)/Keil µVision 5 (C51), progisp + USBasp ISP programmer

TASK 8A GPIO Input/Output
1. Circuit Diagram
The experiment uses the onboard LED of the STM32 Blue Pill development board

Development Board: STM32 Blue Pill
Microcontroller IC: STM32F103C8T6
GPIO Pin: PC13
Peripheral: Onboard LED
Circuit Diagram

2. Core Logic / Pseudocode / Code Base
Working Principle:

The experiment demonstrates GPIO output control using the 

Pseudocode:

Initialize the HAL library.
Configure GPIO pin PC13 as output.
Turn the LED ON.
Introduce a delay.
Turn the LED OFF.
Introduce a delay.
Repeat the process continuously.
Code Base:

The GPIO operations are performed using HAL_GPIO_WritePin() or HAL_GPIO_TogglePin(), with HAL_Delay() used to introduce time intervals.

3. Inference
The onboard LED of the STM32 Blue Pill blinks continuously, demonstrating GPIO configuration and digital output control using STM32 HAL functions.
