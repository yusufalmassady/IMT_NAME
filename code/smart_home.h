/*
 * smart_home.h
 *
 * Created: 24-May-22 11:35:31 PM
 *  Author: Ahmed
 */ 


#ifndef SMART_HOME_H_
#define SMART_HOME_H_
/************************************************************************/
/* Includes                                                             */
/************************************************************************/
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "keypad_interface.h"
#include "eeprom.h"
#include "EXTI_interface.h"

#define SYSTEM_PASS_MAX		4

/**************************************************************
    name        :   SmartHome_init
    parameter1  :   none
	description	:	init Whole system components
    return      :   u8 indication for error	
***************************************************************/
u8 SmartHome_init();

/**************************************************************
    name        :   SmartHome_WelcomeScreen
    parameter1  :   none
	description	:	display Welcome screen
    return      :   u8 indication for error	
***************************************************************/
u8 SmartHome_WelcomeScreen();

/**************************************************************
    name        :   SmartHome_u8TempSensorRead
    parameter1  :   Copy_u8TempChannel -> from 0 to 7
	description	:	read temperature value
    return      :   u8 indication for error	
***************************************************************/
u8 SmartHome_u8TempSensorRead(u8 Copy_u8TempChannel);

/**************************************************************
    name        :   SmartHome_u8LightSensorRead
    parameter1  :   Copy_u8LightChannel -> from 0 to 7
	description	:	read Light intensity value
    return      :   u8 indication for error	
***************************************************************/
u8 SmartHome_u8LightSensorRead(u8 Copy_u8LightChannel);

/**************************************************************
    name        :   SmartHome_u8OpenDoor
    parameter1  :   none
	description	:	take action moving servo motor
    return      :   u8 indication for error	
***************************************************************/
u8 SmartHome_u8OpenDoor();


/* Can Remove them */
u8 SmartHome_u8InitPassword();
u8 SmartHome_u8GetAdminPassword(u8 *Copy_u8UserPassword);
u8 SmartHome_u8GetPassWord(u32 *Copy_u32UserPassword);
u8 SmartHome_u8ReGetPassWord(u8 *Copy_u8UserPassword);
u8 SmartHome_u8CheckPassWord(u8 *Copy_u8UserPassword, u8 *Copy_u8RePassword, u8 Copy_u8PassMax);
u8 SmartHome_u8GetUserInput(u8 *Copy_u8UserInput);
u8 SmartHome_u8SystemOptions();
u8 SmartHome_OpenSystem();
#endif /* SMART_HOME_H_ */