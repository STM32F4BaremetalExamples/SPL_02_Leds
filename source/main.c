#include "stm32f4xx.h"

void led_init(void);
void button_init(void);

int main(){
	led_init();
	button_init();
	while(1){
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)){
			GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		} else{
			GPIO_SetBits(GPIOA,GPIO_Pin_5);
		}
	}
}

void led_init(void){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Mode=GPIO_Mode_OUT;
	myGPIO.GPIO_Pin=GPIO_Pin_5;
	GPIO_Init(GPIOA,&myGPIO);
}

void button_init(void){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Mode=GPIO_Mode_IN;
	myGPIO.GPIO_Pin=GPIO_Pin_13;
	GPIO_Init(GPIOC,&myGPIO);
}
