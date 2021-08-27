/*********************************************************************************/
/* Author    : Ahmed Elbadry                                                     */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// RCC base address : 0x4002 1000

/* Register Definitions */
#define RCC_CR         *((u32*)0x40021000)
#define RCC_CFGR       *((u32*)0x40021004)
#define RCC_CIR        *((u32*)0x40021008)
#define RCC_APB2RSTR   *((u32*)0x4002100C)
#define RCC_APB1RSTR   *((u32*)0x40021010)
#define RCC_AHBENR     *((u32*)0x40021014)
#define RCC_APB2ENR    *((u32*)0x40021018)
#define RCC_APB1ENR    *((u32*)0x4002101C)
#define RCC_BDCR       *((u32*)0x40021020)
#define RCC_CSR        *((u32*)0x40021024)


/* Clock Types */
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2

/* PLL multiplication parameter */

#define PLL_MUL_VAL_2  0b0000     //PLL input clock x 2
#define PLL_MUL_VAL_3  0b0001     //PLL input clock x 3
#define PLL_MUL_VAL_4  0b0010     //PLL input clock x 4
#define PLL_MUL_VAL_5  0b0011     //PLL input clock x 5
#define PLL_MUL_VAL_6  0b0100     //PLL input clock x 6
#define PLL_MUL_VAL_7  0b0101     //PLL input clock x 7
#define PLL_MUL_VAL_8  0b0110     //PLL input clock x 8
#define PLL_MUL_VAL_9  0b0111     //PLL input clock x 9
#define PLL_MUL_VAL_10 0b1000     //PLL input clock x 10
#define PLL_MUL_VAL_11 0b1001     //PLL input clock x 11
#define PLL_MUL_VAL_12 0b1010     //PLL input clock x 12
#define PLL_MUL_VAL_13 0b1011     //PLL input clock x 13
#define PLL_MUL_VAL_14 0b1100     //PLL input clock x 14
#define PLL_MUL_VAL_15 0b1101     //PLL input clock x 15
#define PLL_MUL_VAL_16 0b1110     //PLL input clock x 16

// CLOCK_SECURITY_SYSTEM options
#define  Enable  1
#define  Disable 0


#endif