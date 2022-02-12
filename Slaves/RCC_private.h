/***************************************************************************************************
 *  File Name        : RCC_private.h
 *  Module           : Rcc  Private
 *  Description      : save register and private function
 *  Created on       : JUL 5, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Definistion */

#define  RCC_CR            (*((u32*)0x40021000)) // enable which clock to processor
#define  RCC_CFGR          (*((u32*)0x40021004)) // enable which clock to processor
#define  RCC_CIR           (*((u32*)0x40021008))
#define  RCC_APB2RSTR      (*((u32*)0x4002100C))
#define  RCC_APB1RSTR      (*((u32*)0x40021010))
#define  RCC_AHBENR        (*((u32*)0x40021014)) // enable or disable clock to peripheral in AHB
#define  RCC_APB2ENR       (*((u32*)0x40021018)) // enable or disable clock to peripheral in APB2
#define  RCC_APB1ENR       (*((u32*)0x4002101C)) // enable or disable clock to peripheral in APB1
#define  RCC_BDCR          (*((u32*)0x40021020))
#define  RCC_CSR           (*((u32*)0x40021024))

/* CLOCK TYPES */
#define RCC_HSE_CRYSTAL    0
#define RCC_HSE_RC         1
#define RCC_HSI			   2
#define RCC_PLL            3

/* PLL OPTIONS */
#define RCC_PLL_IN_HSI_DIV_2     0
#define RCC_PLL_IN_HSE_DIV_2     1
#define RCC_PLL_IN_HSE			 2

/* PLL MULTIPILCATION */
#define PLL_INPUT_CLOCK_2			2
#define PLL_INPUT_CLOCK_3			3
#define PLL_INPUT_CLOCK_4			4
#define PLL_INPUT_CLOCK_5			5
#define PLL_INPUT_CLOCK_6			6
#define PLL_INPUT_CLOCK_7			7
#define PLL_INPUT_CLOCK_8			8
#define PLL_INPUT_CLOCK_9			9
#define PLL_INPUT_CLOCK_10			10
#define PLL_INPUT_CLOCK_11			11
#define PLL_INPUT_CLOCK_12			12
#define PLL_INPUT_CLOCK_13			13
#define PLL_INPUT_CLOCK_14			14
#define PLL_INPUT_CLOCK_15			15
#define PLL_INPUT_CLOCK_16			16
#define PLL_INPUT_CLOCK_16			16 
#endif