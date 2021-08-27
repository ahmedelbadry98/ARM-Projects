/*********************************************************************************/
/* Author    : Ahmed Elbadry                                                     */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2

#define RCC_GPIOA         2
#define RCC_GPIOB         3
#define RCC_GPIOC         4

//example: RCC_voidInitSysClock();
void RCC_voidInitSysClock(void);

//example RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

//example RCC_voidDisableClock(RCC_APB2,RCC_GPIOA);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif