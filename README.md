# STM32 LED Control with External Interrupts and SysTick Timing

## Overview
This project demonstrates how to control multiple LEDs on an STM32L476 microcontroller using:
- **External interrupts (EXTI)** for push-button inputs.
- **SysTick** for precise millisecond timing.
- **Custom system clock configuration**.

It is designed as a bare-metal, register-level implementation without relying on the STM32 HAL for GPIO, EXTI, or SysTick configuration.

## Hardware
- **MCU**: STM32L476 (Nucleo-L476RG board)
- **LEDs**:
  - PA5 (LED1)
  - PA6 (LED2)
  - PA7 (LED3)
  - PB6 (LED4)
- **Push Buttons**:
  - PA1 → Increase blink delay
  - PA4 → Cycle through active LED
  - PB0 → Reset blink delay to 500 ms

## Features
1. **Adjustable Blink Delay**
   - Button on PA1 increases the LED blink delay by 500 ms.
   - Wraps back to 500 ms after exceeding 2000 ms.

2. **Active LED Selection**
   - Button on PA4 cycles through LEDs 1 → 4.
   - Uses SysTick-based software debounce for stable input.

3. **Delay Reset**
   - Button on PB0 resets the blink delay to 500 ms.

4. **SysTick Timing**
   - Configured to generate an interrupt every 1 ms.
   - Provides a precise time base for delays and debouncing.

5. **Custom System Clock**
   - Configured via `sysclock.c` (provided by professor).
   - Runs at 80 MHz.


## How It Works
1. **GPIO Initialization**  
   Configures LED pins as high-speed push-pull outputs.  
   Configures button pins as inputs.

2. **EXTI Setup**  
   Maps EXTI lines to the correct ports/pins.  
   Configures falling-edge detection for buttons.  
   Enables NVIC interrupts for EXTI lines 0, 1, and 4.

3. **SysTick Setup**  
   Configured for a 1 ms tick at 80 MHz.  
   Increments a global `msTicks` counter used for delays and debouncing.

4. **Main Loop**  
   - Waits for the current `delay_time` in ms.  
   - Toggles the currently active LED.

## Usage
- Press **PA1** to increase the blink delay.
- Press **PA4** to switch to the next LED.
- Press **PB0** to reset the delay to 500 ms.

## Notes
- This repository contains only the custom source (`Src/`) and header (`Inc/`) files for review purposes.
- CubeMX-generated HAL/CMSIS driver files have been omitted.
- Written for educational purposes to demonstrate register-level STM32 programming.
