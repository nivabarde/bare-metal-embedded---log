#include "stm32f4xx.h"
#include "adc.h"

#define ADC1EN (1U<<8)
#define GPIOAEN (1U<<0)
#define ADC_CH1 (1U<<0)
#define ADC_SEQ_LEN1 0x00
#define CR2_ADON (1U<<0)
#define CR2_SWSTART (1U<<30)
#define SR_EOC (1U<<1)
#define CR2_CONT (1U<<1)


void pa1_adc_init(void)
{
	/***CONFIGURE ADC GPIO PIN***/

	// enable clock access to GPIOA
	RCC -> AHB1ENR |= GPIOAEN;

	// set the mode of PA1 to analog
	GPIOA -> MODER |= (1U<<2);
	GPIOA -> MODER |= (1U<<3);

	/***CONFIGURE ADC GPIO MODULE***/

	// enable clock access to ADC
	RCC -> APB2ENR |= ADC1EN;

	// configure the adc parameters

	// conversion sequence start
	ADC1-> SQR3 = ADC_CH1;
	//configure the conversion sequence length
	ADC1 -> SQR1 = ADC_SEQ_LEN1;
	//enable the adc module
	ADC1 -> CR2 |= CR2_ADON;

}

void start_conversion(void)
{
	// Enable continuous conversion
	ADC1 -> CR2 |= CR2_CONT;
	// start adc conversion
	ADC1 -> CR2 |= CR2_SWSTART;

}

uint32_t adc_read(void)
{
// first we have to wait for the conversion to be complete
	while(!(ADC1 -> SR & SR_EOC)){}

// read the converted results
	return (ADC1->DR);
}
