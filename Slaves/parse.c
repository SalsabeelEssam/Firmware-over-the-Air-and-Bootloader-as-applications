#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "parse.h"
#include "FPES_interface.h"
u32 Address = 0x08000000;
u16 Data[100] = { 0 };

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

ErrorState checksum(u8* Copy_record, u8 Copy_u8length) {
	ErrorState State = NOK;
	u16 Local_u16Sum = 0;
	u8 Local_u8Counter = 0;
	for (; Local_u8Counter < Copy_u8length - 2; Local_u8Counter += 2) {
		Local_u16Sum += AsciToHex(Copy_record[Local_u8Counter]) << 4
				| AsciToHex(Copy_record[Local_u8Counter + 1]);
	}
	Local_u16Sum = ~Local_u16Sum;
	Local_u16Sum++;
	if (((u8) Local_u16Sum)
			== ((AsciToHex(Copy_record[Local_u8Counter]) << 4)
					| (AsciToHex(Copy_record[Local_u8Counter + 1])))) {
		State = OK;
	}
	return State;
}

ErrorState ParseData(u8* Copy_u8BufData) {

	u8 CC, i;
	u8 DataDigit0, DataDigit1, DataDigit2, DataDigit3;
	u8 DataCounter = 0;

	u8 oneRecord[22];

	/* Get Character Count : */
	CC = (AsciToHex(Copy_u8BufData[1]) << 4) | AsciToHex(Copy_u8BufData[2]);
	oneRecord[0] = CC;

	/* Get Address */
	DataDigit0 = AsciToHex(Copy_u8BufData[3]);
	DataDigit1 = AsciToHex(Copy_u8BufData[4]);
	DataDigit2 = AsciToHex(Copy_u8BufData[5]);
	DataDigit3 = AsciToHex(Copy_u8BufData[6]);

	/* Clear Low Part of Address */
	Address = Address & 0xFFFF0000;
	Address = Address | (DataDigit3) | (DataDigit2 << 4) | (DataDigit1 << 8)
			| (DataDigit0 << 12);

	oneRecord[1] = (DataDigit0 << 4) | (DataDigit1);
	oneRecord[2] = (DataDigit2 << 4) | (DataDigit3);

	DataDigit0 = AsciToHex(Copy_u8BufData[7]);
	DataDigit1 = AsciToHex(Copy_u8BufData[8]);
	oneRecord[3] = (DataDigit0 << 4) | (DataDigit1);

	for (i = 0; i < CC / 2; i++) {
		DataDigit0 = AsciToHex(Copy_u8BufData[4 * i + 9]);
		DataDigit1 = AsciToHex(Copy_u8BufData[4 * i + 10]);
		DataDigit2 = AsciToHex(Copy_u8BufData[4 * i + 11]);
		DataDigit3 = AsciToHex(Copy_u8BufData[4 * i + 12]);

		Data[DataCounter] = (DataDigit3 << 8) | (DataDigit2 << 12)
				| (DataDigit1) | (DataDigit0 << 4);
		DataCounter++;

		oneRecord[4 + i * 2] = (DataDigit0 << 4) | (DataDigit1);
		oneRecord[5 + i * 2] = (DataDigit2 << 4) | (DataDigit3);
	}

	if (CC % 2 == 1) {
		DataDigit0 = AsciToHex(Copy_u8BufData[4 * i + 9]);
		DataDigit1 = AsciToHex(Copy_u8BufData[4 * i + 10]);
		oneRecord[4 + i * 2] = (DataDigit0 << 4) | (DataDigit1);

		DataDigit0 = AsciToHex(Copy_u8BufData[4 * i + 11]);
		DataDigit1 = AsciToHex(Copy_u8BufData[4 * i + 12]);
		oneRecord[5 + i * 2] = (DataDigit0 << 4) | (DataDigit1);
	} else {
		DataDigit0 = AsciToHex(Copy_u8BufData[4 * i + 9]);
		DataDigit1 = AsciToHex(Copy_u8BufData[4 * i + 10]);
		oneRecord[4 + i * 2] = (DataDigit0 << 4) | (DataDigit1);
	}

//	if (checksum(oneRecord, CC + 5) == OK) {
		FPEC_voidFlashWrite(Address, Data, CC / 2);
		return OK;
//	}

	return OUT_OF_RANGE;
}

void ParseUpperAddress(u8* Copy_u8BufData) {
//	u8 DataDigit0, DataDigit1, DataDigit2, DataDigit3;
//
//	/* Get Address */
//	DataDigit0 = AsciToHex(Copy_u8BufData[3]);
//	DataDigit1 = AsciToHex(Copy_u8BufData[4]);
//	DataDigit2 = AsciToHex(Copy_u8BufData[5]);
//	DataDigit3 = AsciToHex(Copy_u8BufData[6]);
//
//	/* Clear Low Part of Address */
//	Address = Address & (u32) 0x0000FFFF;
//	Address = Address
//			| (u32) ((u32) (DataDigit3 << 28) | (u32) (DataDigit2 << 24)
//					| (u32) (DataDigit1 << 20) | (u32) (DataDigit0 << 16));
}

ErrorState Parser_vidParseRecord(u8* Copy_u8BufData) {
	u8 Local_u8Return = NOK;
	switch (Copy_u8BufData[8]) {
	case '0':
		Local_u8Return = ParseData(Copy_u8BufData);
		break;
	case '4':
		ParseUpperAddress(Copy_u8BufData);
		Local_u8Return = OK;
		break;
	case '5':
		ParseUpperAddress(Copy_u8BufData);
		Local_u8Return = OK;
		break;
	case '1':
		Local_u8Return = END_OF_FILE;
		break;


	}

	return Local_u8Return;
}
