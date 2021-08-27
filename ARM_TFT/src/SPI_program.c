/***************************************************************/
/* Author    : Ahmed Elbadry                                   */
/* Version   : V01                                             */
/* Date      : 16 SEP 2020                                     */
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void (*CallBack)(u8);

void MSPI1_voidInit(void)
{
	/* clock polarity = 1 , clock phase = 1 , prescaller = clk/2 , spe -> ENABLED , MSB first  */
	MSPI1->CR1 = 0x0347;
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin */
	GPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	
	/* Send Data */
	MSPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 7) == 1);

 	/* Return to the received data */
	*Copy_DataToReceive = MSPI1 -> DR;
	
	/* Set Salve Select Pin */
	GPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}

