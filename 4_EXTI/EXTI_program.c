/********************		Author: Amgad Samir		**************/
/********************		Layer: MCAL				**************/
/********************		SWC: EXTI				**************/
/********************		Version: 1.00			**************/
/********************		Date: 14-9-2020			**************/
/*****************************************************************/
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

/*Define Global array of 3 pointers to functions to carry ISR application addresses*/
static void (*EXTI_pvINTCallBackFunc[3])(void)={NULL};

void EXTI_voidINT0Init(void)
{
	/*Check on INT0 Sense control*/
#if EXTI_INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
#error "Wrong EXTI_INT0_SENSE configuration option"
#endif

	/*Check INT0 PIE initial state*/
#if EXTI_INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif EXTI_INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error " Wrong EXTI_INT0_INITIAL_STATE configuration option"
#endif
}

u8 EXTI_u8SetSenseControl(u8 Copy_u8IntNumber, u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState= OK;
	switch (Copy_u8IntNumber)
	{
	case EXTI_INT0:		/*In case INT0*/
		switch(Copy_u8Sense)
		{
		case LOW_LEVEL:   CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case ON_CHANGE:   SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
		case RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
		default: Local_u8ErrorState = NOK;			break;
		}
		break;			/*Break INT0 case*/
		case EXTI_INT1:	/*In case of INT1*/
			switch(Copy_u8Sense)
			{
			case LOW_LEVEL:   CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
			case ON_CHANGE:   SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
			case FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
			case RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
			default: Local_u8ErrorState = NOK;			break;
			}
			break;		/*Break INT1 case*/
			case EXTI_INT2:	/*In case of INT2*/
				switch(Copy_u8Sense)
				{
				case RISING_EDGE: SET_BIT(MCUCSR,MCUCSR_ISC2);  break;
				case FALLING_EDGE: CLR_BIT(MCUCSR,MCUCSR_ISC2);  break;
				default: Local_u8ErrorState=NOK; break;
				}
				break;		/*Break INT2 case*/
			default: Local_u8ErrorState = NOK;		break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8INT0SetCallBack(void (*Copy_pvCallBackFunc)(void), u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		EXTI_pvINTCallBackFunc[Copy_u8IntNumber]= Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
}

/*ISR of INT0*/
void  __vector_1 (void)	__attribute__((signal));
void  __vector_1 (void)
{
	if(EXTI_pvINTCallBackFunc[EXTI_INT0] != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_INT0]();
	}
	else
	{
		/*Do nothing*/
	}

}
/*ISR of INT1*/
void  __vector_2 (void)	__attribute__((signal));
void  __vector_2 (void)
{
	if(EXTI_pvINTCallBackFunc[EXTI_INT1] != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_INT1]();
	}
	else
	{
		/*Do nothing*/
	}

}
/*ISR of INT2*/
void  __vector_3 (void)	__attribute__((signal));
void  __vector_3 (void)
{
	if(EXTI_pvINTCallBackFunc[EXTI_INT2] != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_INT0]();
	}
	else
	{
		/*Do nothing*/
	}

}
