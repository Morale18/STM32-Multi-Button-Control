
#ifndef SYSTICK_H_
#define SYSTICK_H_
#include <stdint.h>

void SysTick_Init(void);
void delay(uint32_t ms);
uint32_t getTicks(void);



#endif /* SYSTICK_H_ */

