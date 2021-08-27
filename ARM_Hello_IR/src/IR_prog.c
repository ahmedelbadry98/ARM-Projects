/*********************************************************************************/
/* Author    : Ahmed Elbadry                                                     */
/* Version   : V01                                                               */
/* Date      : September 2020                                                    */
/*********************************************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI0_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"
#include "IR_config.h"

volatile u8   u8StartFlag       =0;
volatile u32  u32FrameData[50]  ={0};
volatile u8   u8EdgeCounter     =0;
volatile u8   u8Data            =0;



void VoidTakeAction()
{
	u8Data=0;

	if( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
	   for(u8 i=0;i<8;i++)
	   {
	   	  if( (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <= 2300) ){ SET_BIT(u8Data,i);}
	   	  else{CLR_BIT(u8Data,i);}
	   }
	//voidPlay();
	}

	else
	{
		/* Invalid Frame */
	}


	u8StartFlag       =0;
	u32FrameData[0]   =0;
	u8EdgeCounter     =0;
}




// call back fun
void VoidGetIRFrame(void)
{
if(u8StartFlag == 0)
{
MSTK_voidSetIntervalSingle(1000000,VoidTakeAction);
u8StartFlag =1;
}
else
{
u32FrameData[u8EdgeCounter]=MSTK_u32GetElapsedTime();
MSTK_voidSetIntervalSingle(1000000,VoidTakeAction);
u8EdgeCounter++;
}
}


void IR_VoidInit( void ){


GPIO_VoidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING);

MNVIC_voidEnableInterrupt(6); // Enable EXTI0 

MEXTI_voidSetCallBack(VoidGetIRFrame);// this function will be called when falling age happen

}



u8 IR_u8GetButton ( void ){

	u8 LOC_u8Data = 0 ;

	LOC_u8Data = u8Data ;

	return LOC_u8Data ;
}

