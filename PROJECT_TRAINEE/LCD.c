/*
 * LCD.c
 *
 *  Created on: 23 Aug 2019
 *      Author: Yussuf
 */
#include "STD_TYPES.h"
#include "registers.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "lcd_config.h"
#include "LCD.h"
#include <avr/delay.h>
#define f_cpu 8000000

extern void LCD_vidwritecommand (u8 command)
{
	//RW=0
	DIO_u8SetPinValue (control_port,RW,DIO_u8PIN_LOW);
	//RS=0
	DIO_u8SetPinValue (control_port,RS,DIO_u8PIN_LOW);
	//Data
	DIO_u8SetPortValue (data_port,command);
	//start execution E=1
	DIO_u8SetPinValue(control_port,E,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(control_port,E,DIO_u8PIN_LOW);
}
extern void LCD_vidwritedata (u8 data)
{
	//RW=0
	DIO_u8SetPinValue (control_port,RW,DIO_u8PIN_LOW);
	//RS=0
	DIO_u8SetPinValue (control_port,RS,DIO_u8PIN_HIGH);
	//Data
	DIO_u8SetPortValue (data_port,data);
	//start execution E=1
	DIO_u8SetPinValue(control_port,E,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(control_port,E,DIO_u8PIN_LOW);
}
extern void LCD_vidinit (void)
{
	DIO_u8SetPinDirection(control_port,RS,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(control_port,RW ,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(control_port,E,DIO_u8PIN_OUTPUT);
	DIO_u8SetPortDirection(data_port,0b11111111);
	_delay_ms (50);
	LCD_vidwritecommand(0b00111100);
	_delay_ms (2);
	LCD_vidwritecommand(0b00001110);
	_delay_ms (2);
	LCD_vidwritecommand(0b00000001);
}
void LCD_setposition(u8 row , u8 column)
{
	if(row==0){
		LCD_vidwritecommand(128+column);
	}
	else if (row==1){
		LCD_vidwritecommand(128+64+column);
	}
}
extern void LCD_vidwritestring (u8 line,u8 column,u8 string[])
{
	u8 i=0;
	LCD_setposition(line,column);
	_delay_ms(2);
	while (string[i]!= 0)
	{
		LCD_vidwritedata(string[i]);
		_delay_ms(2);
				i++;
	}
}
extern void LCD_vidwritestringoncursor (u8 string[])
{
	u8 i=0;
	_delay_ms(2);
	while (string[i]!= 0)
	{
		LCD_vidwritedata(string[i]);
		_delay_ms(2);
				i++;
	}
}
