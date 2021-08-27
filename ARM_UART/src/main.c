#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"

int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
	RCC_voidEnableClock(RCC_APB2, 14);		/* Enable USART1 Clock */

	GPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP); /* A9:TX -> max speed 50 MHz */


	GPIO_VoidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING); /* A10:RX -> input floating */

	GPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);

	MUSART1_voidInit();

	u8 x;

	while(1)
	{
		MUSART1_voidTransmit("97");
		x = MUSART1_u8Receive();
		if(x == '5')
		{
			GPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
		}
		if(x == 'r')
		{
			GPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
		}
	}

	return 0;
}
