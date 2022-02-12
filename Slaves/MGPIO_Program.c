#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "MGPIO_Private.h"
#include "MGPIO_Interface.h"
#include "MGPIO_Config.h"


void MGPIO_VoidSetPinDirection(u8 Copy_U8PORT,u8 Copy_U8PIN,u8 Copy_U8MODE)
{
	switch (Copy_U8PORT) {
		case PORTA:
			if (Copy_U8PIN < 8) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOA_PTR_REGS->CRL &= ~((0b1111) << (Copy_U8PIN * 4)); //clear bits mode
				GPIOA_PTR_REGS->CRL |= ((Copy_U8MODE) << (Copy_U8PIN * 4)); //write(insert) user input  mode  inside CRL register
			} 
			else if ((Copy_U8PIN>=8) && (Copy_U8PIN<16)) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOA_PTR_REGS->CRH &= ~((0b1111) << ((Copy_U8PIN%8) * 4)); //clear bits mode
				GPIOA_PTR_REGS->CRH |= ((Copy_U8MODE) << ((Copy_U8PIN%8) * 4)); //write(insert) user input  mode  inside CRL register
			}
			else {
				/*error*/
			}
			break;
		case PORTB:
			if (Copy_U8PIN < 8) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOB_PTR_REGS->CRL &= ~((0b1111) << (Copy_U8PIN * 4)); //clear bits mode
				GPIOB_PTR_REGS->CRL |= ((Copy_U8MODE) << (Copy_U8PIN * 4)); //write(insert) user input  mode  inside CRL register
			} 
			else if ((Copy_U8PIN>=8) && (Copy_U8PIN<16)) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOB_PTR_REGS->CRH &= ~((0b1111) << ((Copy_U8PIN%8) * 4)); //clear bits mode
				GPIOB_PTR_REGS->CRH |= ((Copy_U8MODE) << ((Copy_U8PIN%8) * 4)); //write(insert) user input  mode  inside CRL register
			}
			else {
				/*error*/
			}
			break;
		case PORTC:
			if (Copy_U8PIN < 8) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOC_PTR_REGS->CRL &= ~((0b1111) << (Copy_U8PIN * 4)); //clear bits mode
				GPIOC_PTR_REGS->CRL |= ((Copy_U8MODE) << (Copy_U8PIN * 4)); //write(insert) user input  mode  inside CRL register
			} 
			else if ((Copy_U8PIN>=8) && (Copy_U8PIN<16)) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOC_PTR_REGS->CRH &= ~((0b1111) << ((Copy_U8PIN%8) * 4)); //clear bits mode
				GPIOC_PTR_REGS->CRH |= ((Copy_U8MODE) << ((Copy_U8PIN%8) * 4)); //write(insert) user input  mode  inside CRL register
			}
			else {
				/*error*/
			}
			break;
		case PORTD:
			if (Copy_U8PIN < 8) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOD_PTR_REGS->CRL &= ~((0b1111) << (Copy_U8PIN * 4)); //clear bits mode
				GPIOD_PTR_REGS->CRL |= ((Copy_U8MODE) << (Copy_U8PIN * 4)); //write(insert) user input  mode  inside CRL register
			} 
			else if ((Copy_U8PIN>=8) && (Copy_U8PIN<16)) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOD_PTR_REGS->CRH &= ~((0b1111) << ((Copy_U8PIN%8) * 4)); //clear bits mode
				GPIOD_PTR_REGS->CRH |= ((Copy_U8MODE) << ((Copy_U8PIN%8) * 4)); //write(insert) user input  mode  inside CRL register
			}
			else {
				/*error*/
			}
			break;	
		case PORTE:
			if (Copy_U8PIN < 8) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOE_PTR_REGS->CRL &= ~((0b1111) << (Copy_U8PIN * 4)); //clear bits mode
				GPIOE_PTR_REGS->CRL |= ((Copy_U8MODE) << (Copy_U8PIN * 4)); //write(insert) user input  mode  inside CRL register
			} 
			else if ((Copy_U8PIN>=8) && (Copy_U8PIN<16)) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOE_PTR_REGS->CRH &= ~((0b1111) << ((Copy_U8PIN%8) * 4)); //clear bits mode
				GPIOE_PTR_REGS->CRH |= ((Copy_U8MODE) << ((Copy_U8PIN%8) * 4)); //write(insert) user input  mode  inside CRL register
			}
			else {
				/*error*/
			}
			break;	
		case PORTF:
			if (Copy_U8PIN < 8) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOF_PTR_REGS->CRL &= ~((0b1111) << (Copy_U8PIN * 4)); //clear bits mode
				GPIOF_PTR_REGS->CRL |= ((Copy_U8MODE) << (Copy_U8PIN * 4)); //write(insert) user input  mode  inside CRL register
			} 
			else if ((Copy_U8PIN>=8) && (Copy_U8PIN<16)) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOF_PTR_REGS->CRH &= ~((0b1111) << ((Copy_U8PIN%8) * 4)); //clear bits mode
				GPIOF_PTR_REGS->CRH |= ((Copy_U8MODE) << ((Copy_U8PIN%8) * 4)); //write(insert) user input  mode  inside CRL register
			}
			else {
				/*error*/
			}
			break;		
		case PORTG:
			if (Copy_U8PIN < 8) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOG_PTR_REGS->CRL &= ~((0b1111) << (Copy_U8PIN * 4)); //clear bits mode
				GPIOG_PTR_REGS->CRL |= ((Copy_U8MODE) << (Copy_U8PIN * 4)); //write(insert) user input  mode  inside CRL register
			} 
			else if ((Copy_U8PIN>=8) && (Copy_U8PIN<16)) {
				//insert user input mode and config inside CRL register
				//FIRSTLY WE NEED TO RESET
				GPIOG_PTR_REGS->CRH &= ~((0b1111) << ((Copy_U8PIN%8) * 4)); //clear bits mode
				GPIOG_PTR_REGS->CRH |= ((Copy_U8MODE) << ((Copy_U8PIN%8) * 4)); //write(insert) user input  mode  inside CRL register
			}
			else {
				/*error*/
			}
			break;			
		default: /************/
			break;

	}
}

