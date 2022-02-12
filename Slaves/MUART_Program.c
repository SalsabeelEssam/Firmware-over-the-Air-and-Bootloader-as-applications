#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MUART_Interface.h"
#include "MUART_Private.h"
#include "MUART_Config.h"

static void (*MUSART1_PTR_CallBackFunction)(void) = (void*)0;
static void (*MUSART2_PTR_CallBackFunction)(void) = (void*)0;
static void (*MUSART3_PTR_CallBackFunction)(void) = (void*)0;
static void (*MUART4_PTR_CallBackFunction) (void)  = (void*)0;
static void (*MUART5_PTR_CallBackFunction) (void)  = (void*)0;

void MUSART1_voidInit(void) {
#if MUSART1_SELCTION_TO_DO == ENABLE

	SET_BIT(USART1_ACCESS_REGISTERS -> CR1, 13);

#if MUSART1_WORD_LENGTH == 8
	CLR_BIT(USART1_ACCESS_REGISTERS -> CR1, 12);
#elif MUSART1_WORD_LENGTH == 9
	SET_BIT(USART1_ACCESS_REGISTERS -> CR1,12);
#else
#error "Wrong input"
#endif

#if MUSART1_TRANSMITTER == DISABLE
	CLR_BIT(USART1_ACCESS_REGISTERS -> CR1,3);
#elif MUSART1_TRANSMITTER == ENABLE
	SET_BIT(USART1_ACCESS_REGISTERS -> CR1, 3);

#else
#error "Wrong input"
#endif

#if MUSART1_RECEIVER == DISABLE
	CLR_BIT(USART1_ACCESS_REGISTERS -> CR1,2);
#elif MUSART1_RECEIVER == ENABLE
	SET_BIT(USART1_ACCESS_REGISTERS -> CR1, 2);
#else
#error "Wrong input"
#endif

#if MUSART1_ENABLE_INTERRUPT     ==  ENABLE
	//SET_BIT(USART_ACCESS_REGISTERS -> CR1, 7);
	SET_BIT(USART1_ACCESS_REGISTERS -> CR1, 5);
#else
#error "Wrong input"
#endif

#if MUSART1_BAUD_RATE     ==  9600
	USART1_ACCESS_REGISTERS -> BRR = 0x341;
#elif MUSART1_BAUD_RATE     ==  115200
	USART1_ACCESS_REGISTERS->BRR = 0x045;
#else
#error "Wrong input"
#endif
	USART1_ACCESS_REGISTERS->SR = 0;

#elif MUSART1_SELCTION_TO_DO == DISABLE
#else
#error "Wrong input"
#endif

}

void MUSART2_voidInit(void) {
#if MUSART2_SELCTION_TO_DO == ENABLE

	SET_BIT(USART2_ACCESS_REGISTERS -> CR1, 13);

#if MUSART2_WORD_LENGTH == 8
	CLR_BIT(USART2_ACCESS_REGISTERS -> CR1, 12);
#elif MUSART2_WORD_LENGTH == 9
	SET_BIT(USART2_ACCESS_REGISTERS -> CR1,12);
#else
#error "Wrong input"
#endif

#if MUSART2_TRANSMITTER == DISABLE
	CLR_BIT(USART2_ACCESS_REGISTERS -> CR1,3);
#elif MUSART2_TRANSMITTER == ENABLE
	SET_BIT(USART2_ACCESS_REGISTERS -> CR1, 3);

#else
#error "Wrong input"
#endif

#if MUSART2_RECEIVER == DISABLE
	CLR_BIT(USART2_ACCESS_REGISTERS -> CR1,2);
#elif MUSART2_RECEIVER == ENABLE
	SET_BIT(USART2_ACCESS_REGISTERS -> CR1, 2);
#else
#error "Wrong input"
#endif

#if MUSART2_ENABLE_INTERRUPT     ==  ENABLE
	//SET_BIT(USART_ACCESS_REGISTERS -> CR1, 7);
	SET_BIT(USART2_ACCESS_REGISTERS -> CR1, 5);
#else
#error "Wrong input"
#endif

#if MUSART2_BAUD_RATE     ==  9600
	USART2_ACCESS_REGISTERS -> BRR = 0x341;
#elif MUSART2_BAUD_RATE     ==  115200
	USART2_ACCESS_REGISTERS->BRR = 0x045;
#else
#error "Wrong input"
#endif
	USART2_ACCESS_REGISTERS->SR = 0;

#elif MUSART2_SELCTION_TO_DO == DISABLE
#else
#error "Wrong input"
#endif

}

