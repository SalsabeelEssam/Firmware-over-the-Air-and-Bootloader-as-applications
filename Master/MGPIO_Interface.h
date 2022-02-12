#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_
	/*port numbers*/
	typedef enum
	{
		PORTA,PORTB,PORTC,PORTD,PORTE,PORTF,PORTG
	} PORT_N;
	
	/*pin numbers*/
	typedef enum
	{
		PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15
	}PIN_N;

	/*INPUT OUTPUT MODES*/
	typedef enum
	{
		/*INPUT MODES*/
		INPUT_ANALOG = 0x0,
		INPUT_FLOAT  = 0x4,
		INPUT_PULLED = 0x8,

		/*OUTPUT MODES*/
		/*in case 10 MHZ*/
		OUTPUT_MAX10MHZ_GPOPP = 0x1,
		OUTPUT_MAX10MHZ_GPOOD = 0x5,
		OUTPUT_MAX10MHZ_AFOPP = 0x9,
		OUTPUT_MAX10MHZ_AFOOD = 0xD,
		/*in case 2MHZ*/
		OUTPUT_MAX2MHZ_GPOPP  = 0x2,
		OUTPUT_MAX2MHZ_GPOOD  = 0x6,
		OUTPUT_MAX2MHZ_AFOPP  = 0xA,
		OUTPUT_MAX2MHZ_AFOOD  = 0xE,
		/*in case 50MHZ*/
		OUTPUT_MAX50MHZ_GPOPP = 0x3,
		OUTPUT_MAX50MHZ_GPOOD = 0x7,
		OUTPUT_MAX50MHZ_AFOPP = 0xB,
		OUTPUT_MAX50MHZ_AFOOD = 0xF
	} MODES;
	
	typedef enum
	{
		EXTI0,EXTI1,EXTI2,EXTI3,EXTI4,EXTI5,EXTI6,EXTI7,EXTI8,EXTI9,EXTI10,EXTI11,EXTI12,EXTI13,EXTI14,EXTI15
	} EXTI_N;
	
	/**/
	#define PIN_LOW   0
	#define PIN_HIGH  1
	
	#define PULL_DOWN 0
	#define PULL_UP   1
	
	#define LOW_BITS  0
	#define HIGH_BITS 1
	#define ALL_BITS  2
	
	
	
	
	/*FUNCTION PROTOTYPES*/
	void MGPIO_VoidSetPinDirection(u8 Copy_U8PORT,u8 Copy_U8PIN,u8 Copy_U8MODE);
	void MGPIO_VoidSetPinValue(u8 Copy_U8PORT,u8 Copy_U8PIN,u8 Copy_U8VALUE);
    void MGPIO_U8GetPinValue(u8 Copy_U8PORT,u8 Copy_U8PIN,u8 * Copy_U8Ptr_return);
	void MGPIO_VoidSetPortDirection(u8 Copy_U8PORT,u8 Copy_U8PositionOption,u8 Copy_U8MODE);
	void MGPIO_VoidSetPortValue(u8 Copy_U8PORT,u8 Copy_U8PositionOption,u16 Copy_U16VALUE);
	void MGPIO_VoidTogglePinValue(u8 Copy_U8PORT,u8 Copy_U8PIN);
	void MGPIO_VoidPullUpDownSelect(u8 Copy_U8PORT,u8 Copy_U8PIN,u8 CopyMode);
	void MAFIO_VoidEXTIConfig(u8 Copy_U8PORT,u8 Copy_U8EXTI_ID);
#endif
