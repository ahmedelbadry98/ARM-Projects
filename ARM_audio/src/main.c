#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "file.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "STK_interface.h"

volatile u16 SignalCounter = 0;


void Void_Set_DAC(void)
{
GPIOA_ODR = song_raw[SignalCounter];
SignalCounter++;
if(SignalCounter == 31858){SignalCounter = 0;}
}

int main(){

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);

	GPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN6,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN8,OUTPUT_SPEED_2MHZ_PP);

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125,Void_Set_DAC); // every 125 micro second


	while(1)
	{

	}



}

