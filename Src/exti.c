#include "systick.h"
#include "stm32l476xx.h"
#include "exti.h"
#include "gpio.h"


extern volatile int32_t delay_time;
extern volatile uint8_t activeLED;
volatile uint32_t lastPress2 = 0;


void debouncing(void) {
	for (int i=0;i<200000;i++);
}


void init_EXTI(void){

	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; // Tell EXTI which port the pin belongs to A or B

	// Setup the external interrupt for push button 1 or PA1
	NVIC_EnableIRQ(EXTI1_IRQn); // Allows CPU to respond to that EXTI line's interrupt
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI1; // Route EXTI to correct pin
	EXTI->IMR1 |= EXTI_IMR1_IM1; // Unmask interrupt
	EXTI->FTSR1 |= EXTI_FTSR1_FT1; // Select Trigger type

	// Setup the external interrupt for push button 2 or PA4
	NVIC_EnableIRQ(EXTI4_IRQn);
	SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI4;
	EXTI->IMR1 |= EXTI_IMR1_IM4;
	EXTI->FTSR1 |= EXTI_FTSR1_FT4;

	// Setup the external interrupt for push button 3 or PB0
	NVIC_EnableIRQ(EXTI0_IRQn);
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0; // Clear
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PB; // Set
	EXTI->IMR1 |= EXTI_IMR1_IM0;
	EXTI->FTSR1 |= EXTI_FTSR1_FT0;
}

