/*********************************************************************************/
/* Author    : Ahmed Elbadry                                                     */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/*
GPIOA_BASE_ADDRESS  0x40010800
GPIOB_BASE_ADDRESS  0x40010C00
GPIOC_BASE_ADDRESS  0x40011000
*/

        /*       REGISTERS ADDRESSES FOR PORTA        */

#define GPIOA_CRL  *((u32*)0x40010800)   
#define GPIOA_CRH  *((u32*)0x40010804)
#define GPIOA_IDR  *((u32*)0x40010808)
#define GPIOA_ODR  *((u32*)0x4001080C)
#define GPIOA_BSRR *((u32*)0x40010810)   //Bit Set Reset register 1->set , 0-> no change
#define GPIOA_BRR  *((u32*)0x40010814)   //Bit Reset register 1->reset   , 0-> no change
#define GPIOA_LCKR *((u32*)0x40010818)   //lock register : 1-> pin locked (can't change its mode) , 0-> pin not_locked

        /*       REGISTERS ADDRESSES FOR PortB        */

#define GPIOB_CRL  *((u32*)0x40010C00)
#define GPIOB_CRH  *((u32*)0x40010C04)
#define GPIOB_IDR  *((u32*)0x40010C08)
#define GPIOB_ODR  *((u32*)0x40010C0C)
#define GPIOB_BSRR *((u32*)0x40010C10)
#define GPIOB_BRR  *((u32*)0x40010C14)
#define GPIOB_LCKR *((u32*)0x40010C18)

        /*       REGISTERS ADDRESSES FOR PortC        */

#define GPIOC_CRL  *((u32*)0x40011000)
#define GPIOC_CRH  *((u32*)0x40011004)
#define GPIOC_IDR  *((u32*)0x40011008)
#define GPIOC_ODR  *((u32*)0x4001100C)
#define GPIOC_BSRR *((u32*)0x40011010)
#define GPIOC_BRR  *((u32*)0x40011014)
#define GPIOC_LCKR *((u32*)0x40011018)


#endif
