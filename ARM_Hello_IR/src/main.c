#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI0_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"






int main()
{
RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);


GPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_10MHZ_PP);  /* RED   */
GPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_10MHZ_PP);  /* GREEN */
GPIO_VoidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_10MHZ_PP);  /* BLUE  */


MEXTI_voidInit(); // A0 -> EXTI0 is enabled on falling age to capture high and low



// Enable EXTI0 from NVIC
MNVIC_voidInit();

/* initialize SYSTIK AHB/8 = 1MHZ     */
MSTK_voidInit();

IR_VoidInit();

u8 u8Button=0;

while(1)
{
	u8Button = IR_u8GetButton();

	 switch(u8Button)
	  {
	  case MUTE_BUTTON: GPIO_VoidSetPinValue(GPIOA,PIN1,HIGH); break;
	  case POWER_BUTTON: GPIO_VoidSetPinValue(GPIOA,PIN1,LOW); break;
	  }

}

}
