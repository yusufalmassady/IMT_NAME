
#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


#define START_ACK                0x08 // start has been sent
#define REP_START_ACK            0x10 // repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK
#define WR_BYTE_ACK              0x28 // Master transmit data ACK
#define RD_BYTE_WITH_NACK        0x58 // Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with write req
#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with read req
#define SLAVE_DATA_RECEIVED      0x80 // means that read byte req is received
#define SLAVE_BYTE_TRANSMITTED   0xC0 // means that write byte req is received

//initializes controller as master
//takes no arguments
//returns void
void MI2C_voidInitMaster(void);

//initializes controller as slave
//takes no arguments
//returns void
void MI2C_voidInitSlave(void);

//sends start condition
//takes no arguments
//returns void
void MI2C_voidStart(void);


//sends repeated start condition
//takes no arguments
//returns void
void MI2C_voidRepeatedStart(void);


//takes in argument of slave address 
//returns void 
void MI2C_voidSendSlaveAddressWithWriteReq(u8 Copy_u8SlaveAddress);


//takes in argument of slave address 
//returns void 
void MI2C_voidSendSlaveAddressWithReadReq(u8 Copy_u8SlaveAddress)


//takes in argument of data byte to be send 
//returns void 
void MI2C_voidWriteByte(u8 Copy_u8Byte);

//takes no arguments 
//returns the data byte on TWDR register
u8 MI2C_u8ReadByte(void);

//sends stop condition
//takes no arguments 
//returns void  
void MI2C_voidStop(void);

//enables acknowledgement after recieving write requirement
//takes no arguments 
//returns void 
void MI2C_voidSlaveCheckSlaveAddressReceivedWithWriteReq(void);

//enables acknowledgement after recieving read requirement
//takes no arguments 
//returns void 
void MI2C_voidSlaveCheckSlaveAddressReceivedWithReadReq(void);

//takes no arguments 
//returns data byte on TWDR 
u8 MI2C_voidSlaveReadByte(void);

//takes in the argument of the data byte to be sent 
//returns void 
void MI2C_voidSlaveWriteByte(u8 Copy_u8Byte);

#endif

