#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_



#if MUSART1_SELCTION_TO_DO  ==     ENABLE
	void MUSART1_voidInit(void);
	void MUSART1_voidTransmit(u8 *Copy_Data, u8 Copy_Size);
	void MUSART1_voidTransmitString(u8 *Copy_Data);
	void MUSART1_voidReceive(u8 *Copy_DataReturn);
	void MUSART1_voidTransmitChar(u8 Copy_Data);
	void MUSART1_VoidClearReceiver(void);

	void MUSART1_VoidReceiveInterrptData(u8* Copy_Data);
	void MUSART1_SetCallBack(void (*ptr)(void));
#endif

#if MUSART2_SELCTION_TO_DO  ==     ENABLE
	void MUSART2_voidInit(void);
	void MUSART2_voidTransmit(u8 *Copy_Data, u8 Copy_Size);
	void MUSART2_voidTransmitString(u8 *Copy_Data);
	void MUSART2_voidReceive(u8 *Copy_DataReturn);
	void MUSART2_voidTransmitChar(u8 Copy_Data);
	void MUSART2_VoidClearReceiver(void);

	void MUSART2_VoidReceiveInterrptData(u8* Copy_Data);
	void MUSART2_SetCallBack(void (*ptr)(void));
#endif

#if MUSART3_SELCTION_TO_DO  ==     ENABLE
	void MUSART3_voidInit(void);
	void MUSART3_voidTransmit(u8 *Copy_Data, u8 Copy_Size);
	void MUSART3_voidTransmitString(u8 *Copy_Data);
	void MUSART3_voidReceive(u8 *Copy_DataReturn);
	void MUSART3_voidTransmitChar(u8 Copy_Data);
	void MUSART3_VoidClearReceiver(void);

	void MUSART3_VoidReceiveInterrptData(u8* Copy_Data);
	void MUSART3_SetCallBack(void (*ptr)(void));
#endif


#if MUART4_SELCTION_TO_DO  ==     ENABLE
	void MUART4_voidInit(void);
	void MUART4_voidTransmit(u8 *Copy_Data, u8 Copy_Size);
	void MUART4_voidTransmitString(u8 *Copy_Data);
	void MUART4_voidReceive(u8 *Copy_DataReturn);
	void MUART4_voidTransmitChar(u8 Copy_Data);
	void MUART4_VoidClearReceiver(void);

	void MUART4_VoidReceiveInterrptData(u8* Copy_Data);
	void MUART4_SetCallBack(void (*ptr)(void));
#endif

#if MUART5_SELCTION_TO_DO  ==     ENABLE
	void MUART5_voidInit(void);
	void MUART5_voidTransmit(u8 *Copy_Data, u8 Copy_Size);
	void MUART5_voidTransmitString(u8 *Copy_Data);
	void MUART5_voidReceive(u8 *Copy_DataReturn);
	void MUART5_voidTransmitChar(u8 Copy_Data);
	void MUART5_VoidClearReceiver(void);

	void MUART5_VoidReceiveInterrptData(u8* Copy_Data);
	void MUART5_SetCallBack(void (*ptr)(void));
#endif

#endif
