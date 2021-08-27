/**********************************************************/
/* Author    : Ahmed Elbadry                              */
/* Date      : 19 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_ISER0       *((u32*)0xE000E100) /* Enable External interrupts from 0  to 31  */    
#define NVIC_ISER1       *((u32*)0xE000E104) /* Enable External interrupts from 32 to 63  */

#define NVIC_ICER0       *((u32*)0xE000E180) /* Disable external interrupts from 0  to 31 */
#define NVIC_ICER1       *((u32*)0xE000E184) /* Disable external interrupts from 32 to 63 */

#define NVIC_ISPR0       *((u32*)0xE000E200)/* Set pending flag from 0  to 31             */
#define NVIC_ISPR1       *((u32*)0xE000E204)/* Set pending flag from 32 to 63             */

#define NVIC_ICPR0       *((u32*)0xE000E280)/* Clear pending flag from 32 to 63           */
#define NVIC_ICPR1       *((u32*)0xE000E284)/* Clear pending flag from 32 to 63           */

#define NVIC_IABR0       *((volatile u32*)0xE000E300)/* to check active bit register status from  0  to 31 */
#define NVIC_IABR1       *((volatile u32*)0xE000E304)/* to check active bit register status from  32 to 63 */


#define NVIC_IPR          ((u8*)0xE000E400)

#define MNVIC_GROUP_4_SUB_0      0x05FA0300
#define MNVIC_GROUP_3_SUB_1      0x05FA0400
#define MNVIC_GROUP_2_SUB_2      0x05FA0500
#define MNVIC_GROUP_1_SUB_3      0x05FA0600
#define MNVIC_GROUP_0_SUB_4      0x05FA0700

/*  (0xE000ED00) SCB(system control block) Base Address    */

#define SCB_ACTLR                *((volatile u32*)0xE000ED00)
#define SCB_ICSR                 *((volatile u32*)0xE000ED04)
#define SCB_VTOR                 *((volatile u32*)0xE000ED08)
#define SCB_AIRCR                *((volatile u32*)0xE000ED0C)
#define SCB_SCR                  *((volatile u32*)0xE000ED10)   
#define SCB_CCR                  *((volatile u32*)0xE000ED14)



#endif
