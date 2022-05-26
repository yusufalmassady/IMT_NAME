/****************************************************************
 Author     : 	Ahmed Mohsen                               
 Layer      : 	MCAL 		                                         
 SWC        :   ADC		                        		     
 Date       : 	26-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/************************************************************
    Includes 
************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_register.h"
#include "ADC_config.h"

/************************************************************
    APIs 
************************************************************/

/****************************************************************
 name           : 	ADC_voidInit                        
 description    : 	init ADC  		                                         
 parameter      :   none		                        		     
 return         : 	none                                                                               
****************************************************************/
void ADC_voidInit(void);


/****************************************************************
 name           : 	ADC_u8StartConversion                        
 description    : 	return ADC converstion result  		                                         
 parameter      :   Copy_u8Channel -> to select channel(0 -> 7)		                        		     
 return         : 	u8 channel result                                                                               
****************************************************************/
u8 ADC_u8StartConversion(u8 Copy_u8Channel);


#endif