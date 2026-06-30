#include "stm32f4xx.h"

#define GPIOAEN (1U<<0)
#define GPIOCEN (1U<<2)
#define PIN13 (1U<<13)
#define PIN5   (1U<<5)
#define LED_PIN (PIN5)
#define PUSHBTN (PIN13)

int main(void)
{
	RCC->AHB1ENR |= GPIOAEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~ (1U<<11);

	RCC->AHB1ENR |= GPIOCEN;
	GPIOC->MODER &=~ (1U<<26);
	GPIOC->MODER &=~ (1U<<27);
	while(1)
	{
		//Check if btn is pressed//
		if(GPIOC -> IDR & PUSHBTN)
		{
			//TURN ON LED//
		GPIOA -> BSRR = LED_PIN;
		}
		else {
			//TURN OFF LED
		GPIOA -> BSRR = (1U<<21) ;
		}

	}
}
