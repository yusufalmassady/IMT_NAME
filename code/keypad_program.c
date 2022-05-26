/*****************************************************************/
/*****************************************************************/
/* Author: 	Ahmed Mohsen	                                     */
/* Layer: 	HAL 		                                         */
/* SWC: 	Keypad			                        		     */
/* Date: 	24-5-2022	                                         */
/* Version: 1.00		                                         */
/*****************************************************************/
/*****************************************************************/

#include "keypad_interface.h"

u8 mat[4][4] = {'1','2','3','+',
				'4','5','6','-',
				'7','8','9','*',
				'N','0','=','/'
};

u8 keypad_u8Init()
{
	u8 Local_u8Error = OK;

	/* init rows pins inputs */
	DIO_u8SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN0,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN1,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN2,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN3,DIO_u8PIN_INPUT);

	/* INIT col pin as outputs  */
	DIO_u8SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_PIN3,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinValue(KEYPAD_COL_PORT,KEYPAD_COL_PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KEYPAD_COL_PORT,KEYPAD_COL_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KEYPAD_COL_PORT,KEYPAD_COL_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KEYPAD_COL_PORT,KEYPAD_COL_PIN3,DIO_u8PIN_HIGH);
	return Local_u8Error;
}

u8 keypad_u8Read()
{
	u8 Local_u8RowCounter = 0;
	u8 Local_u8ColCounter = 0;
	u8 Local_u8Val = 0xFF;

	u8 Local_u8ColArray[4] = {KEYPAD_COL_PIN0,KEYPAD_COL_PIN1,KEYPAD_COL_PIN2,KEYPAD_COL_PIN3};
	u8 Local_u8RowArray[4] = {KEYPAD_ROW_PIN0,KEYPAD_ROW_PIN1,KEYPAD_ROW_PIN2,KEYPAD_ROW_PIN3};
		
	for(Local_u8ColCounter = 0; Local_u8ColCounter < 4; Local_u8ColCounter++)
	{
		DIO_u8SetPinValue(KEYPAD_COL_PORT,Local_u8ColArray[Local_u8ColCounter],DIO_u8PIN_LOW);

		for(Local_u8RowCounter = 0; Local_u8RowCounter < 4; Local_u8RowCounter++)
		{
			DIO_u8GetPinValue(KEYPAD_ROW_PORT,Local_u8RowArray[Local_u8RowCounter],&Local_u8Val);
			if(Local_u8Val == DIO_u8PIN_LOW)
			{
				 return mat[Local_u8RowCounter][Local_u8ColCounter];
			}
		}
		/* activate col again */
		DIO_u8SetPinValue(KEYPAD_COL_PORT,Local_u8ColArray[Local_u8ColCounter],DIO_u8PIN_HIGH);
	}
	
	return Local_u8Val;
}
