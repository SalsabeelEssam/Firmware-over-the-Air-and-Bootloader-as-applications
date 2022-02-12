#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "RCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MUART_Interface.h"
#include "parse.h"
#include "FPES_interface.h"


#define CHECK_READY   0x3F  /*?*/
#define SEND_START    0x7E  /*~*/
#define READY         0x52  /*R*/

void APPSlave_voidEnableClock(void);
void APPSlave_voidInit(void);
void SlaveApp_ReceiveAndParse(void);



typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void CallApp(void) {
#define SCB_VTOR   *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08001800;

	addr_to_call = *(Function_t*) (0x08001804);
	addr_to_call();

}

int main(void)
{
    u8 IM_ready =0;
	APPSlave_voidEnableClock();

	APPSlave_voidInit();
	while( (IM_ready != CHECK_READY) ){
       MUSART1_voidReceive(&IM_ready);

	}
	MUSART1_voidTransmitChar(READY);/*1st ?*/
	FPEC_voidEraseAppArea(6, 64);

	while(1){

		SlaveApp_ReceiveAndParse();
	}
}

void APPSlave_voidEnableClock(void) {
	RCC_voidInitSysClock();
	RCC_voidEnableClock(2, 2); /* PORTA*/
	RCC_voidEnableClock(2, 14); /* USRT1*/
	RCC_voidEnableClock(RCC_AHB, 4); /* FLash*/
}
void APPSlave_voidInit(void) {
	/*URt1*/
	MGPIO_VoidSetPinDirection(PORTA, PIN9, OUTPUT_MAX2MHZ_AFOPP); /*TX*/
	MGPIO_VoidSetPinDirection(PORTA, PIN10, INPUT_FLOAT); /*RX*/

	MUSART1_voidInit();
}
void SlaveApp_ReceiveAndParse(void){
	u8 LocalArrRecord[45]={0};
	u8 Local_u8Index=0;
	u8 ReadyToExecute=0;
	ErrorState state = NOK;
	while(1){
		MUSART1_voidReceive(LocalArrRecord+Local_u8Index);
		if(LocalArrRecord[Local_u8Index] == '\n')
			break;
		Local_u8Index ++;
	}
	Local_u8Index =0;
	state = Parser_vidParseRecord(LocalArrRecord);
	if(state == OK){
		MUSART1_voidTransmitChar(READY);
	}
	else if(state == END_OF_FILE){
		MUSART1_voidTransmitChar(CHECK_READY);
		while(ReadyToExecute != SEND_START){
	       MUSART1_voidReceive(&ReadyToExecute);
		}
		CallApp();
	}

}
