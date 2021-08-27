/*********************************************************************************/
/* Author    : Ahmed Elbadry                                                     */
/* Version   : V01                                                               */
/* Date      : 16 August 2020                                                    */
/*********************************************************************************/
#ifndef    SEV_SEG_PROGRAM_H
#define    SEV_SEG_PROGRAM_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "sev_seg_interface.h"
#include "sev_seg_config.h"
#include "sev_seg_private.h"





static u8 COMM_A_NUMBERS[10]={ COMM_A_ZERO , COMM_A_ONE , COMM_A_TWO , COMM_A_THREE , COMM_A_FOUR , COMM_A_FIVE , COMM_A_SIX , COMM_A_SEVEN , COMM_A_EIGHT , COMM_A_NINE };

static u8 COMM_C_NUMBERS[10]={ COMM_C_ZERO , COMM_C_ONE , COMM_C_TWO , COMM_C_THREE , COMM_C_FOUR , COMM_C_FIVE , COMM_C_SIX , COMM_C_SEVEN , COMM_C_EIGHT , COMM_C_NINE };


SEV_SEG_Display(u8 Copy_U8Common_Type ,u8 Copy_U8Number)
{
	if(Copy_U8Number <= 9 )
	{
	
	    if(Copy_U8Common_Type == CommonAnode)
	    {
	    	GPIOA_ODR &=  0b0000000                    ; // clearing old values
            GPIOA_ODR |=  COMM_A_NUMBERS[Copy_U8Number];		
	    }
	    else if(Copy_U8Common_Type == CommonCathode)
	    {
	    	GPIOA_ODR &=  0b0000000                    ; // clearing old values
            GPIOA_ODR |=  COMM_C_NUMBERS[Copy_U8Number];
	    	
	    }
	
	}
}


#endif
