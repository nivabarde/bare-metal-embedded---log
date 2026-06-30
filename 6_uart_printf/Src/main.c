#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

#define GPIOAEN (1U<<0)
#define UART2EN (1U<<17)
#define CR1_TE (1U<<3)
#define UART_EN (1U<<13)
#define SR_TXE (1U<<7)

#define SYS_FREQ 16000000  // 16 MILLION CYCLES PER SECOND
#define APB1_CLK  SYS_FREQ

#define UART_BAUDRATE  115200

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

void uar2_tx_init(void);
void uart2_write(int ch);

int __io_putchar(int ch)
{
	uart2_write(ch); // redirecting it to uart.
	return ch;
}

int main(void)
{
	uar2_tx_init();
	while(1)
	{
		printf("I love my boyfriend \n\r");
	}
}


void uar2_tx_init(void)
{
/********configure uart gpio pin*******/
// 1. enable clock access to the gpioa
	RCC -> AHB1ENR|= GPIOAEN; // turn on clock to gpio
// 2. set PA2 mode to alternate function mode
	GPIOA -> MODER |= (1U<<5); // telling the gpio that you are now a uart tx gpio no a normal gpio
	GPIOA-> MODER &=~ (1U<<4);
// 3. set PA2 alternate function type to UART_TX (AF07)
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &=~ (1U<<11);
/*******configure uart module****/
// 1. enable clock access to uart2 peripheral
	RCC -> APB1ENR |= UART2EN;
// 2. configure baudrate
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);
// 3. configure the transfer direction
	USART2 -> CR1 = CR1_TE; //enabling the transmitter
// 4. enable the uart module
	USART2 -> CR1 |= UART_EN; //turning the uart on
}

void uart2_write(int ch)
{
// make sure the transmit data register is empty
	while(!(USART2 -> SR & SR_TXE)) {}
// write to transmit data register
	USART2 -> DR = (ch & 0xFF); // this drops one character at a time.
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
USARTx -> BRR = compute_uart_bd(PeriphClk, BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return((PeriphClk+(BaudRate/2))/BaudRate);
}
