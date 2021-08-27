#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"



void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);

	MSTK_voidInit();

	GPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);


	 // HSTP_voidSendSynchronus(0b11111111); /* Put high to all STP pins */

	while(1)
	{
		for(int i=0;i<8;i++)
		{
			HSTP_voidSendSynchronus(1<<i);
	        MSTK_voidSetBusyWait(300000);
		}
	}

}
