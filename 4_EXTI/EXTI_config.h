/*****************************************************************/
/*****************************************************************/
/********************		Author: Amgad Samir		**************/
/********************		Layer: MCAL				**************/
/********************		SWC: EXTI				**************/
/********************		Version: 1.00			**************/
/********************		Date: 14-9-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Choose INT0 Sense control(interrupt trigger)
 * Options:		1- LOW_LEVEL
 * 				2- ON_CHANGE
 * 				3- FALLING_EDGE
 * 				4- RISING_EDGE
 * */
#define EXTI_INT0_SENSE				FALLING_EDGE

/*Choose INT0 peripheral interrupt enable initial state
 * Options:		1- ENABLED
 * 				2- DISABLED
 * 									*/
#define EXTI_INT0_INITIAL_STATE		ENABLED

#endif
