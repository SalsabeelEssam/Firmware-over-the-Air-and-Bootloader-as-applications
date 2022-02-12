/***************************************************************************************************
 *  File Name        : RCC_Program.c
 *  Module           : Rcc  program
 *  Description      : public function
 *  Created on       : JUL 5, 2020
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void){
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /*Enable HSE with no bypass*/
		RCC_CFGR = 0x00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /*Enable Hse With by pass*/
		RCC_CFGR = 0x00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /*Enble Hsi*/
		RCC_CFGR = 0x00000000;
	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		#endif
	#else 
		#error("You Chosed Wrong Clock Type")
	#endif
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripherId){
	if (Copy_u8PeripherId <= 31){
		switch(Copy_u8BusId){
			case RCC_AHB  : SET_BIT(RCC_AHBENR  , Copy_u8PeripherId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR , Copy_u8PeripherId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR , Copy_u8PeripherId);   break;
			default       : /* return Error*/                           break;
		}
	}else {
		/* return Error*/
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripherId){
	if (Copy_u8PeripherId <= 31){
		switch(Copy_u8BusId){
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  , Copy_u8PeripherId);   break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR , Copy_u8PeripherId);   break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR , Copy_u8PeripherId);   break;
			default       : /* return Error*/                           break;
		}
	}else {
		/* return Error*/
	}
}
