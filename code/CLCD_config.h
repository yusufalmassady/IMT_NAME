
/****************************************************************
 Author     : 	Ahmed Mohsen                               
 Layer      : 	HAL 		                                         
 SWC        :   LCD	                        		     
 Date       : 	25-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/* CLCD_DATA_PORT 8 pins Data*/
#define CLCD_DATA_PORT			DIO_u8PORTD	

/*	
	CLCD_CTRL_PORT
		DIO_u8PORTA
		DIO_u8PORTB
		DIO_u8PORTC
		DIO_u8PORTD
*/
#define CLCD_CTRL_PORT			DIO_u8PORTC

/*	
	Pins
		DIO_u8PIN1	 DIO_u8PIN2	 DIO_u8PIN3	 DIO_u8PIN4	 
		DIO_u8PIN5	 DIO_u8PIN6  DIO_u8PIN7  DIO_u8PIN8
*/
#define CLCD_RS_PIN				DIO_u8PIN0
#define CLCD_RW_PIN				DIO_u8PIN1
#define CLCD_E_PIN				DIO_u8PIN2

/* 
can work in 2 modes 8bit or 4bit mode: 
    CLCD_MODE_8BIT
    CLCD_MODE_4BIT 
*/
#define CLCD_MODE   CLCD_MODE_4BIT

#endif
