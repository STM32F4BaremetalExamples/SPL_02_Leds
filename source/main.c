#include "stm32f4xx.h"

void led_init(void);

int main(){
	led_init();
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	while(1){
		
	}
}

void led_init(void){
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Mode=GPIO_Mode_OUT;
	myGPIO.GPIO_Pin=GPIO_Pin_13;
	GPIO_Init(GPIOC,&myGPIO);
}
