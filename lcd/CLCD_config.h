/*****************************************************************/
/*****************************************************************/
/* Author: 	Ahmed Mohsen	                                     */
/* Layer: 	HAL 		                                         */
/* SWC: 	CHARACHTER LCD			                             */
/* Date: 	24-5-2022	                                         */
/* Version: 1.00		                                         */
/*****************************************************************/
/*****************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/* CLCD_DATA_PORT 8 pins Data*/
#define CLCD_DATA_PORT			DIO_u8PORTA

#define CLCD_CTRL_PORT			DIO_u8PORTC

#define CLCD_RS_PIN				DIO_u8PIN0
#define CLCD_RW_PIN				DIO_u8PIN1
#define CLCD_E_PIN				DIO_u8PIN2

/* 
can work in 2 modes 8bit or 4bit mode: 
    CLCD_MODE_8BIT
    CLCD_MODE_4BIT 
*/
#define CLCD_MODE   CLCD_MODE_8BIT

#endif