void MUSART3_voidInit(void) {
#if MUSART3_SELCTION_TO_DO == ENABLE

	SET_BIT(USART3_ACCESS_REGISTERS -> CR1, 13);

#if MUSART3_WORD_LENGTH == 8
	CLR_BIT(USART3_ACCESS_REGISTERS -> CR1, 12);
#elif MUSART3_WORD_LENGTH == 9
	SET_BIT(USART3_ACCESS_REGISTERS -> CR1,12);
#else
#error "Wrong input"
#endif

#if MUSART3_TRANSMITTER == DISABLE
	CLR_BIT(USART3_ACCESS_REGISTERS -> CR1,3);
#elif MUSART3_TRANSMITTER == ENABLE
	SET_BIT(USART3_ACCESS_REGISTERS -> CR1, 3);

#else
#error "Wrong input"
#endif

#if MUSART3_RECEIVER == DISABLE
	CLR_BIT(USART3_ACCESS_REGISTERS -> CR1,2);
#elif MUSART3_RECEIVER == ENABLE
	SET_BIT(USART3_ACCESS_REGISTERS -> CR1, 2);
#else
#error "Wrong input"
#endif

#if MUSART3_ENABLE_INTERRUPT     ==  ENABLE
	//SET_BIT(USART_ACCESS_REGISTERS -> CR1, 7);
	SET_BIT(USART3_ACCESS_REGISTERS -> CR1, 5);
#else
#error "Wrong input"
#endif

#if MUSART3_BAUD_RATE     ==  9600
	USART3_ACCESS_REGISTERS -> BRR = 0x341;
#elif MUSART3_BAUD_RATE     ==  115200
	USART3_ACCESS_REGISTERS -> BRR = 0x045;
#else
#error "Wrong input"
#endif
	USART3_ACCESS_REGISTERS->SR = 0;

#elif MUSART3_SELCTION_TO_DO == DISABLE
#else
#error "Wrong input"
#endif

}

void MUART4_voidInit(void) {
#if MUART4_SELCTION_TO_DO == ENABLE

	SET_BIT(UART4_ACCESS_REGISTERS -> CR1, 13);

#if MUART4_WORD_LENGTH == 8
	CLR_BIT(UART4_ACCESS_REGISTERS -> CR1, 12);
#elif MUART4_WORD_LENGTH == 9
	SET_BIT(UART4_ACCESS_REGISTERS -> CR1,12);
#else
#error "Wrong input"
#endif

#if MUART4_TRANSMITTER == DISABLE
	CLR_BIT(UART4_ACCESS_REGISTERS -> CR1,3);
#elif MUART4_TRANSMITTER == ENABLE
	SET_BIT(UART4_ACCESS_REGISTERS -> CR1, 3);

#else
#error "Wrong input"
#endif

#if MUART4_RECEIVER == DISABLE
	CLR_BIT(UART4_ACCESS_REGISTERS -> CR1,2);
#elif MUART4_RECEIVER == ENABLE
	SET_BIT(UART4_ACCESS_REGISTERS -> CR1, 2);
#else
#error "Wrong input"
#endif

#if MUART4_ENABLE_INTERRUPT    ==  ENABLE
	//SET_BIT(USART_ACCESS_REGISTERS -> CR1, 7);
	SET_BIT(UART4_ACCESS_REGISTERS -> CR1, 5);
#else
#error "Wrong input"
#endif

#if MUART4_BAUD_RATE     ==  9600
	UART4_ACCESS_REGISTERS -> BRR = 0x341;
#elif MUART4_BAUD_RATE     ==  115200
	UART4_ACCESS_REGISTERS -> BRR = 0x045;
#else
#error "Wrong input"
#endif
	UART4_ACCESS_REGISTERS -> SR = 0;

#elif MUART4_SELCTION_TO_DO == DISABLE
#else
#error "Wrong input"
#endif

}

