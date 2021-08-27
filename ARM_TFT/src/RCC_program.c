/*********************************************************************************/
/* Author    : Ahmed Elbadry                                                      */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


// by default system is using internal RCC(8 MHZ) clock
void RCC_voidInitSysClock(void)
{
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
		RCC_CFGR = 0x00000001;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /* Enable HSE with bypass */
		RCC_CFGR = 0x00000001;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		RCC_CFGR = 0x00000000;
	
	#elif   RCC_CLOCK_TYPE == RCC_PLL

		// PLL MUL value is determined before enabling PLL as per data_sheet

		#if RCC_PLL_MUL_VALUE == 2
		   RCC_CFGR |= ((PLL_MUL_VAL_2)<<18);
		#elif RCC_PLL_MUL_VALUE == 3
		   RCC_CFGR |= ((PLL_MUL_VAL_3)<<18);
		#elif RCC_PLL_MUL_VALUE == 4
		   RCC_CFGR |= ((PLL_MUL_VAL_4)<<18);
		#elif RCC_PLL_MUL_VALUE == 5
		   RCC_CFGR |= ((PLL_MUL_VAL_5)<<18);
		#elif RCC_PLL_MUL_VALUE == 6
		   RCC_CFGR |= ((PLL_MUL_VAL_6)<<18);
		#elif RCC_PLL_MUL_VALUE == 7
		   RCC_CFGR |= ((PLL_MUL_VAL_7)<<18);
		#elif RCC_PLL_MUL_VALUE == 8
		   RCC_CFGR |= ((PLL_MUL_VAL_8)<<18);
		#elif RCC_PLL_MUL_VALUE == 9
		   RCC_CFGR |= ((PLL_MUL_VAL_9)<<18);
		#elif RCC_PLL_MUL_VALUE == 10
		   RCC_CFGR |= ((PLL_MUL_VAL_10)<<18);
		#elif RCC_PLL_MUL_VALUE == 11
		   RCC_CFGR |= ((PLL_MUL_VAL_11)<<18);
		#elif RCC_PLL_MUL_VALUE == 12
		   RCC_CFGR |= ((PLL_MUL_VAL_12)<<18);
		#elif RCC_PLL_MUL_VALUE == 13
		   RCC_CFGR |= ((PLL_MUL_VAL_13)<<18);
		#elif RCC_PLL_MUL_VALUE == 14
		   RCC_CFGR |= ((PLL_MUL_VAL_14)<<18);
		#elif RCC_PLL_MUL_VALUE == 15
		   RCC_CFGR |= ((PLL_MUL_VAL_15)<<18);
		#elif RCC_PLL_MUL_VALUE == 16
		   RCC_CFGR |= ((PLL_MUL_VAL_16)<<18);
		#endif


		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
		#endif
	
	#else
		#error("You choosed Wrong Clock type")
	#endif
}



void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}

