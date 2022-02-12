#ifndef PARSE_INTERFACE_H
#define PARSE_INTERFACE_H
#include "ERROR_STATE.h"
u8 AsciToHex(u8 Copy_u8Asci);
ErrorState checksum(u8* Copy_record, u8 Copy_u8length);
ErrorState ParseData(u8* Copy_u8BufData);
void ParseUpperAddress(u8* Copy_u8BufData);
ErrorState Parser_vidParseRecord(u8* Copy_u8BufData);

#endif
