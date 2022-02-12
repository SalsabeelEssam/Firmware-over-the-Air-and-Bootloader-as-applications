#ifndef FPES_PRIVATE_H
#define FPES_PRIVATE_H

#define FPES_BASE_ADDRESS  0x40022000

typedef struct{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 RESERVED;
	volatile u32 OBR;
	volatile u32 WRPR;
} FPES_REGISTERS;

#define FPES_PTR_REGISTERS   ((volatile FPES_REGISTERS *)FPES_BASE_ADDRESS)



#endif
