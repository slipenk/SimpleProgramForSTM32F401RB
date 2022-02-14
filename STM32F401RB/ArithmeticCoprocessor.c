#include "defines.h"
#include "stm32f4xx.h"   
#include "stm32f4xx_gpio.h" 
static GPIO_InitTypeDef gpio_c; 
static GPIO_InitTypeDef gpio_b; 
int main(void) {
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  GPIO_StructInit(&gpio_c); 
  gpio_c.GPIO_Pin = GPIO_Pin_7; 
  gpio_c.GPIO_Mode = GPIO_Mode_IN;   
  GPIO_Init(GPIOC, &gpio_c);   
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 
  GPIO_StructInit(&gpio_b); 
  gpio_b.GPIO_Pin = GPIO_Pin_1; 
  gpio_b.GPIO_Mode = GPIO_Mode_OUT;   
  GPIO_Init(GPIOB, &gpio_b);  
  while (1) 
  {
    if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7) == 0) 
    {
       GPIO_SetBits(GPIOB,GPIO_Pin_1);
    }
    else
    {
       GPIO_ResetBits(GPIOB,GPIO_Pin_1);
    }
  }
}