void MUART5_voidInit(void) {
#if MUART5_SELCTION_TO_DO == ENABLE

	SET_BIT(UART5_ACCESS_REGISTERS -> CR1, 13);

#if MUART5_WORD_LENGTH == 8
	CLR_BIT(UART5_ACCESS_REGISTERS -> CR1, 12);
#elif MUART5_WORD_LENGTH == 9
	SET_BIT(UART5_ACCESS_REGISTERS -> CR1,12);
#else
#error "Wrong input"
#endif

#if MUART5_TRANSMITTER == DISABLE
	CLR_BIT(UART5_ACCESS_REGISTERS -> CR1,3);
#elif MUART5_TRANSMITTER == ENABLE
	SET_BIT(UART5_ACCESS_REGISTERS -> CR1, 3);

#else
#error "Wrong input"
#endif

#if MUART5_RECEIVER == DISABLE
	CLR_BIT(UART5_ACCESS_REGISTERS -> CR1,2);
#elif MUART5_RECEIVER == ENABLE
	SET_BIT(UART5_ACCESS_REGISTERS -> CR1, 2);
#else
#error "Wrong input"
#endif

#if MUART5_ENABLE_INTERRUPT    ==  ENABLE
	//SET_BIT(USART_ACCESS_REGISTERS -> CR1, 7);
	SET_BIT(UART5_ACCESS_REGISTERS -> CR1, 5);
#else
#error "Wrong input"
#endif

#if MUART5_BAUD_RATE     ==  9600
	UART5_ACCESS_REGISTERS -> BRR = 0x341;
#elif MUART5_BAUD_RATE     ==  115200
	UART5_ACCESS_REGISTERS -> BRR = 0x045;
#else
#error "Wrong input"
#endif
	UART5_ACCESS_REGISTERS -> SR = 0;

#elif MUART5_SELCTION_TO_DO == DISABLE
#else
#error "Wrong input"
#endif

}


#if MUSART1_SELCTION_TO_DO  ==     ENABLE

void MUSART1_voidTransmit(u8 *Copy_Data, u8 Copy_Size) {
	u8 Local_u8Counter = 0;

	for (; Local_u8Counter < Copy_Size; Local_u8Counter++) {
		USART1_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(USART1_ACCESS_REGISTERS->SR, 7))
			;
	}
}

void MUSART1_voidTransmitChar(u8 Copy_Data) {
	USART1_ACCESS_REGISTERS->DR = Copy_Data;
	/*POLLING UNTILE ALL DATA SEND and clear flag*/
	while (!GET_BIT(USART1_ACCESS_REGISTERS->SR, 7))
		;
}

void MUSART1_voidTransmitString(u8 *Copy_Data) {
	u8 Local_u8Counter = 0;

	while (Copy_Data[Local_u8Counter] != '\0') {
		USART1_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter++];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(USART1_ACCESS_REGISTERS->SR, 7))
			;
	}
}

void MUSART1_voidReceive(u8 *Copy_DataReturn) {
	while (!GET_BIT(USART1_ACCESS_REGISTERS->SR, 5))
		;
	*Copy_DataReturn = (u8) USART1_ACCESS_REGISTERS->DR;
}

void MUSART1_VoidClearReceiver(void) {
	u8 LocalDumyData;
	u8 *LocalPtrDumyData = &LocalDumyData;
	if (!GET_BIT(USART1_ACCESS_REGISTERS->SR, 5)) {
		return;
	}
	*LocalPtrDumyData = (u8) USART1_ACCESS_REGISTERS->DR;
	/*CLR_BIT(USART_ACCESS_REGISTERS -> SR, 5)*/
}


#endif


#if MUSART2_SELCTION_TO_DO  ==     ENABLE

void MUSART2_voidTransmit(u8 *Copy_Data, u8 Copy_Size) {
	u8 Local_u8Counter = 0;

	for (; Local_u8Counter < Copy_Size; Local_u8Counter++) {
		USART2_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(USART2_ACCESS_REGISTERS->SR, 7));
	}
}

void MUSART2_voidTransmitChar(u8 Copy_Data) {
	USART2_ACCESS_REGISTERS->DR = Copy_Data;
	/*POLLING UNTILE ALL DATA SEND and clear flag*/
	while (!GET_BIT(USART2_ACCESS_REGISTERS->SR, 7))
		;
}

void MUSART2_voidTransmitString(u8 *Copy_Data) {
	u8 Local_u8Counter = 0;

	while (Copy_Data[Local_u8Counter] != '\0') {
		USART2_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter++];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(USART2_ACCESS_REGISTERS->SR, 7))
			;
	}
}

void MUSART2_voidReceive(u8 *Copy_DataReturn) {
	while (!GET_BIT(USART2_ACCESS_REGISTERS->SR, 5))
		;
	*Copy_DataReturn = (u8) USART2_ACCESS_REGISTERS->DR;
}

