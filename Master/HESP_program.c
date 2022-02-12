/***************************************************************************************************
 *  File Name        : ESP_program.C
 *  Module           : ESP  PROGRAM
 *  Description      : public function
 *  Created on       : JUL 14, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "MUART_interface.h"

#include "HESP_interface.h"
#include "HESP_private.h"
#include "HESP_config.h"
static u8 Local_u8Response[LENGTH_OF_RETURN_DATA];

void HESP_voidInit(void) {
	ErrorState STATE = NOK;
	MUSART1_voidInit();
	while (!STATE) {
		/*clear data register*/
		MUSART1_VoidClearReceiver();
		/* set Station mode*/
		STATE = HESP_voidCommand(RESET_ESP);
		HESP_delay();
	}
	STATE = NOK;
	while (!STATE) {
		/*clear data register*/
		MUSART1_VoidClearReceiver();
		/*Stop Echo*/
		STATE = HESP_voidCommand(DISABLE_ECHO);
		HESP_delay();

	}
	STATE = NOK;
	while (!STATE) {
		/*clear data register*/
		MUSART1_VoidClearReceiver();
		/* set Station mode*/
		STATE = HESP_voidCommand(ENABLE_STATION_MODE);
		HESP_delay();
	}

}
u8 HESP_voidCommand(u8 Copy_U8Command) {
	if (DISABLE_ECHO == Copy_U8Command)
		MUSART1_voidTransmitString((u8*) "ATE0\r\n");
	else if (ENABLE_STATION_MODE == Copy_U8Command)
		MUSART1_voidTransmitString((u8*) "AT+CWMODE=1\r\n");
	else if (RESET_ESP == Copy_U8Command)
		MUSART1_voidTransmitString((u8*) "AT+RST\r\n");
	/* check if OK  */
	return (HESP_ReadOK_ERROR());
}

void HESP_voidWifiConnect(u8* Copy_U8WifiName, u8* Copy_U8WifiPassword) {
	/*clear data register*/
	MUSART1_VoidClearReceiver();
	MUSART1_voidTransmitString((u8*) "AT+CWJAP_CUR=\"");
	MUSART1_voidTransmitString(Copy_U8WifiName);
	MUSART1_voidTransmitString((u8*) "\",\"");
	MUSART1_voidTransmitString(Copy_U8WifiPassword);
	MUSART1_voidTransmitString((u8*) "\"\r\n");
	/* check if OK  */
	HESP_ReadOK_ERROR();
	HESP_delay();
}

void HESP_voidConnectToServer(u8* Copy_U8Address, u8* Copy_U8Port) {
	/*clear data register*/
	MUSART1_VoidClearReceiver();
	MUSART1_voidTransmitString((u8*) "AT+CIPSTART=\"TCP\",\"");
	MUSART1_voidTransmitString(Copy_U8Address);
	MUSART1_voidTransmitString((u8*) "\",");
	MUSART1_voidTransmitString(Copy_U8Port);
	MUSART1_voidTransmitString((u8*) "\r\n");
	/* check if OK  */
	HESP_ReadOK_ERROR();
	HESP_delay();
}

void HESP_voidSetLengthOFRequest(u8 *Copy_U8Length) {
	/*clear data register*/
	MUSART1_VoidClearReceiver();
	MUSART1_voidTransmitString((u8*) "AT+CIPSEND=");
	MUSART1_voidTransmitString(Copy_U8Length);
	MUSART1_voidTransmitString((u8*) "\r\n");
	/* check if OK  */
	HESP_ReadOK_ERROR();
	HESP_delay();
}

void HESP_voidHttpRequest(u8* Copy_U8ChannelID) {
	/*clear array of data*/
	HESP_ClearData();
	/*clear data register*/
	MUSART1_VoidClearReceiver();
	MUSART1_voidTransmitString((u8*) "GET http://");
	MUSART1_voidTransmitString(Copy_U8ChannelID);
	MUSART1_voidTransmitString((u8*) "\r\n");
	HESP_ReadData();

}

