#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"
#include "RCC_interface.h"

#include "TFT_interface.h"

#include "Image.h"

void main(void)
{
   RCC_voidInitSysClock();
   RCC_voidEnableClock(RCC_APB2 , RCC_GPIOA ); /* GPIOA   */
   RCC_voidEnableClock(RCC_APB2 , 12        ); /* SPI_1   */

   GPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP   );  /* connected to (A0 in TFT)   */
   GPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP   );  /* connected to (RST in TFT)  */
   GPIO_VoidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_10MHZ_AFPP);  /* connected to (CLK in TFT)  */
   GPIO_VoidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_10MHZ_AFPP);  /* connected to (MOSI in TFT) */

   MSTK_voidInit();

   MSPI1_voidInit();

   HTFT_voidInitialize();

   HTFT_voidDisplayImage(image);

while(1);


}
