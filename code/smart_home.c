/*
 * smart_home.c
 *
 * Created: 24-May-22 11:35:40 PM
 *  Author: Ahmed
 */ 
#include "smart_home.h"

u8 SmartHome_init()
{
	u8 Local_u8Error = OK;
	/* init LCD */
	CLCD_voidInit();
	keypad_u8Init();
	ADC_voidInit();
	// EEpromInit();
	
	/* no password set */
	// EEpromWriteByte(1,'A');
	return Local_u8Error;
}

u8 SmartHome_WelcomeScreen()
{
	u8 Local_u8Error = OK;
		CLCD_voidSendString("Welcome IMT World");
	return Local_u8Error;	
}

u8 SmartHome_u8InitPassword()
{
	u8 Local_u8CheckForPass, Local_u8Key = 0xFF , Local_u8Loop=0 ;
	Local_u8CheckForPass = EEpromReadByte(1);
	if(Local_u8CheckForPass == 'A')
	{
		/* Enter New Password */
		CLCD_voidSendCommand(0x01);
		CLCD_voidSendString("TYPE NEW PASS:");
		CLCD_voidGotoXY(2,1);
		
		while(Local_u8Loop != 4)
		{
			while(Local_u8Key == 0xFF)
			{
				Local_u8Key = keypad_u8Read();
				_delay_ms(200);
			}
			
			EEpromWriteByte(Local_u8Loop + 2,Local_u8Key);
			_delay_ms(500);
			
			CLCD_voidSendData(EEpromReadByte(Local_u8Loop + 2));
			
			Local_u8Key = 0xFF ;
			Local_u8Loop++;
		}
	}
	else
	{
		/* nothing */
	}
}

u8 SmartHome_u8GetAdminPassword(u8 *Copy_u8UserPassword)
{
	/* get new password */
	CLCD_voidSendCommand(0x01);
	CLCD_voidSendString("Enter new Pass: ");
	CLCD_voidGotoXY(2,1);
	
	u8 Local_u8Counter = 0;
	while(1)
	{
		Copy_u8UserPassword[Local_u8Counter] = keypad_u8Read();
		_delay_ms(200);
		if (Local_u8Counter > 3)
		{
			break;
		}
		else if(Copy_u8UserPassword[Local_u8Counter] >= '0' && Copy_u8UserPassword[Local_u8Counter] <= '9')
		{
			Local_u8Counter++;
			CLCD_voidSendData('*');
		}
		else
		{
			/* nothing */
		}
	}
}

u8 SmartHome_u8ReGetPassWord(u8 *Copy_u8UserPassword)
{
	/* get new password */
	CLCD_voidSendCommand(0x01);
	CLCD_voidSendString("Enter Pass again: ");
	CLCD_voidGotoXY(2,1);
	
	u8 Local_u8Counter = 0;
	while(1)
	{
		Copy_u8UserPassword[Local_u8Counter] = keypad_u8Read();
		_delay_ms(200);
		if (Local_u8Counter > 3)
		{
			break;
		}
		else if(Copy_u8UserPassword[Local_u8Counter] >= '0' && Copy_u8UserPassword[Local_u8Counter] <= '9')
		{
			Local_u8Counter++;
			CLCD_voidSendData('*');
		}
		else
		{
			/* nothing */
		}
	}	
}

u8 SmartHome_u8CheckPassWord(u8 *Copy_u8UserPassword, u8 *Copy_u8RePassword, u8 Copy_u8PassMax)
{
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0; Local_u8Counter < Copy_u8PassMax; Local_u8Counter++)
	{
		if(Copy_u8UserPassword[Local_u8Counter] != Copy_u8RePassword[Local_u8Counter])
		{
			CLCD_voidSendCommand(0x01);
			CLCD_voidSendString("Error in Password");
			_delay_ms(500);
			return NOK;
		}
	}
	return OK;
}


u8 SmartHome_u8SystemOptions()
{
	u8 Local_u8Val;
	CLCD_voidSendCommand(0x01);
	
	CLCD_voidSendString("1- Open 2- Suspend: ");
	CLCD_voidGotoXY(2,1);
	CLCD_voidSendString("Enter Options: ");
	
	while(1)
	{
		Local_u8Val = keypad_u8Read();
		_delay_ms(200);
		
		if(Local_u8Val == '1' || Local_u8Val == '2')
		{
			break;
		}
	}

	return Local_u8Val;
}

u8 SmartHome_OpenSystem()
{

	u8 Local_u8Pass[SYSTEM_PASS_MAX] = {0}; 
	/* get password */
	CLCD_voidSendCommand(0x01);
	CLCD_voidSendString("Enter Pass: ");
	CLCD_voidGotoXY(2,1);
	
	u8 Local_u8Counter = 0;
	while(1)
	{
		Local_u8Pass[Local_u8Counter] = keypad_u8Read();
		_delay_ms(200);
		if (Local_u8Counter > 3)
		{
			break;
		}
		else if(Local_u8Pass[Local_u8Counter] >= '0' && Local_u8Pass[Local_u8Counter] <= '9')
		{
			Local_u8Counter++;
			CLCD_voidSendData('*');
		}
		else
		{
			/* nothing */
		}
	}
	
	/* check password with that in eeprom */
}

u8 SmartHome_u8TempSensorRead(u8 Copy_u8TempChannel)
{
	/* Select AVCC reference voltage */
	u8 Local_u8TempVal = ADC_u8StartConversion(Copy_u8TempChannel);
	
	float temp = (Local_u8TempVal * 5) / 256.0;
	temp = (temp * 100);
	
	return temp;
}

u8 SmartHome_u8LightSensorRead(u8 Copy_u8LightChannel)
{
	/* Select AVCC reference voltage */
	u8 Local_u8LightVal = ADC_u8StartConversion(Copy_u8LightChannel);
	
	// float Local_fLight = (Local_u8LightVal * 5) / 256.0;
	
	return Local_u8LightVal;	
}

u8 SmartHome_u8OpenDoor()
{
	/* drive servo motor */
}