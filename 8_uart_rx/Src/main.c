#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

#define GPIOAEN  (1u<<0)
#define GPIOA_5 (1U<<5)

#define LED_PIN  GPIOA_5


// creating a variable to store the value that will be received from the rx
char key;
int main(void)
{
	RCC -> AHB1ENR |= GPIOAEN;  // ENABLING THE CLOCK ACCESS
	GPIOA -> MODER |= (1U<<10); // SETTING PA5 TO OUTPUT PIN
	GPIOA -> MODER &=~ (1U<<11);
	uart2_rxtx_init();
	while(1)
	{
		key = uart2_read();
		if(key == '1')
		{
			GPIOA -> ODR |= LED_PIN;
		}
		else {

			GPIOA -> ODR &=~ LED_PIN;
		}

	}
}





