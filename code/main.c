/*
 * code.c
 *
 * Created: 24-May-22 7:03:55 PM
 * Author : Ahmed
 */ 

#include "smart_home.h"
#include "ADC_interface.h"

int main(void)
{
	SmartHome_init();
	SmartHome_WelcomeScreen();
	_delay_ms(500);
	
	/* check if password already in EEPROM or not */
	// SmartHome_u8InitPassword();
	
	u8 Local_u8TempVal = 0x00;
	u8 Local_u8LightVal = 0x00;
	CLCD_voidSendCommand(0x01);
	while(1)
	{
		Local_u8TempVal  = SmartHome_u8TempSensorRead(0);
		Local_u8LightVal = SmartHome_u8LightSensorRead(1);
		
		/* Display data (Temp and Light )on LCD */
		CLCD_voidGotoXY(1,1);
		CLCD_voidSendString("Temp: ");
		CLCD_voidSendNumber((u32)Local_u8TempVal);
		CLCD_voidSendData('C');
		CLCD_voidGotoXY(2,1);
		CLCD_voidSendString("Light: ");
		CLCD_voidSendNumber((u32)Local_u8LightVal);
		
		/* 
			use external interrupt to deal with external button 
		*/
		
		/* check for Temperature */
		if(Local_u8TempVal > 50)
		{
			// SmartHome_voidFanOn();
		}
		else
		{
			// SmartHome_voidFanOff();
		}
		
		/* check for Light */
		if(Local_u8LightVal > 200)
		{
			// SmartHome_voidLedOff();
		}
		else
		{
			// SmartHome_voidLedOn();
		}	
	}
}