void MUSART2_VoidClearReceiver(void) {
	u8 LocalDumyData;
	u8 *LocalPtrDumyData = &LocalDumyData;
	if (!GET_BIT(USART2_ACCESS_REGISTERS->SR, 5)) {
		return;
	}
	*LocalPtrDumyData = (u8) USART2_ACCESS_REGISTERS->DR;
	/*CLR_BIT(USART_ACCESS_REGISTERS -> SR, 5)*/
}

#endif

#if MUSART3_SELCTION_TO_DO  ==     ENABLE

void MUSART3_voidTransmit(u8 *Copy_Data, u8 Copy_Size) {
	u8 Local_u8Counter = 0;

	for (; Local_u8Counter < Copy_Size; Local_u8Counter++) {
		USART3_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(USART3_ACCESS_REGISTERS->SR, 7))
			;
	}
}

void MUSART3_voidTransmitChar(u8 Copy_Data) {
	USART3_ACCESS_REGISTERS->DR = Copy_Data;
	/*POLLING UNTILE ALL DATA SEND and clear flag*/
	while (!GET_BIT(USART3_ACCESS_REGISTERS->SR, 7))
		;
}

void MUSART3_voidTransmitString(u8 *Copy_Data) {
	u8 Local_u8Counter = 0;

	while (Copy_Data[Local_u8Counter] != '\0') {
		USART3_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter++];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(USART3_ACCESS_REGISTERS->SR, 7));
	}
}

void MUSART3_voidReceive(u8 *Copy_DataReturn) {
	while (!GET_BIT(USART3_ACCESS_REGISTERS->SR, 5))
		;
	*Copy_DataReturn = (u8) USART3_ACCESS_REGISTERS->DR;
}

void MUSART3_VoidClearReceiver(void) {
	u8 LocalDumyData;
	u8 *LocalPtrDumyData = &LocalDumyData;
	if (!GET_BIT(USART3_ACCESS_REGISTERS->SR, 5)) {
		return;
	}
	*LocalPtrDumyData = (u8) USART3_ACCESS_REGISTERS->DR;
	/*CLR_BIT(USART_ACCESS_REGISTERS -> SR, 5)*/
}


#endif

#if MUART4_SELCTION_TO_DO  ==     ENABLE

void MUART4_voidTransmit(u8 *Copy_Data, u8 Copy_Size) {
	u8 Local_u8Counter = 0;

	for (; Local_u8Counter < Copy_Size; Local_u8Counter++) {
		UART4_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(UART4_ACCESS_REGISTERS->SR, 7))
			;
	}
}

void MUART4_voidTransmitChar(u8 Copy_Data) {
	UART4_ACCESS_REGISTERS->DR = Copy_Data;
	/*POLLING UNTILE ALL DATA SEND and clear flag*/
	while (!GET_BIT(UART4_ACCESS_REGISTERS->SR, 7))
		;
}

void MUART4_voidTransmitString(u8 *Copy_Data) {
	u8 Local_u8Counter = 0;

	while (Copy_Data[Local_u8Counter] != '\0') {
		UART4_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter++];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(UART4_ACCESS_REGISTERS->SR, 7))
			;
	}
}

void MUART4_voidReceive(u8 *Copy_DataReturn) {
	while (!GET_BIT(UART4_ACCESS_REGISTERS->SR, 5))
		;
	*Copy_DataReturn = (u8) UART4_ACCESS_REGISTERS->DR;
}

void MUART4_VoidClearReceiver(void) {
	u8 LocalDumyData;
	u8 *LocalPtrDumyData = &LocalDumyData;
	if (!GET_BIT(UART4_ACCESS_REGISTERS->SR, 5)) {
		return;
	}
	*LocalPtrDumyData = (u8) UART4_ACCESS_REGISTERS->DR;
	/*CLR_BIT(USART_ACCESS_REGISTERS -> SR, 5)*/
}

#endif

#if MUART5_SELCTION_TO_DO  ==     ENABLE

void MUART5_voidTransmit(u8 *Copy_Data, u8 Copy_Size) {
	u8 Local_u8Counter = 0;

	for (; Local_u8Counter < Copy_Size; Local_u8Counter++) {
		UART5_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(UART5_ACCESS_REGISTERS->SR, 7))
			;
	}
}

void MUART5_voidTransmitChar(u8 Copy_Data) {
	UART5_ACCESS_REGISTERS->DR = Copy_Data;
	/*POLLING UNTILE ALL DATA SEND and clear flag*/
	while (!GET_BIT(UART5_ACCESS_REGISTERS->SR, 7))
		;
}

