#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"


uint32_t sensor_value;
int main(void)
{
	RCC ->AHB1ENR |= GPIOAEN;

	GPIOA -> MODER |= (1U<<10);
	GPIOA ->MODER &=~ (1U<<11);

	uart2_rxtx_init();
	tim2_1hz_init();


	while(1)
	{
		// WAIT FOR UIF
		while(!(TIM2 ->SR & SR_UIF)) {}

		//CLEAR UIF
		TIM2->SR &=~ SR_UIF;


		printf("A second passed! \n\r"	);
		GPIOA -> ODR ^= LED;
	}
}






