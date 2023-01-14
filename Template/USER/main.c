#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"


int main(void)
{
	uint8_t t=0;
	Stm32_Clock_Init(360,25,2,8);	//????,180Mhz
	delay_init(180);				//???????
	uart_init(90,115200);			//??????115200
	while(1)
	{
		printf("t:%d\r\n",t);
		delay_ms(500);
		t++;
	}
}



