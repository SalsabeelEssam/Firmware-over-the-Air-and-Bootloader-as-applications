#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_
	typedef struct
	{
		u32  CRL ;
		u32  CRH ;
		u32  IDR ;
		u32  ODR ;
		u32  BSRR ;
		u32  BRR ;
		u32  LCKR ;

	}GPIO_TYPE;
	
	
	#define  GPIOA_PTR_REGS   ((volatile GPIO_TYPE*)0x40010800)
	#define  GPIOB_PTR_REGS   ((volatile GPIO_TYPE*)0x40010C00)
	#define  GPIOC_PTR_REGS   ((volatile GPIO_TYPE*)0x40011000)
	#define  GPIOD_PTR_REGS   ((volatile GPIO_TYPE*)0x40011400)
	#define  GPIOE_PTR_REGS   ((volatile GPIO_TYPE*)0x40011800)
	#define  GPIOF_PTR_REGS   ((volatile GPIO_TYPE*)0x40011C00)
	#define  GPIOG_PTR_REGS   ((volatile GPIO_TYPE*)0x40012000)
	
	typedef struct
	{
		u32  EVCR   ;
		u32  MAPR   ;
		u32  EXTICR[4];
		u32  MAPR2  ;

	}AFIO_TYPE;
	#define  ADIO_PTR_REGS   ((volatile AFIO_TYPE*)0x40010000)
	
	#define BIT_SET    1
	#define BIT_RESET  0
	
	
#endif


