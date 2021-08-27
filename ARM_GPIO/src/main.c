#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"


void main(void){

/*          initializing system clock                         */
	RCC_voidInitSysClock();


/*          Enable peripheral clock                           */
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOC);


/*        setting peripheral clock type                       */
GPIO_VidSetPinDirection(GPIOA, PIN0 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOA, PIN1 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOA, PIN2 , OUTPUT_SPEED_10MHZ_PP);

GPIO_VidSetPinDirection(GPIOB, PIN5 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOB, PIN6 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOB, PIN7 , OUTPUT_SPEED_10MHZ_PP);

GPIO_VidSetPinDirection(GPIOC, PIN13 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOC, PIN14 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOC, PIN15 , OUTPUT_SPEED_10MHZ_PP);



/*        setting pin value                      */
GPIO_VidSetPinValue(GPIOA , PIN0 , HIGH);
GPIO_VidSetPinValue(GPIOA , PIN1 , HIGH);
GPIO_VidSetPinValue(GPIOA , PIN2 , HIGH);

GPIO_VidSetPinValue(GPIOB , PIN5 , HIGH);
GPIO_VidSetPinValue(GPIOB , PIN6 , HIGH);
GPIO_VidSetPinValue(GPIOB , PIN7 , HIGH);

GPIO_VidSetPinValue(GPIOC , PIN13 , HIGH);
GPIO_VidSetPinValue(GPIOC , PIN14 , HIGH);
GPIO_VidSetPinValue(GPIOC , PIN15 , HIGH);


	while(1)
	{

	}


}
