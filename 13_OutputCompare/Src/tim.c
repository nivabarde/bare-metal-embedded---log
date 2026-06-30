#include "stm32f4xx.h"

#define TIM2EN (1U<<0)
#define CR1_CEN (1U<<0)
#define OC_TOGGLE (1U<<4) | (1U<<5)
#define  CC1E (1U<<0)
#define GPIOAEN (1U<<0)
#define AFR5_TIM (1U<<20)


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
void tim2_pa5_output_compare(void)
{
	// ENABLE CLOCK ACCESS TO GPIOA
	RCC ->AHB1ENR |= GPIOAEN;

	//SET PA5 MODE ALTERNATE FUNCTION
	GPIOA -> MODER |= (1U<<11);
	GPIOA ->MODER &=~ (1U<<10);

	//SET PA5 ALTERNATE FUNCTION TYPE TO TIM2_CH1 (AF01)
	GPIOA -> AFR[0] |= AFR5_TIM;

	// enable clock access to timer2
	RCC ->APB1ENR |= TIM2EN;

	//set the prescalar value
	TIM2 ->PSC = 1600 - 1;  // 16 000 000/ 1 600 = 10 000, we subtract 1 because it is counted from 0

	//set the auto-reload value
	TIM2 ->ARR = 10000-1; // 10 000/ 10 000 = 1

	//set output compare toggle mode
	TIM2 ->CCMR1 = OC_TOGGLE;

	//enable tim2 ch1 in compare mode
	TIM2 -> CCER = CC1E;

	//clear the counter
	TIM2 ->CNT = 0;

	//enable the timer
	TIM2 ->CR1 = CR1_CEN;

}