void MGPIO_VoidSetPinValue(u8 Copy_U8PORT,u8 Copy_U8PIN,u8 Copy_U8VALUE)
{
	switch(Copy_U8PORT)
	{
		case PORTA:
			if(PIN_HIGH == Copy_U8VALUE)
			{
				GPIOA_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}
			else if(PIN_LOW == Copy_U8VALUE)
			{
				GPIOA_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			break;
		case PORTB:
			if(PIN_HIGH == Copy_U8VALUE)
			{
				GPIOB_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}
			else if(PIN_LOW == Copy_U8VALUE)
			{
				GPIOB_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			break;
		case PORTC:
			if(PIN_HIGH == Copy_U8VALUE)
			{
				GPIOC_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}
			else if(PIN_LOW == Copy_U8VALUE)
			{
				GPIOC_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			break;
		case PORTD:
			if(PIN_HIGH == Copy_U8VALUE)
			{
				GPIOD_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}
			else if(PIN_LOW == Copy_U8VALUE)
			{
				GPIOD_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			break;
		case PORTE:
			if(PIN_HIGH == Copy_U8VALUE)
			{
				GPIOE_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}
			else if(PIN_LOW == Copy_U8VALUE)
			{
				GPIOE_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			break;
		case PORTF:
			if(PIN_HIGH == Copy_U8VALUE)
			{
				GPIOF_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}
			else if(PIN_LOW == Copy_U8VALUE)
			{
				GPIOF_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			break;
		case PORTG:
			if(PIN_HIGH == Copy_U8VALUE)
			{
				GPIOG_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}
			else if(PIN_LOW == Copy_U8VALUE)
			{
				GPIOG_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			break;
		default: /************/
			break;
	}
}

void MGPIO_U8GetPinValue(u8 Copy_U8PORT,u8 Copy_U8PIN,u8 * Copy_U8Ptr_return)
{
	u8 local_u8pinvalue = 0;
	switch (Copy_U8PORT) {
		case PORTA:
			local_u8pinvalue = (GPIOA_PTR_REGS->IDR & 1<<Copy_U8PIN) != BIT_RESET ? BIT_SET : BIT_RESET;
			break;
		case PORTB:
			local_u8pinvalue = (GPIOB_PTR_REGS->IDR & 1<<Copy_U8PIN) != BIT_RESET ? BIT_SET : BIT_RESET;
			break;
		case PORTC:
			local_u8pinvalue = (GPIOC_PTR_REGS->IDR & 1<<Copy_U8PIN) != BIT_RESET ? BIT_SET : BIT_RESET;
			break;
		case PORTD:
			local_u8pinvalue = (GPIOD_PTR_REGS->IDR & 1<<Copy_U8PIN) != BIT_RESET ? BIT_SET : BIT_RESET;
			break;
		case PORTE:
			local_u8pinvalue = (GPIOE_PTR_REGS->IDR & 1<<Copy_U8PIN) != BIT_RESET ? BIT_SET : BIT_RESET;
			break;
		case PORTF:
			local_u8pinvalue = (GPIOF_PTR_REGS->IDR & 1<<Copy_U8PIN) != BIT_RESET ? BIT_SET : BIT_RESET;
			break;
		case PORTG:
			local_u8pinvalue = (GPIOG_PTR_REGS->IDR & 1<<Copy_U8PIN) != BIT_RESET ? BIT_SET : BIT_RESET;
			break;
		default:
			break;
	}
	 (*Copy_U8Ptr_return)=local_u8pinvalue;

}

void MGPIO_VoidSetPortDirection(u8 Copy_U8PORT,u8 Copy_U8PositionOption,u8 Copy_U8MODE)
{
	u8 u8Counter=0,u8Stop=0;
	if(LOW_BITS == Copy_U8PositionOption)
	{
		u8Counter = 0;
		u8Stop    = 8;
	}	
	else if(HIGH_BITS == Copy_U8PositionOption)
	{
		u8Counter = 8 ;
		u8Stop    = 16;
	}
	else if(ALL_BITS == Copy_U8PositionOption)
	{
		u8Counter = 0 ;
		u8Stop    = 16;
	}
	
	for(;u8Counter<u8Stop;u8Counter++)
	{
		MGPIO_VoidSetPinDirection(Copy_U8PORT,u8Counter,Copy_U8MODE);
	}
}

void MGPIO_VoidSetPortValue(u8 Copy_U8PORT,u8 Copy_U8PositionOption,u16 Copy_U16VALUE)
{
	switch (Copy_U8PORT) {
		case PORTA:
			if(LOW_BITS == Copy_U8PositionOption)
			{
				GPIOA_PTR_REGS->ODR =( GPIOA_PTR_REGS->ODR&0xff00)| Copy_U16VALUE ;
			}	
			else if(HIGH_BITS == Copy_U8PositionOption)
			{
				GPIOA_PTR_REGS->ODR = ( GPIOA_PTR_REGS->ODR&0x00ff)| (Copy_U16VALUE <<8);
			}
			else if(ALL_BITS == Copy_U8PositionOption)
			{
				GPIOA_PTR_REGS->ODR = (u32)Copy_U16VALUE;
			}
			break;
		case PORTB:
			if(LOW_BITS == Copy_U8PositionOption)
			{
				GPIOB_PTR_REGS->ODR =( GPIOB_PTR_REGS->ODR&0xff00)| Copy_U16VALUE ;
			}	
			else if(HIGH_BITS == Copy_U8PositionOption)
			{
				GPIOB_PTR_REGS->ODR = ( GPIOB_PTR_REGS->ODR&0x00ff)| (Copy_U16VALUE <<8);
			}
			else if(ALL_BITS == Copy_U8PositionOption)
			{
				GPIOB_PTR_REGS->ODR = (u32)Copy_U16VALUE;
			}
			break;
		case PORTC:
			if(LOW_BITS == Copy_U8PositionOption)
			{
				GPIOC_PTR_REGS->ODR =( GPIOC_PTR_REGS->ODR  &0xff00)| Copy_U16VALUE ;
			}	
			else if(HIGH_BITS == Copy_U8PositionOption)
			{
				GPIOC_PTR_REGS->ODR = ( GPIOC_PTR_REGS->ODR&0x00ff)| (Copy_U16VALUE <<8);
			}
			else if(ALL_BITS == Copy_U8PositionOption)
			{
				GPIOC_PTR_REGS->ODR = (u32)Copy_U16VALUE;
			}			
			break;
		case PORTD:
			if(LOW_BITS == Copy_U8PositionOption)
			{
				GPIOD_PTR_REGS->ODR =( GPIOD_PTR_REGS->ODR&0xff00)| Copy_U16VALUE ;
			}	
			else if(HIGH_BITS == Copy_U8PositionOption)
			{
				GPIOD_PTR_REGS->ODR = ( GPIOD_PTR_REGS->ODR&0x00ff)| (Copy_U16VALUE <<8);
			}
			else if(ALL_BITS == Copy_U8PositionOption)
			{
				GPIOD_PTR_REGS->ODR = (u32)Copy_U16VALUE;
			}			
			break;
		case PORTE:
			if(LOW_BITS == Copy_U8PositionOption)
			{
				GPIOE_PTR_REGS->ODR =( GPIOE_PTR_REGS->ODR&0xff00)| Copy_U16VALUE ;
			}	
			else if(HIGH_BITS == Copy_U8PositionOption)
			{
				GPIOE_PTR_REGS->ODR = ( GPIOE_PTR_REGS->ODR&0x00ff)| (Copy_U16VALUE <<8);
			}
			else if(ALL_BITS == Copy_U8PositionOption)
			{
				GPIOE_PTR_REGS->ODR = (u32)Copy_U16VALUE;
			}			
			break;
		case PORTF:
			if(LOW_BITS == Copy_U8PositionOption)
			{
				GPIOF_PTR_REGS->ODR =( GPIOF_PTR_REGS->ODR&0xff00)| Copy_U16VALUE ;
			}	
			else if(HIGH_BITS == Copy_U8PositionOption)
			{
				GPIOF_PTR_REGS->ODR = ( GPIOF_PTR_REGS->ODR&0x00ff)| (Copy_U16VALUE <<8);
			}
			else if(ALL_BITS == Copy_U8PositionOption)
			{
				GPIOF_PTR_REGS->ODR = (u32)Copy_U16VALUE;
			}			
			break;
		case PORTG:
			if(LOW_BITS == Copy_U8PositionOption)
			{
				GPIOG_PTR_REGS->ODR =( GPIOG_PTR_REGS->ODR&0xff00)| Copy_U16VALUE ;
			}	
			else if(HIGH_BITS == Copy_U8PositionOption)
			{
				GPIOG_PTR_REGS->ODR = ( GPIOG_PTR_REGS->ODR&0x00ff)| (Copy_U16VALUE <<8);
			}
			else if(ALL_BITS == Copy_U8PositionOption)
			{
				GPIOG_PTR_REGS->ODR = (u32)Copy_U16VALUE;
			}			
			break;
		default:
			break;
	}	
}

void MGPIO_VoidTogglePinValue(u8 Copy_U8PORT,u8 Copy_U8PIN)
{
	switch (Copy_U8PORT) {
		case PORTA:
			TOGGLE_BIT(GPIOA_PTR_REGS->ODR,Copy_U8PIN);
			break;
		case PORTB:
			TOGGLE_BIT(GPIOB_PTR_REGS->ODR,Copy_U8PIN);
			break;
		case PORTC:
			TOGGLE_BIT(GPIOC_PTR_REGS->ODR,Copy_U8PIN);
			break;
		case PORTD:
			TOGGLE_BIT(GPIOD_PTR_REGS->ODR,Copy_U8PIN);
			break;
		case PORTE:
			TOGGLE_BIT(GPIOE_PTR_REGS->ODR,Copy_U8PIN);
			break;
		case PORTF:
			TOGGLE_BIT(GPIOF_PTR_REGS->ODR,Copy_U8PIN);
			break;
		case PORTG:
			TOGGLE_BIT(GPIOG_PTR_REGS->ODR,Copy_U8PIN);
			break;
		default:
			break;
	}
}

void MGPIO_VoidPullUpDownSelect(u8 Copy_U8PORT,u8 Copy_U8PIN,u8 CopyMode)
{
	switch (Copy_U8PORT) {
		case PORTA:
			if(PULL_DOWN == CopyMode)
			{
				GPIOA_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			else if(PULL_UP == CopyMode)
			{
				GPIOA_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}
			break;
		case PORTB:
			if(PULL_DOWN == CopyMode)
			{
				GPIOB_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			else if(PULL_UP == CopyMode)
			{
				GPIOB_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}
			break;
		case PORTC:
			if(PULL_DOWN == CopyMode)
			{
				GPIOC_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			else if(PULL_UP == CopyMode)
			{
				GPIOC_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}				
			break;
		case PORTD:
			if(PULL_DOWN == CopyMode)
			{
				GPIOD_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			else if(PULL_UP == CopyMode)
			{
				GPIOD_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}						
			break;
		case PORTE:
			if(PULL_DOWN == CopyMode)
			{
				GPIOE_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			else if(PULL_UP == CopyMode)
			{
				GPIOE_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}						
			break;
		case PORTF:
			if(PULL_DOWN == CopyMode)
			{
				GPIOF_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			else if(PULL_UP == CopyMode)
			{
				GPIOF_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}						
			break;
		case PORTG:
			if(PULL_DOWN == CopyMode)
			{
				GPIOG_PTR_REGS->BRR = 1<<Copy_U8PIN;
			}
			else if(PULL_UP == CopyMode)
			{
				GPIOG_PTR_REGS->BSRR = 1<<Copy_U8PIN;
			}						
			break;
		default:
			break;
	}
}

void MAFIO_VoidEXTIConfig(u8 Copy_U8PORT,u8 Copy_U8EXTI_ID)
{
	switch (Copy_U8PORT) 
	{
		case PORTA:
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] &=(~(0b1111<<(Copy_U8EXTI_ID%4)*4));
			break;
		case PORTB:
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] &= (~(0b1111<<((Copy_U8EXTI_ID%4)*4)));
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] |= (0b0001<<((Copy_U8EXTI_ID%4)*4));
			break;
		case PORTC:
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] &= (~(0b1111<<((Copy_U8EXTI_ID%4)*4)));
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] |= (0b0010<<((Copy_U8EXTI_ID%4)*4));
			break;
		case PORTD:
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] &= (~(0b1111<<((Copy_U8EXTI_ID%4)*4)));
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] |= (0b0011<<((Copy_U8EXTI_ID%4)*4));
			break;
		case PORTE:
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] &= (~(0b1111<<((Copy_U8EXTI_ID%4)*4)));
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] |= (0b0100<<((Copy_U8EXTI_ID%4)*4));
			break;
		case PORTF:
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] &= (~(0b1111<<((Copy_U8EXTI_ID%4)*4)));
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] |= (0b0101<<((Copy_U8EXTI_ID%4)*4));
			break;
		case PORTG:
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] &= (~(0b1111<<((Copy_U8EXTI_ID%4)*4)));
			ADIO_PTR_REGS->EXTICR[Copy_U8EXTI_ID/4] |= (0b0110<<((Copy_U8EXTI_ID%4)*4));
			break;
		default:
			break;
	}
}
