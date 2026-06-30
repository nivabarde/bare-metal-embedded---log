#include "stm32f4xx.h"

#define TIM2EN (1U<<0)
#define CR1_CEN (1U<<0)


void tim2_1hz_init(void)
{
	// enable clock access to timer2
	RCC ->APB1ENR |= TIM2EN;

	//set the prescalar value
	TIM2 ->PSC = 1600 - 1;  // 16 000 000/ 1 600 = 10 000, we subtract 1 because it is counted from 0

	//set the auto-reload value
	TIM2 ->ARR = 10000-1; // 10 000/ 10 000 = 1

	//clear the counter
	TIM2 ->CNT = 0;

	//enable the timer
	TIM2 ->CR1 = CR1_CEN;

}
