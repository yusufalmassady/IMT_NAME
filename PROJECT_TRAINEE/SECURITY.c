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
    //REDEFINE KEY AS NOT PRESSED
	Local_u8Key=NOT_PRESSED;
	//DISPLAY MESSAGE FOR USER
	LCD_vidwritecommand(lcd_clr);
	LCD_setposition(0,0);
	LCD_vidwritestringoncursor("ENTER YOUR PASS:");
	LCD_setposition(1,5);
	//LOOP TO PASS THROUGH EEPROM
	for(Local_u8Loop=0;Local_u8Loop<4;Local_u8Loop++)
		{
		    //INFINITE LOOP TRAP UNTIL KEY IS PRESSED
			while(Local_u8Key==NOT_PRESSED )
			{
				Local_u8Key=KPD_u8GetPressedKey();
			}
			//COMPARES USER DATA TO INPUT DATA
			if(Local_u8Key!=EEpromReadByte(Local_u8Loop + 2))
			{
				//0 MEANS ERROR AND TRY AGAIN LOOP MUST CONTINUE
				Local_u8CheckForError=0;
				//CHECK FOR THREE TRIALS
				if(Local_u8PassLoopCounter==3)
				{
					//USER IS INCORRECT THREE TIMES MESSAGE
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
					//DEACTIVATE BUZZER
					DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_LOW);
					//EXIT FUNCTION
					return;
				}
				else
				{
					//TRY GAIN MESSAGE
					LCD_vidwritecommand(lcd_clr);
					LCD_setposition(0,0);
					LCD_vidwritestringoncursor("TRY AGAIN");
					_delay_ms(1000);
					//UNCHECK A TRY OF THE THREE
					Local_u8PassLoopCounter++;
					break;
				}

			}
			else
			{
				//USER WAS CORRECT BREAK LOOP
				Local_u8CheckForError=1;
			}
			//RESET VALUE TO TRAP IN LOOP
			Local_u8Key=NOT_PRESSED;
        }

	}
	//PASSWORD CORRECT, START SERVO
	LCD_vidwritecommand(lcd_clr);
	LCD_setposition(0,0);
	LCD_vidwritestringoncursor("WELCOME SIR");
}
