#include "exti.h"

#define GPIOCEN (1U<<2)
#define SYSCFGEN (1U<<14)
#define EXTI13 (1U<<5)

void pc13_exti_init(void)
{
	//disable global interrupt
	__disable_irq();

	// enable clock access for gpio c
	RCC -> AHB1ENR |= GPIOCEN;


	// setting pc13 as the input pin
	GPIOC->MODER &=~ (1U<<26);
	GPIOC->MODER &=~ (1U<<27);


	// enable clock access to syscfg
	RCC -> APB2ENR |= SYSCFGEN;


	//select port c for exti13
	SYSCFG-> EXTICR[3] |= EXTI13;


	// unmask exti13
	EXTI -> IMR |= (1U<<13);


	// select falling edge trigger
	EXTI -> FTSR |= (1U<<13);


	// enable exti line in NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);


	//enable global intrrupt
	__enable_irq();
}
