/***************************************************************************************************
 *  File Name        : ESP_interface.h
 *  Module           : ESP  INTERFACE
 *  Description      : to interface ESP
 *  Created on       : JUL 14, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef HESP_INTERFACE_H
#define HESP_INTERFACE_H


	#define DISABLE_ECHO 		0
	#define ENABLE_STATION_MODE 1
	#define RESET_ESP           2


    void HESP_voidInit(void);
    u8 HESP_voidCommand(u8 Copy_U8Command);
	void HESP_voidWifiConnect(u8* Copy_U8WifiName,u8* Copy_U8WifiPassword);
	void HESP_voidConnectToServer(u8* Copy_U8Address,u8* Copy_U8Port);
	void HESP_voidSetLengthOFRequest(u8 *Copy_U8Length);
	void HESP_voidHttpRequest(u8* Copy_U8ChannelID);
	void HESP_voidHttpRequestWithNumberOfPage(u8* Copy_U8ChannelID,u8 Copy_u8NumberPage) ;
	void HESP_voidHttpRequestWithNumberOfPageAndPlayerNum(u8* Copy_U8ChannelID,
			u8 Copy_u8NumberPage, u8 Copy_u8FileNumber);
	void HESP_u8GetDataFromServer(u8 ** Copy_ReturnData);

#endif
