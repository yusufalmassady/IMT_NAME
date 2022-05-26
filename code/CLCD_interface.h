
/****************************************************************
 Author     : 	Ahmed Mohsen                               
 Layer      : 	HAL 		                                         
 SWC        :   LCD	                        		     
 Date       : 	25-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

/*****************************************************************
                         Includes
*****************************************************************/
#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_private.h"
/*****************************************************************
                             APIs
*****************************************************************/

/*****************************************************************/
/* name         : CLCD_voidSendCommand	                         */
/* parameter1   : 	Copy_u8Command ->command to send		     */
/* return       : 	u8 indication for error			             */
/*****************************************************************/
u8 CLCD_voidSendCommand(u8 Copy_u8Command);

/*****************************************************************/
/* name         :   CLCD_voidSendData	                         */
/* parameter1   : 	Copy_u8Data -> data to send		             */
/* return       : 	u8 indication for error			             */
/*****************************************************************/
void CLCD_voidSendData(u8 Copy_u8Data);

/*****************************************************************/
/* name         :   CLCD_voidInit	                             */
/* parameter1   : 	none                       		             */
/* return       : 	u8 indication for error			             */
/*****************************************************************/
void CLCD_voidInit(void);

/*****************************************************************/
/* name         :   CLCD_voidSendString	                         */
/* parameter1   : 	Copy_pchString -> string to display		     */
/* return       : 	u8 indication for error			             */
/*****************************************************************/
void CLCD_voidSendString(const char* Copy_pchString);

/*****************************************************************/
/* name         :   CLCD_voidSendNumber	                         */
/* parameter1   : 	Copy_u32Number -> number to display		     */
/* return       : 	u8 indication for error			             */
/*****************************************************************/
void CLCD_voidSendNumber(u32 Copy_u32Number);

/**************************************************************
    name        :   CLCD_voidGotoXY
    parameter1  :   Copy_u8XPos -> x position 
    parameter1  :   Copy_u8YPos -> y position 
    return      :   u8 indication for error	
***************************************************************/
void CLCD_voidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

/*************************************************************
    name        :   CLCD_voidWriteSpecialCharacter
    parameter1  :   Copy_pu8Pattern      -> data to send
    parameter1  :   Copy_u8PatternNumber -> data to send
    parameter1  :   Copy_u8XPos          -> data to send
    parameter1  :   Copy_u8YPos          -> data to send
    return      :   u8 indication for error	
***************************************************************/
void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);


#endif
