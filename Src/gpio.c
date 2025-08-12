#include "stm32l476xx.h"
#include "gpio.h"
#include "exti.h"

#define LED_PIN1	5 //PA5
#define LED_PIN2    6 //PA6
#define LED_PIN3    7 //PA7
#define LED_PIN4    6 //PB6

extern volatile uint8_t activeLED;


void init_GPIOs(void)
{
	// Activate clocks on GPIO A and B
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN;

    // Setup all LED pins, i did this to preserve space
    GPIOA->MODER &= ~((3UL<<(2*LED_PIN1))|(3UL<<(2*LED_PIN2))|(3UL<<(2*LED_PIN3)));
    GPIOA->MODER |=  ((1UL<<(2*LED_PIN1))|(1UL<<(2*LED_PIN2))|(1UL<<(2*LED_PIN3)));
    GPIOA->OTYPER &= ~((1UL<<LED_PIN1)|(1UL<<LED_PIN2)|(1UL<<LED_PIN3));
    GPIOA->OSPEEDR |= ((3UL<<(2*LED_PIN1))|(3UL<<(2*LED_PIN2))|(3UL<<(2*LED_PIN3)));

    GPIOB->MODER &= ~(3UL<<(2*LED_PIN4));
    GPIOB->MODER |=  (1UL<<(2*LED_PIN4));
    GPIOB->OTYPER &= ~(1UL<<LED_PIN4);
    GPIOB->OSPEEDR |= (3UL<<(2*LED_PIN4));

    GPIOA->ODR |= (1UL<<LED_PIN1)|(1UL<<LED_PIN2)|(1UL<<LED_PIN3);
    GPIOB->ODR |= (1UL<<LED_PIN4);

}

void toggle_led(void)
{
    switch (activeLED) {
        case 1: GPIOA->ODR ^= (1UL<<LED_PIN1); break;
        case 2: GPIOA->ODR ^= (1UL<<LED_PIN2); break;
        case 3: GPIOA->ODR ^= (1UL<<LED_PIN3); break;
        case 4: GPIOB->ODR ^= (1UL<<LED_PIN4); break;
    }
}



