# IoT LAB EXPERIMENTS

This repository contains the experiments and tasks completed as part of the **Fundamentals of IoT (FIoT) Lab**.

The experiments are performed using 8051 and STM32 microcontrollers, along with different sensors, communication modules and IoT platforms.

Each experiment folder contains:
- `README.md` – Experiment details, working principle, pseudocode and code explanation.
- Source code files.
- `circuit.png` – Circuit diagram.
- Other required files and screenshots, wherever applicable.

---

## 1. 8051 Microcontroller Experiments

Experiments performed using the 8051 microcontroller.

| CAT | Experiment / Task | Link |
|---|---|---|
| CAT 2 | Task 2B | [TASK2B](8051/CAT2/TASK2B/) |
| CAT 3 | Task 3A | [TASK3A](8051/CAT3/TASK3A/) |
| CAT 4 | Task 4A | [TASK4A](8051/CAT4/TASK4A/) |
| CAT 5 | Task 5A | [TASK5A](8051/CAT5/TASK5A/) |
| CAT 5 | Task 5B.1 | [TASK5B.1](8051/CAT5/TASK5B/TASK5B.1/) |
| CAT 5 | Task 5B.2 | [TASK5B.2](8051/CAT5/TASK5B/TASK5B.2/) |
| CAT 5 | Task 5B.3 | [TASK5B.3](8051/CAT5/TASK5B/TASK5B.3/) |
| CAT 5 | Task 5C | [TASK5C](8051/CAT5/TASK5C/) |
| CAT 6 | Task 6A | [TASK6A](8051/CAT6/TASK6A/) |
| CAT 6 | Task 6B | [TASK6B](8051/CAT6/TASK6B/) |
| CAT 7 | Task 7A | [TASK7A](8051/CAT7/TASK7A/) |
| CAT 7 | Task 7B | [TASK7B](8051/CAT7/TASK7B/) |
| CAT 7 | Task 7C | [TASK7C](8051/CAT7/TASK7C/) |

### Common Libraries

[Common Libraries](8051/Common%20Libraries/)

Contains reusable header files and functions used across multiple 8051 experiments.

---

## 2. STM32 Microcontroller Experiments

Experiments performed using STM32 microcontrollers and STM32 HAL libraries.

| CAT | Experiment / Task | Link |
|---|---|---|
| CAT 8 | STM32 Experiments | [CAT8](STM32/CAT8/) |
| CAT 9 | STM32 Experiments | [CAT9](STM32/CAT9/) |
| CAT 10 | ESP Module Communication | [CAT10](STM32/CAT10/) |
| CAT 11 | Task 11A – TCP Server Configuration | [TASK11A](STM32/CAT11/TASK11A/) |
| CAT 11 | Task 11B – HTTP Webpage Hosting | [TASK11B](STM32/CAT11/TASK11B/) |
| CAT 12 | Task 12A – LED Blinking | [TASK12A](STM32/CAT12/TASK12A/) |
| CAT 12 | Task 12B – Push Button Controlled LED | [TASK12B](STM32/CAT12/TASK12B/) |
| CAT 12 | Task 12C – Short and Long Press LED Control | [TASK12C](STM32/CAT12/TASK12C/) |
| CAT 13 | BME280 Sensor Data Transmission using MQTT | [CAT13](STM32/CAT13/) |
| CAT 14 | BME280 Sensor Data Transmission using MQTT | [CAT14](STM32/CAT14/) |
| CAT 15 | Project – Complete IoT Flow | [CAT15](STM32/CAT15/) |

---

## 3. Technologies and Components Used

### Microcontrollers
- 8051 Microcontroller
- STM32 Microcontroller

### Sensors and Modules
- BME280 Sensor
- ESP8266 Wi-Fi Module
- LCD Display
- Keypad
- Seven Segment Display
- LEDs and Push Buttons
- Stepper Motor

### Communication Protocols
- UART
- I2C
- TCP/IP
- HTTP
- MQTT

### Software and Platforms
- Keil µVision
- STM32CubeIDE
- Node-RED
- MQTT Broker
- Git and GitHub

---

## 4. Repository Structure

```text
25011102103_FIoT_LAB/
│
├── 8051/
│   ├── CAT2/
│   │   └── TASK2B/
│   ├── CAT3/
│   │   └── TASK3A/
│   ├── CAT4/
│   │   └── TASK4A/
│   ├── CAT5/
│   │   ├── TASK5A/
│   │   ├── TASK5B/
│   │   │   ├── TASK5B.1/
│   │   │   ├── TASK5B.2/
│   │   │   └── TASK5B.3/
│   │   └── TASK5C/
│   ├── CAT6/
│   │   ├── TASK6A/
│   │   └── TASK6B/
│   ├── CAT7/
│   │   ├── TASK7A/
│   │   ├── TASK7B/
│   │   └── TASK7C/
│   └── Common Libraries/
│
├── STM32/
│   ├── CAT8/
│   ├── CAT9/
│   ├── CAT10/
│   ├── CAT11/
│   │   ├── TASK11A/
│   │   └── TASK11B/
│   ├── CAT12/
│   │   ├── TASK12A/
│   │   ├── TASK12B/
│   │   └── TASK12C/
│   ├── CAT13/
│   ├── CAT14/
│   └── CAT15/
│
└── README.md
```

---

**Note:** Each experiment has its own README file with the corresponding circuit diagram and implementation details.