#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "RCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MUART_Interface.h"
#include "HESP_interface.h"
#include "FPES_interface.h"

#define CHECK_READY   0x3F   /*?*/
#define SEND_START    0x7E   /*~*/
#define READY         0x52   /*R*/

#define Version_Page_50   0x0800C800

void MasterApp_voidConnectServer(void);
void APP_voidEnableClock(void);
void APP_voidInit(void);
void MasterApp_ReceiveAndTransmite(u8 Copy_u8PlayerNum);
void Busy_delay();
void CheckVersion(void) ;
u8 AsciToHex(u8 Copy_u8Asci);

int main(void) {
	APP_voidEnableClock();
	APP_voidInit();
    /*Connect to WI FI*/
	HESP_voidWifiConnect((u8*) "DESKTOP-0QDCO2G 1447" , (u8*) "i2419[0S");

	while(1){

         CheckVersion();
	}
}
void APP_voidEnableClock(void) {
	RCC_voidInitSysClock();
	RCC_voidEnableClock(2, 2); /* PORTA*/
	RCC_voidEnableClock(2, 3); /* PORTB*/
	RCC_voidEnableClock(2, 14); /* USRT1*/
	RCC_voidEnableClock(1, 17); /* USRT2*/
	RCC_voidEnableClock(1, 18); /* USRT3*/
	RCC_voidEnableClock(RCC_AHB, 4); /* FLash*/

}
void APP_voidInit(void) {

	/*URt1*/
	MGPIO_VoidSetPinDirection(PORTA, PIN9, OUTPUT_MAX2MHZ_AFOPP); /*TX*/
	MGPIO_VoidSetPinDirection(PORTA, PIN10, INPUT_FLOAT); /*RX*/
	/*URt2*/
	MGPIO_VoidSetPinDirection(PORTA, PIN2, OUTPUT_MAX2MHZ_AFOPP); /*TX*/
	MGPIO_VoidSetPinDirection(PORTA, PIN3, INPUT_FLOAT); /*RX*/
	/*URt3*/
	MGPIO_VoidSetPinDirection(PORTB, PIN10, OUTPUT_MAX2MHZ_AFOPP); /*TX*/
	MGPIO_VoidSetPinDirection(PORTB, PIN11, INPUT_FLOAT); /*RX*/
	/*reset PIN */
	MGPIO_VoidSetPinDirection(PORTA, PIN6, OUTPUT_MAX2MHZ_GPOPP);
	MGPIO_VoidSetPinDirection(PORTA, PIN7, OUTPUT_MAX2MHZ_GPOPP);
	/*iNIT */
	MGPIO_VoidSetPinValue(PORTA,PIN6,PIN_HIGH);
	MGPIO_VoidSetPinValue(PORTA,PIN7,PIN_HIGH);
	MUSART2_voidInit();
	MUSART3_voidInit();
	HESP_voidInit();// usart 1 has init in esp

}

void CheckVersion(void)
{
	u32 Local_u32AllVersion = (*(volatile u32*) Version_Page_50);
	u8 Local_u8FlagTOFlash=0;

		u8 *Ptr_u8Version = (void*) 0;
		// 1- read version status from server
		MasterApp_voidConnectServer();
		HESP_u8GetDataFromServer(&Ptr_u8Version);
		// check
		// 800 C800   // page # 50
		//5 2 3 1
		u8 Local_u8VesionHelp1 = (AsciToHex(Ptr_u8Version[4]) << 4) | AsciToHex(Ptr_u8Version[5]);
		if ((u8) Local_u32AllVersion != Local_u8VesionHelp1){
			// read from server then update flash
			MGPIO_VoidSetPinValue(PORTA,PIN6,PIN_LOW);
			Busy_delay();
			MGPIO_VoidSetPinValue(PORTA,PIN6,PIN_HIGH);
			MasterApp_ReceiveAndTransmite(1);
			Local_u8FlagTOFlash=1;
		}
		Busy_delay();/*delay to make synchronous between meastro and slave*/
		MUSART2_voidTransmitChar(SEND_START);

		u8 Local_u8VesionHelp2= (AsciToHex(Ptr_u8Version[11]) << 4) | AsciToHex(Ptr_u8Version[12]);
		if ((u8) (Local_u32AllVersion >> 16) != Local_u8VesionHelp2)
		{
			// read from server then update flash
			MGPIO_VoidSetPinValue(PORTA,PIN7,PIN_LOW);
			Busy_delay();
			MGPIO_VoidSetPinValue(PORTA,PIN7,PIN_HIGH);
			MasterApp_ReceiveAndTransmite(2);
			Local_u8FlagTOFlash=1;
		}


//		Busy_delay();/*delay to make synchronous between meastro and slave*/
//		MUSART2_voidTransmitChar(SEND_START);

		Busy_delay();/*delay to make synchronous between meastro and slave*/
		MUSART3_voidTransmitChar(SEND_START);
		// == do nothing
		if(Local_u8FlagTOFlash == 1){
			/*START*/
			//muart3 >????????????
			FPEC_voidFlashPageErase(50);
			u16 BurnToFlash[2]={(u16)Local_u8VesionHelp1,(u16)Local_u8VesionHelp2};
			FPEC_voidFlashWrite(Version_Page_50,BurnToFlash,2);
			Local_u8FlagTOFlash=0;
		}

      return;
}
void MasterApp_voidConnectServer(void) {

	HESP_voidConnectToServer((u8*) "162.253.155.226", (u8*) "80");
	HESP_voidSetLengthOFRequest((u8*) "51");
	HESP_voidHttpRequest(
			(u8*) "sara.freevar.com/version.php?version=0");
}

