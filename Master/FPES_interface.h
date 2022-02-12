#ifndef FPES_INTERFACE_H
#define FPES_INTERFACE_H

void FPEC_voidEraseAppArea(u8 Copy_u8Start,u8 Copy_u8End);
	
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber);

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);

#endif