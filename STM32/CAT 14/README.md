EXPERIMENT DETAILS
EXP: CONTINUOUS ASSESMENT 14

DATE: 21/09/2026

NAME OF EXP: STM32 GPIO Bring-Up and Switch-Controlled LED

HARDWARE SETUP / PLATFORM: CubeMX + Keil MDK + STM32 Development Board Blue Pill STM32F103C8T6

TASK 8A GPIO Input/Output
1. Circuit Diagram
The experiment uses the onboard LED of the STM32 Blue Pill development board.

Development Board: STM32 Blue Pill
Microcontroller IC: STM32F103C8T6
GPIO Pin: PC13
Peripheral: Onboard LED
Circuit Diagram

2. Core Logic / Pseudocode / Code Base
Working Principle:

The experiment demonstrates GPIO output control using the STM32 HAL library. The PC13 pin is configured as a digital output to control the onboard LED.

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
