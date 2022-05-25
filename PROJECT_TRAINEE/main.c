#define F_CPU 8000000
#include <util/delay.h>
#include "registers.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD.h"
#include "KPD_interface.h"
#include "I2c.h"
#include "eeprom.h"
#include "SECURITY.h"

int main(void)
{
	
	EEpromInit();
	
	LCD_vidinit();
	//KeybPadInit();
	KPD_voidInit();
	//LCD_writestring("Last Saved");
	
	//i2c_init_master();

	_delay_ms(500);
	EEpromWriteByte(1,NO_PASSWORD);
	_delay_ms(500);
    DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_OUTPUT);




	while (1)
	{
	u8 Local_u8Key=NOT_PRESSED;
	ASECURITY_voidInitializePassword();


	while(Local_u8Key==NOT_PRESSED)
	{
		Local_u8Key=KPD_u8GetPressedKey();
	}
	LCD_vidwritedata(Local_u8Key);
    DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_HIGH);
    if(Local_u8Key==OPEN_THE_DOOR)
    {
        DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_LOW);
    }
	}
}
