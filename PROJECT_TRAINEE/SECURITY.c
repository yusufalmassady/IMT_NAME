/*
 * SECURITY.c
 *
 *  Created on: May 25, 2022
 *      Author: SAMA
 */
#include <util/delay.h>
#include "registers.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SECURITY.h"

#include "DIO_interface.h"
#include "LCD.h"
#include "KPD_interface.h"
#include "I2c.h"
#include "eeprom.h"

void ASECURITY_voidInitializePassword(void)
{
	u8 Local_u8CheckForPass,Local_u8Key=NOT_PRESSED ,Local_u8Loop=0;
	Local_u8CheckForPass=EEpromReadByte(1);
	if(Local_u8CheckForPass==NO_PASSWORD)
	{
		LCD_vidwritecommand(lcd_clr);
		LCD_setposition(0,0);
		LCD_vidwritestringoncursor("TYPE NEW PASS:");
		LCD_setposition(1,5);
		while(Local_u8Loop!=4)
		{
		while(Local_u8Key==NOT_PRESSED )
		{
			Local_u8Key=KPD_u8GetPressedKey();
		}
		EEpromWriteByte(Local_u8Loop+2,Local_u8Key);
		_delay_ms(500);
		LCD_vidwritedata(Local_u8Key);
		Local_u8Key=NOT_PRESSED ;
		Local_u8Loop++;
		}
	}
	EEpromWriteByte(1,PASSWORD_EXISTS);
	LCD_vidwritecommand(lcd_clr);
}


