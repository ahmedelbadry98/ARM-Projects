#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "sev_seg_interface.h"


void simple_delay(){
u16 w=500;
	for(u16 i=0;i<w;i++)
	{
		for(u16 j=0;j<w;j++){ asm("NOP"); }
	}
}

void main(void){


RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);


GPIO_VidSetPinDirection(GPIOA, PIN0 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOA, PIN1 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOA, PIN2 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOA, PIN3 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOA, PIN4 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOA, PIN5 , OUTPUT_SPEED_10MHZ_PP);
GPIO_VidSetPinDirection(GPIOA, PIN6 , OUTPUT_SPEED_10MHZ_PP);




u16 DelayCounter=500;
	while(1)
	{

		SEV_SEG_Display(CommonAnode , ZERO);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}} // simple delay loop
		SEV_SEG_Display(CommonAnode , ONE);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}}
		SEV_SEG_Display(CommonAnode , TWO);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}}
		SEV_SEG_Display(CommonAnode , THREE);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}}
		SEV_SEG_Display(CommonAnode , FOUR);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}}
		SEV_SEG_Display(CommonAnode , FIVE);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}}
		SEV_SEG_Display(CommonAnode , SIX);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}}
		SEV_SEG_Display(CommonAnode , SEVEN);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}}
		SEV_SEG_Display(CommonAnode , EIGHT);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}}
		SEV_SEG_Display(CommonAnode , NINE);
		for(u16 i=0;i<DelayCounter;i++){for(u16 j=0;j<DelayCounter;j++){asm("NOP");}}



	}


}
