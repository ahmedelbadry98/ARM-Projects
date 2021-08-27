#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"



void EXTI0_IRQHandler(void)
{
MNVIC_voidSetPendingFlag(7); //Fire EXTI1 interrupt
GPIO_VidSetPinValue(GPIOA,PIN0,HIGH);

}

void EXTI1_IRQHandler(void)
{
	GPIO_VidSetPinValue(GPIOA,PIN1,HIGH);
}



void main(void){

	/* Initialize clocks  */
RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);

GPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
GPIO_VidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);


/* Initialize NVIC */
MNVIC_voidInit();


MNVIC_voidSetPriority(6,0b01000000);  // EXTI0 is in Group1 , sub 0
MNVIC_voidSetPriority(7,0b00110000);  // EXTI1 is in Group0 , sub 3

/* Enable EXTI interrupt from NVIC */
MNVIC_voidEnableInterrupt(6);  // EXTI0
MNVIC_voidEnableInterrupt(7);  // EXTI1

MNVIC_voidSetPendingFlag(6); //Fire EXTI0 interrupt


while(1)
{

}



}