void MasterApp_ReceiveAndTransmite(u8 Copy_u8PlayerNum){
	u8 *ptr = (void*) 0;
	u8 Local_u8ConuterPage = 0;
	u16 Local_u16CounterLoop = 0;
	u8 Local_u8ArrayBuffer[45] = { 0 };
	u8 Local_u8indexBuffer = 0;
	u8 Is_Ready=0;
	Busy_delay();///????????
	if(Copy_u8PlayerNum==1){
		MUSART2_voidTransmitChar(CHECK_READY);
		while(READY!=Is_Ready){
			MUSART2_voidReceive(&Is_Ready);
		}
	}
	else if (Copy_u8PlayerNum==2){
		MUSART3_voidTransmitChar(CHECK_READY);
		while(READY!=Is_Ready){
			MUSART3_voidReceive(&Is_Ready);
		}
	}


	while (1) {

			HESP_voidConnectToServer((u8*) "162.253.155.226", (u8*) "80");
			HESP_voidSetLengthOFRequest((u8*) "56");
			HESP_voidHttpRequestWithNumberOfPageAndPlayerNum(
					(u8*) "sara.freevar.com/fetch.php?",
					Local_u8ConuterPage,Copy_u8PlayerNum);
			HESP_u8GetDataFromServer(&ptr);

			Local_u8ConuterPage++;



			for (Local_u16CounterLoop = 0; Local_u16CounterLoop <= 2816;
					Local_u16CounterLoop++) {

				if (ptr[Local_u16CounterLoop] == 'C'
						&& ptr[Local_u16CounterLoop + 1] == 'L'
						&& ptr[Local_u16CounterLoop + 2] == 'O'
						&& ptr[Local_u16CounterLoop + 3] == 'S'
						&& ptr[Local_u16CounterLoop + 4] == 'E') {
					break;
				}
				if (ptr[Local_u16CounterLoop] == '\n') {

					if (1 == Copy_u8PlayerNum)
					{
						Local_u8ArrayBuffer[Local_u8indexBuffer++]='\n';
						Local_u8ArrayBuffer[Local_u8indexBuffer]='\0';
						MUSART2_voidTransmitString(Local_u8ArrayBuffer);


						Is_Ready=0;
						while(Is_Ready != READY){
							MUSART2_voidReceive(&Is_Ready);
							if(CHECK_READY == Is_Ready)
							{
								return;
							}
						}
					}
					else if (2 == Copy_u8PlayerNum)
					{
						Local_u8ArrayBuffer[Local_u8indexBuffer++]='\n';
						Local_u8ArrayBuffer[Local_u8indexBuffer]='\0';
						MUSART3_voidTransmitString(Local_u8ArrayBuffer);


						Is_Ready=0;
						while(Is_Ready != READY){
							MUSART3_voidReceive(&Is_Ready);
							if(CHECK_READY == Is_Ready)
							{
								return;
							}
						}
					}
					Local_u8indexBuffer = 0;
				} else {
					Local_u8ArrayBuffer[Local_u8indexBuffer++] =
							ptr[Local_u16CounterLoop];
				}
			}

		}
}
void Busy_delay(){
	u16 i,j;
	for (i = 0; i < 500; i++) {
		for (j = 0; j < 500; j++) {
			asm("NOP");
		}
	}
}

u8 AsciToHex(u8 Copy_u8Asci) {

	u8 Local_u8Result = 0;
	if ((Copy_u8Asci >= 48) && (Copy_u8Asci <= 57)) {
		Local_u8Result = Copy_u8Asci - 48;
	}

	else {
		Local_u8Result = Copy_u8Asci - 55;
	}

	return Local_u8Result;
}
