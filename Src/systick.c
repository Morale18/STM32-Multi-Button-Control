#include "stm32l476xx.h"
#include "systick.h"

static volatile uint32_t msTicks = 0;

void SysTick_Init(void)
{
    SysTick->CTRL = 0;
    SysTick->LOAD = 80000000/1000 - 1; // Set to 80Mhz
    SysTick->VAL  = 0;
    NVIC_SetPriority(SysTick_IRQn, 1);
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
}

// This runs when SysTick triggers

void SysTick_Handler(void) {
	msTicks++;
}

void delay(uint32_t t) {
	uint32_t s = msTicks;
	while ((msTicks - s) < t);
}

uint32_t getTicks(void){

	return msTicks;
}
