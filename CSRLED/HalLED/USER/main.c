#include "sys.h"
#include "delay.h"
#include "usart.h"

void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
    HAL_Init();                     //初始化HAL库    
    Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz
		delay_init(180);
	
		__HAL_RCC_GPIOB_CLK_ENABLE();		//使能PB时钟
	
		GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;//推挽输出
		GPIO_InitStructure.Pin = GPIO_PIN_0 | GPIO_PIN_1;
		GPIO_InitStructure.Pull = GPIO_PULLUP;		//上拉输出
		GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;		//高速
	
	
		HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);
	while(1)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);	//PB0 = 0;
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);	//PB0 = 1
		delay_ms(500);
		
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);	//PB0 = 0;
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);	//PB0 = 1
		delay_ms(500);
	}

}

