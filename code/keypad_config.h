/*****************************************************************/
/*****************************************************************/
/* Author: 	Ahmed Mohsen	                                     */
/* Layer: 	HAL 		                                         */
/* SWC: 	Keypad			                        		     */
/* Date: 	24-5-2022	                                         */
/* Version: 1.00		                                         */
/*****************************************************************/
/*****************************************************************/


#define KEYPAD_ROW_PORT     DIO_u8PORTA
#define KEYPAD_COL_PORT 	DIO_u8PORTA


#define KEYPAD_ROW_PIN0     DIO_u8PIN0
#define KEYPAD_ROW_PIN1     DIO_u8PIN1
#define KEYPAD_ROW_PIN2     DIO_u8PIN2
#define KEYPAD_ROW_PIN3     DIO_u8PIN3

#define KEYPAD_COL_PIN0     DIO_u8PIN4
#define KEYPAD_COL_PIN1     DIO_u8PIN5
#define KEYPAD_COL_PIN2     DIO_u8PIN6
#define KEYPAD_COL_PIN3     DIO_u8PIN7



/*
	First 4  pins for row  ==> output
	Second 4 pins for cols ==> input
*/