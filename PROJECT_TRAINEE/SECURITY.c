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
		LCD_vidwritedata(EEpromReadByte(Local_u8Loop+2));
		Local_u8Key=NOT_PRESSED ;
		Local_u8Loop++;
		}
	}
	EEpromWriteByte(1,PASSWORD_EXISTS);
	_delay_ms(1000);
	LCD_vidwritecommand(lcd_clr);
}

void ASECURITY_voidCheckPassword()
{
	u8 Local_u8Key=NOT_PRESSED ,Local_u8Loop=0,Local_u8PassLoopCounter=0,Local_u8BuzzLoop=0,Local_u8CheckForError=0;
	while(Local_u8CheckForError==0)
	{
	Local_u8Key=NOT_PRESSED;
	LCD_vidwritecommand(lcd_clr);
	LCD_setposition(0,0);
	LCD_vidwritestringoncursor("ENTER YOUR PASS:");
	LCD_setposition(1,5);
	for(Local_u8Loop=0;Local_u8Loop<4;Local_u8Loop++)
		{
			while(Local_u8Key==NOT_PRESSED )
			{
				Local_u8Key=KPD_u8GetPressedKey();
			}
			if(Local_u8Key!=EEpromReadByte(Local_u8Loop + 2))
			{
				Local_u8CheckForError=0;
				if(Local_u8PassLoopCounter==3)
				{
					LCD_vidwritecommand(lcd_clr);
					LCD_setposition(0,0);
					LCD_vidwritestringoncursor("STOP RIGHT THERE");
					LCD_setposition(1,0);
					LCD_vidwritestringoncursor("CRIMINAL SCUM");
					//BUZZ FOR 20 SECONDS
					for(Local_u8BuzzLoop=0;Local_u8BuzzLoop<20;Local_u8BuzzLoop++)
					{
						//ACTIVATES BUZZER
						DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_HIGH);
								_delay_ms(500);
						DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_LOW);
							   _delay_ms(500);
					}
					DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_LOW);
					return;
				}
				else
				{
					LCD_vidwritecommand(lcd_clr);
					LCD_setposition(0,0);
					LCD_vidwritestringoncursor("TRY AGAIN");
					_delay_ms(1000);
					Local_u8PassLoopCounter++;
				}

			}
			else
			{
				Local_u8CheckForError=1;
			}
			Local_u8Key=NOT_PRESSED;
        }

	}
	//PASSWORD CORRECT, START SERVO
	LCD_vidwritecommand(lcd_clr);
	LCD_setposition(0,0);
	LCD_vidwritestringoncursor("WELCOME SIR");
}
