/*****************************************************************/
/*****************************************************************/
/* Author: 	Ahmed Mohsen	                                     */
/* Layer: 	HAL 		                                         */
/* SWC: 	CHARACHTER LCD			                             */
/* Date: 	24-5-2022	                                         */
/* Version: 1.00		                                         */
/*****************************************************************/
/*****************************************************************/

#include "CLCD_interface.h"


u8 CLCD_voidSendCommand(u8 Copy_u8Command)
{
	u8 Local_u8Error = OK;

#if 		CLCD_MODE == CLCD_MODE_8BIT
	/*1- Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*3- Send the command to the LCD*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*4- Send the enable pulse to the LCD*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#elif		CLCD_MODE == CLCD_MODE_4BIT
		/* no thing */
#endif
	return Local_u8Error;
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
#if 		CLCD_MODE == CLCD_MODE_8BIT
	/*1- Set RS pin to high for Data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*3- Send the Data to the LCD*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*4- Send the enable pulse to the LCD*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#elif			CLCD_MODE == CLCD_MODE_4BIT	
#endif		
}

void CLCD_voidInit(void)
{
#if 		CLCD_MODE == CLCD_MODE_8BIT
	/*1- wait for more than 30 ms*/
	_delay_ms(40);

	/* */

	/*2- Function set command: 2 lines, Font= 5x7*/
	CLCD_voidSendCommand(0b00111000);

	/*3- Display on off control: Display on, cursor off, blink cursor off*/
	CLCD_voidSendCommand(0b00001100);

	/*4- Display clear*/
	CLCD_voidSendCommand(1);
#elif			CLCD_MODE == CLCD_MODE_4BIT
#endif	

}

void CLCD_voidSendString(const char* Copy_pchString)
{
	u8 Local_u8Counter=0;
	while(Copy_pchString[Local_u8Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pchString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8DDRAMAddress;
	if(Copy_u8YPos ==0)
	{
		/*Check if in first line*/
		Local_u8DDRAMAddress=Copy_u8XPos;
	}
	else if(Copy_u8YPos==1)
	{
		/*Check if in second line*/
		Local_u8DDRAMAddress=0x40+Copy_u8XPos;
	}

	/*Setbit number 7 for SetDDRAM Address command then send the command*/
	CLCD_voidSendCommand(Local_u8DDRAMAddress+128);
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRamAddress,Local_u8Counter;

	/*1- calculate CGRAM address knowing that every pattern consumes 8 bytes*/
	Local_u8CGRamAddress= Copy_u8PatternNumber*8;

	/*2-Send SET CGRAM address command to LCD with setting bit6 ,clearing bit7*/
	CLCD_voidSendCommand(Local_u8CGRamAddress+64);

	/*3- write the pattern into CGRAM*/
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Counter]);
	}
	/*4- Back to the DDRAM to display the special pattern*/
	CLCD_voidGotoXY(Copy_u8XPos,Copy_u8YPos);

	/*5- Display the special pattern*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}