void HESP_voidHttpRequestWithNumberOfPage(u8* Copy_U8ChannelID,
		u8 Copy_u8NumberPage) {
	u8 string[2] = { 0 };
	if (Copy_u8NumberPage < 10) {
		string[0] = '0';
		string[1] = Copy_u8NumberPage + 48;
	} else if (Copy_u8NumberPage >= 10) {
		string[0] = (Copy_u8NumberPage / 10) + 48;
		string[1] = (Copy_u8NumberPage % 10) + 48;
	}
	/*clear array of data*/
	HESP_ClearData();
	/*clear data register*/
	MUSART1_VoidClearReceiver();
	MUSART1_voidTransmitString((u8*) "GET http://");
	MUSART1_voidTransmitString(Copy_U8ChannelID);
	MUSART1_voidTransmitString(string);
	MUSART1_voidTransmitString((u8*) "\r\n");
	HESP_ReadData();

}

void HESP_voidHttpRequestWithNumberOfPageAndPlayerNum(u8* Copy_U8ChannelID,
		u8 Copy_u8NumberPage, u8 Copy_u8FileNumber) {
	u8 string[2] = { 0 };
	if (Copy_u8NumberPage < 10) {
		string[0] = '0';
		string[1] = Copy_u8NumberPage + 48;
	} else if (Copy_u8NumberPage >= 10) {
		string[0] = (Copy_u8NumberPage / 10) + 48;
		string[1] = (Copy_u8NumberPage % 10) + 48;
	}
	/*clear array of data*/
	HESP_ClearData();
	/*clear data register*/
	MUSART1_VoidClearReceiver();
	MUSART1_voidTransmitString((u8*) "GET http://");
	MUSART1_voidTransmitString(Copy_U8ChannelID);
	MUSART1_voidTransmitString((u8*) "Page=");
	MUSART1_voidTransmitString(string);
	MUSART1_voidTransmitString((u8*) "&Player=");
	MUSART1_voidTransmitChar(Copy_u8FileNumber+48);
	MUSART1_voidTransmitString((u8*) "\r\n");
	HESP_ReadData();

}
static u8 HESP_ReadOK_ERROR(void) {
	for (s32 i = 0; i < LENGTH_OF_RETURN_DATA; i++) {
		MUSART1_voidReceive(Local_u8Response + i);
		if (i > 1) {
			if (Local_u8Response[i - 1] == 'O') {
				if (Local_u8Response[i] == 'K') {
					for (; i >= 0; i--)
						Local_u8Response[i] = 0;
					return OK;
				} else if (Local_u8Response[i] == 'R') {
					for (; i >= 0; i--)
						Local_u8Response[i] = 0;
					return NOK;
				}
			}

		}
	}
	return NOK;
}

static void HESP_ReadData(void) {
	u8 Local_u8Flag = 0;
	for (s32 i = 0; i < LENGTH_OF_RETURN_DATA; i++) {
		MUSART1_voidReceive(Local_u8Response + i);
		if (Local_u8Flag == 0 && Local_u8Response[i] == ':') {
			i = -1;
			Local_u8Flag = 1;

		}
		if (i > 3) {
			if (Local_u8Response[i - 4] == 'C' && Local_u8Response[i - 3] == 'L'
					&& Local_u8Response[i - 2] == 'O'
					&& Local_u8Response[i - 1] == 'S'
					&& Local_u8Response[i] == 'E')
				break;
		}
		if (Local_u8Response[i] == '\r' && Local_u8Flag == 1) {
			while (Local_u8Response[i] != ':') {
				MUSART1_voidReceive(Local_u8Response + i);
			}
			i--;
		}
	}
}

static void HESP_ClearData(void) {
	for (u32 i = 0; i < LENGTH_OF_RETURN_DATA; i++)
		Local_u8Response[i] = 0;
}
static void HESP_delay(void) {
	for (u32 i = 0; i < DELAY_TIME; i++)
		asm("nop");
}

void HESP_u8GetDataFromServer(u8 ** Copy_ReturnData) {
	*Copy_ReturnData = (Local_u8Response);
}
