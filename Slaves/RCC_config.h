/***************************************************************************************************
 *  File Name        : RCC_config.H
 *  Module           : Rcc  configuration
 *  Description      : to config RCC
 *  Created on       : JUL 5, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* RCC_CLOCK_TYPE options :  
               RCC_HSE_CRYSTAL
			   RCC_HSE_RC
			   RCC_HSI
			   RCC_PLL
*/
#define RCC_CLOCK_TYPE  RCC_HSI

/*  RCC_PLL_INPUT options :
            RCC_PLL_IN_HSI_DIV_2
			RCC_PLL_IN_HSE_DIV_2
			RCC_PLL_IN_HSE
*/
/* select value only if you hve PLL as input Clock Source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT    RCC_PLL_IN_HSE_DIV_2
#endif

/* RCC_PLL_MULTIPLICATION options :  
                PLL_INPUT_CLOCK_2
				PLL_INPUT_CLOCK_3
				PLL_INPUT_CLOCK_4
				PLL_INPUT_CLOCK_5
				PLL_INPUT_CLOCK_6
				PLL_INPUT_CLOCK_7
				PLL_INPUT_CLOCK_8
				PLL_INPUT_CLOCK_9
				PLL_INPUT_CLOCK_10
				PLL_INPUT_CLOCK_11
				PLL_INPUT_CLOCK_12
				PLL_INPUT_CLOCK_13
				PLL_INPUT_CLOCK_14
				PLL_INPUT_CLOCK_15
				PLL_INPUT_CLOCK_16
				PLL_INPUT_CLOCK_16
*/
/* select value only if you hve PLL as input Clock Source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MULTIPLICATION  PLL_INPUT_CLOCK_4 
#endif

#endif
