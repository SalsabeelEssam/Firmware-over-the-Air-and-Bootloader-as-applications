#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_

	#define USART1_BASE_ADDRESS  0x40013800   /*APB2*/
    #define USART2_BASE_ADDRESS  0x40004400   /*APB1*/
    #define USART3_BASE_ADDRESS  0x40004800   /*APB1*/
    #define UART4_BASE_ADDRESS   0x40004C00   /*APB1*/
    #define UART5_BASE_ADDRESS   0x40005000   /*APB1*/ /*UART*/
	typedef struct
	{
		 u32 SR;
		 u32 DR;
		 u32 BRR;
		 u32 CR1;
		 u32 CR2;
		 u32 CR3;
		 u32 GTPR;
		
	} USART_REGISTERS;

	#define USART1_ACCESS_REGISTERS   ((volatile USART_REGISTERS *)USART1_BASE_ADDRESS)
    #define USART2_ACCESS_REGISTERS   ((volatile USART_REGISTERS *)USART2_BASE_ADDRESS)
    #define USART3_ACCESS_REGISTERS   ((volatile USART_REGISTERS *)USART3_BASE_ADDRESS)
    #define UART4_ACCESS_REGISTERS    ((volatile USART_REGISTERS *)UART4_BASE_ADDRESS)
    #define UART5_ACCESS_REGISTERS    ((volatile USART_REGISTERS *)UART5_BASE_ADDRESS)
	
	#define DISABLE 0
	#define ENABLE  1
	
#endif