void MUART5_voidTransmitString(u8 *Copy_Data) {
	u8 Local_u8Counter = 0;

	while (Copy_Data[Local_u8Counter] != '\0') {
		UART5_ACCESS_REGISTERS->DR = Copy_Data[Local_u8Counter++];
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while (!GET_BIT(UART5_ACCESS_REGISTERS->SR, 7))
			;
	}
}

void MUART5_voidReceive(u8 *Copy_DataReturn) {
	while (!GET_BIT(UART5_ACCESS_REGISTERS->SR, 5))
		;
	*Copy_DataReturn = (u8) UART5_ACCESS_REGISTERS->DR;
}

void MUART5_VoidClearReceiver(void) {
	u8 LocalDumyData;
	u8 *LocalPtrDumyData = &LocalDumyData;
	if (!GET_BIT(UART5_ACCESS_REGISTERS->SR, 5)) {
		return;
	}
	*LocalPtrDumyData = (u8) UART5_ACCESS_REGISTERS->DR;
	/*CLR_BIT(USART_ACCESS_REGISTERS -> SR, 5)*/
}

#endif


#if MUSART1_ENABLE_INTERRUPT  ==  ENABLE
void USART1_IRQHandler(void) {
	if (MUSART1_PTR_CallBackFunction != ((void*) 0)) {
		MUSART1_PTR_CallBackFunction();
	}
	USART1_ACCESS_REGISTERS -> SR = 0;
}

void MUSART1_SetCallBack(void (*ptr)(void)) {

	MUSART1_PTR_CallBackFunction = ptr;
}
void MUSART1_VoidReceiveInterrptData(u8* Copy_Data)
{
	*Copy_Data = (u8) USART1_ACCESS_REGISTERS->DR;
}
#endif


#if MUSART2_ENABLE_INTERRUPT  ==  ENABLE
void USART2_IRQHandler(void) {
	if (MUSART2_PTR_CallBackFunction != ((void*) 0)) {
		MUSART2_PTR_CallBackFunction();
	}
	USART2_ACCESS_REGISTERS -> SR = 0;
}

void MUSART2_SetCallBack(void (*ptr)(void)) {

	MUSART2_PTR_CallBackFunction = ptr;
}
void MUSART2_VoidReceiveInterrptData(u8* Copy_Data)
{
	*Copy_Data = (u8) USART2_ACCESS_REGISTERS->DR;
}
#endif

#if MUSART3_ENABLE_INTERRUPT  ==  ENABLE
void USART3_IRQHandler(void) {
	if (MUSART3_PTR_CallBackFunction != ((void*) 0)) {
		MUSART3_PTR_CallBackFunction();
	}
	USART3_ACCESS_REGISTERS -> SR = 0;
}

void MUSART_SetCallBack(void (*ptr)(void)) {

	MUSART3_PTR_CallBackFunction = ptr;
}
void MUSART_VoidReceiveInterrptData(u8* Copy_Data)
{
	*Copy_Data = (u8) USART3_ACCESS_REGISTERS->DR;
}
#endif


#if MUART4_ENABLE_INTERRUPT  ==  ENABLE
void UART4_IRQHandler(void) {
	if (MUART4_PTR_CallBackFunction != ((void*) 0)) {
		MUART4_PTR_CallBackFunction();
	}
	UART4_ACCESS_REGISTERS -> SR = 0;
}

void MUART4_SetCallBack(void (*ptr)(void)) {

	MUART4_PTR_CallBackFunction = ptr;
}
void MUART4_VoidReceiveInterrptData(u8* Copy_Data)
{
	*Copy_Data = (u8) UART4_ACCESS_REGISTERS->DR;
}
#endif


#if MUART4_ENABLE_INTERRUPT  ==  ENABLE
void UART5_IRQHandler(void) {
	if (MUART5_PTR_CallBackFunction != ((void*) 0)) {
		MUART5_PTR_CallBackFunction();
	}
	UART5_ACCESS_REGISTERS -> SR = 0;
}

void MUART5_SetCallBack(void (*ptr)(void)) {

	MUART5_PTR_CallBackFunction = ptr;
}
void MUART5_VoidReceiveInterrptData(u8* Copy_Data)
{
	*Copy_Data = (u8) UART5_ACCESS_REGISTERS->DR;
}
#endif
