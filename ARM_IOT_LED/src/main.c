#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"
#include "NVIC_interface.h"

#include "ESP_interface.h"

extern u8 volatile DataCome[200] ;

int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 14);		/* Enable USART1 Clock */
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);

	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz */
	 GPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_2MHZ_AFPP);
	/* Setting A10:RX pin as input floating */
	 GPIO_VoidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	 GPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	 GPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	 GPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);


	MUSART_VidInit();

	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt  (37); // Enable  UART interrupt


	ESP8266_VidInit();
	ESP8266_VidConnectToWiFi( (u8 *)"WEB52EB2" , (u8 *)"kb552946" );



	u8 LOC_u8Data ;
	while(1)
	{
		ESP8266_VidConnectToSrvTcp( (u8 *)"162.253.155.226" , (u8 *)"80" );
		LOC_u8Data = ESP8266_u8ReceiveHttpReq( (u8 *)"ahmed98x.freevar.com" , (u8 *)"51" );

		switch(LOC_u8Data)
		{
		case '1':GPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);break;
		case '2':GPIO_VoidSetPinValue(GPIOA,PIN0,LOW);break;
		case '3':GPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);break;
		case '4':GPIO_VoidSetPinValue(GPIOA,PIN1,LOW);break;
		case '5':GPIO_VoidSetPinValue(GPIOA,PIN2,HIGH);break;
		case '6':GPIO_VoidSetPinValue(GPIOA,PIN2,LOW);break;
		}


	}



}
