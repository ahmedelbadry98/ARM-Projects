/*****************************************************/
/* Author   : Ahmed Elbadry                          */
/* Version  : V01                                    */
/* Date     : 14 SEP 2020                            */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for (Local_s8Counter = 7; Local_s8Counter >=0; Local_s8Counter--)
	{
		/* Send bit by bit strating from MSb */
		Local_u8Bit =  GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		
		GPIO_VoidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);
		
		/* Send Pulse to Shift Clock */
		GPIO_VoidSetPinValue(HSTP_SHIFT_CLOCK,HIGH);
		MSTK_voidSetBusyWait(1);
		GPIO_VoidSetPinValue(HSTP_SHIFT_CLOCK,LOW);
		MSTK_voidSetBusyWait(1);
	}
	
			/* Send Pulse to Shift Clock */
	GPIO_VoidSetPinValue(HSTP_STORE_CLOCK,HIGH);
	MSTK_voidSetBusyWait(1);
	GPIO_VoidSetPinValue(HSTP_STORE_CLOCK,LOW);
	MSTK_voidSetBusyWait(1);
	
}
