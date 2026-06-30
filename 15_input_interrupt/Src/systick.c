#include "stm32f4xx.h"

#define SYSTICK_LOAD_VAL  16000 //this is the value of n, here we are creating a delay of 1ms

#define SYST_CSREN (1U<<0)
#define SYST_CSR_CLKSOURCE (1U<<2)
#define SYST_CSR_COUNTFLAG (1U<<16)

void systickDelayMs(int delay)
{
	// CONFIGURE THE SYSTICK

	// reload with number of clocks per millisec
	SysTick ->LOAD = SYSTICK_LOAD_VAL;

	// clear systick current value register
	SysTick ->VAL = 0;

	//enable systick and select internal clk src
	SysTick ->CTRL = (SYST_CSREN | SYST_CSR_CLKSOURCE);

	for(int i=0; i<delay; i++)
	{
		// wait until the countflag is set
		while(!(SysTick -> CTRL & SYST_CSR_COUNTFLAG )){}
	}
	SysTick ->CTRL = 0;

}
