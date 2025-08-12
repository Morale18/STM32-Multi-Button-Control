#include "gpio.h"
#include "exti.h"
#include "systick.h"
#include "SysClock.h"

volatile int32_t delay_time = 500;
volatile uint8_t activeLed = 1;

int main(void)
{
    init_GPIOs();
    System_Clock_Init();
    SysTick_Init();
    init_EXTI();

    while (1) {
        delay(delay_time);
        toggle_led();
    }
}




