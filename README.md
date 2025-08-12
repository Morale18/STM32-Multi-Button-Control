STM32L476 Real-Time Event-Driven LED Control System
Bare-Metal Firmware with External Interrupts, SysTick Timing, and Custom Debouncing
Overview
This project implements a real-time, event-driven control system on the STM32L476 microcontroller, demonstrating bare-metal firmware development without relying on STM32 HAL drivers.

It uses:

External Interrupts (EXTI) for responsive, non-blocking user input.

SysTick for precise 1 ms system timing.

Custom debouncing for reliable input signal processing.

Direct register access for GPIO, EXTI, and SysTick configuration.

Custom clock initialization for deterministic timing performance.

The system dynamically manages multiple outputs (LEDs) based on low-latency, interrupt-driven events, simulating a simplified real-time scheduler for hardware control.

Hardware
MCU: STM32L476RG (Nucleo-L476RG board)

Outputs (LEDs):

PA5 – LED1

PA6 – LED2

PA7 – LED3

PB6 – LED4

Inputs (Push Buttons via EXTI):

PA1 → Increase blink delay (+500 ms)

PA4 → Cycle active LED (1 → 4)

PB0 → Reset blink delay to 500 ms

Core Features
1. Interrupt-Driven Input Handling
Configures EXTI lines for hardware-level falling-edge detection.

Maps EXTI to GPIO ports via SYSCFG configuration registers.

Uses NVIC priority settings for predictable event latency.

2. SysTick-Based Timing
SysTick configured for a 1 ms tick at 80 MHz.

Global millisecond counter for non-blocking delays and debounce timing.

Timing control ensures stable LED blinking without blocking CPU execution.

3. Custom Input Debouncing
Implements software debounce algorithm using SysTick timestamps.

Ensures signal integrity in mechanical button presses without HAL libraries.

4. Dynamic Output Control
LED Blink Delay: Adjustable in real-time (500 ms → 2000 ms, wraps around).

LED Selection: Cycle through active LED channels with EXTI button press.

Delay Reset: Instant reset to 500 ms via dedicated button.

5. Bare-Metal Register-Level Implementation
No HAL calls for GPIO, EXTI, SysTick — all configured via direct register writes.

Clear separation of low-level drivers from application logic.

Applications
While demonstrated with LEDs, the architecture is adaptable to:

Motor control loops with precise timing.

Multi-sensor event handling.

Power management wake/sleep control.

User interface button panels in industrial systems.

Technical Highlights for Recruiters/Engineers
Direct register-level control of GPIO, EXTI, SysTick.

Real-time, non-blocking event handling with deterministic latency.

Hardware abstraction kept minimal for performance and transparency.

Custom clock configuration for optimal timing resolution.

Scalable design — LED logic can be replaced with actuators, displays, or communication modules without changing core event/timing logic.
