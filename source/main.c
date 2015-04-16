#include "stm32f4xx.h"

void led_init(void);

int main(){
	led_init();
	GPIO_SetBits(GPIOA,GPIO_Pin_5);
	while(1){
		
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
