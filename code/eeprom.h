
/****************************************************************
 Author     : 	Youssif                               
 Layer      : 	MCAL 		                                         
 SWC        :   External EEPROM			                        		     
 Date       : 	25-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/
#ifndef EEPROM_H_
#define EEPROM_H_


void EEpromInit(void);
void EEpromWriteByte(unsigned short address, unsigned char data);
unsigned char EEpromReadByte(unsigned short address);
 
#endif








