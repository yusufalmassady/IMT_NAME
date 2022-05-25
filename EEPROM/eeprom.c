
#include "eeprom.h"
#include "I2C.h"


void EEpromInit(void)
{
	MI2C_voidInitMaster();
}



void EEpromWriteByte(unsigned short address, unsigned char data)
{
    MI2C_voidStart();
	MI2C_voidSendSlaveAddressWithWriteReq( 0b01010000 /*| ((address & 0x0700)>>8) */);
	MI2C_voidWriteByte((unsigned char)address);
	MI2C_voidWriteByte(data);
	MI2C_voidStop();
    return;
}



unsigned char EEpromReadByte(unsigned short address)
{
	unsigned char data;
	MI2C_voidStart();
	MI2C_voidSendSlaveAddressWithWriteReq( 0b01010000 /*| ((address & 0x07)>>8) */);
    MI2C_voidWriteByte((unsigned char)address);
	MI2C_voidRepeatedStart();
	MI2C_voidSendSlaveAddressWithReadReq( 0b01010000 /*| ((address & 0x07)>>8)*/ );
	data = MI2C_u8ReadByte();
	MI2C_voidStop();
    return data;
}
