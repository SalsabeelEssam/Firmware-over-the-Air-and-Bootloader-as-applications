
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPES_interface.h"
#include "FPES_private.h"
#include "FPES_config.h"

void FPEC_voidEraseAppArea(u8 Copy_u8Start,u8 Copy_u8End)
{
	u8 Local_u8Counter = Copy_u8Start;
	
	for (;Local_u8Counter < Copy_u8End;Local_u8Counter++)
	{
		FPEC_voidFlashPageErase(Local_u8Counter);
	}
}

void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber)
{
	/* Wait Busy Flag */
	while (GET_BIT(FPES_PTR_REGISTERS->SR,0) == 1);

	/* Check if FPEC is locked or not */
	if ( GET_BIT(FPES_PTR_REGISTERS->CR,7) == 1)
	{
		FPES_PTR_REGISTERS -> KEYR = 0x45670123;
		FPES_PTR_REGISTERS -> KEYR = 0xCDEF89AB;
	}
	
	/* Page Erase Operation */
	SET_BIT(FPES_PTR_REGISTERS->CR,1);

	/* Write Page address */
	FPES_PTR_REGISTERS->AR = (u32)(Copy_u8PageNumber * 1024) + 0x08000000 ;

	/* Start operation */
	SET_BIT(FPES_PTR_REGISTERS->CR,6);

	/* Wait Busy Flag */
	while (GET_BIT(FPES_PTR_REGISTERS->SR,0) == 1);

	/* EOP */
	SET_BIT(FPES_PTR_REGISTERS->SR,5);
	CLR_BIT(FPES_PTR_REGISTERS->CR,1);
}

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length)
{
	u8 i;
	volatile u16 Temp;

	while (GET_BIT(FPES_PTR_REGISTERS->SR,0) == 1);

	/* Check if FPEC is locked or not */
	if (GET_BIT(FPES_PTR_REGISTERS->CR,7) == 1 )
	{
		FPES_PTR_REGISTERS -> KEYR = 0x45670123;
		FPES_PTR_REGISTERS -> KEYR = 0xCDEF89AB;
	}
	
	
	for (i = 0; i< Copy_u8Length; i++)
	{
		/* Write Flash Programming */
		SET_BIT(FPES_PTR_REGISTERS->CR,0);

		/* Half word operation */

		Temp = Copy_u16Data[i];
		*((volatile u16*)Copy_u32Address) = Copy_u16Data[i];
		Copy_u32Address += 2 ;

		/* Wait Busy Flag */
		while (GET_BIT(FPES_PTR_REGISTERS->SR,0) == 1);
	
		/* EOP */
		SET_BIT(FPES_PTR_REGISTERS->SR,5);
		CLR_BIT(FPES_PTR_REGISTERS->CR,0);
	}

}
