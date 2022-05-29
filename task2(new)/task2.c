#include "def_basic.h"

int main(void)
{
	ClockInit();
	USART2_Init();
	GPIO_Init(GPIOB, 2, GPIO_OUTPUT);
	GPIO_Init(GPIOE, 8, GPIO_OUTPUT);
	USART2_TX_String("[Please input the direction(use lowercase):]\n\r");
	while (1)
	{
		char* input = USART2_RX_String();
		if (!strcmp(input, "left")) GPIOB->BSRR = GPIO_BSRR_BS2;       // Left  ON
		else if (!strcmp(input, "right")) GPIOE->BSRR = GPIO_BSRR_BS8; // Right ON
		else if (!strcmp(input, "up")) GPIOB->BSRR = GPIO_BSRR_BR2;    // Left OFF
		else if (!strcmp(input, "down")) GPIOE->BSRR = GPIO_BSRR_BR8;  // Right OFF
		else if (!strcmp(input, "center"))                             // BOTH OFF
		{
			GPIOB->BSRR = GPIO_BSRR_BR2;
			GPIOE->BSRR = GPIO_BSRR_BR8;
		}
	}
}
