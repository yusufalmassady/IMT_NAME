/*****************************************************************/
/*****************************************************************/
/* Author: 	Ahmed Mohsen	                                     */
/* Layer: 	HAL 		                                         */
/* SWC: 	Keypad			                        		     */
/* Date: 	24-5-2022	                                         */
/* Version: 1.00		                                         */
/*****************************************************************/
/*****************************************************************/
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "gpio.h"
#include "util/delay.h"

#include "STD_TYPES.h"

#include "Keypad_interface.h"
#include "Keypad_config.h"



u8 keypad_u8Init();
u8 keypad_u8Read(u8 *Copy_u8Key);

#endif /* KEYPAD_H_ */