/*
 * SWITCH_prog.c
 *
 *  Created on: Apr 18, 2026
 *      Author: Mohamed Ghitas
 */

#include "STD_TYPES.h"

#include "ErrType.h"

#include "DIO_interface.h"


#include "SWITCH_prv.h"
#include "SWITCH_cfg.h"
#include "SWITCH_interface.h"

uint8 SWITCH_u8GetState(uint8 BUTTON_obj, uint8 *Copy_pu8State)
{
	uint8 Local_ErrorState = OK;
	uint8 Local_StateRead;

	if(BUTTON_obj < SWITCH_MAX && Copy_pu8State != NULL)
	{
		DIO_u8ReadPinValue(
				SWITCH_strConfig[BUTTON_obj].BUTTON_port,
				SWITCH_strConfig[BUTTON_obj].BUTTON_pin,
				&Local_StateRead
		);

		if(SWITCH_strConfig[BUTTON_obj].BUTTON_pullState == PULL_UP)
		{
			if(Local_StateRead == DIO_u8PIN_LOW)
				*Copy_pu8State = PRESSED;
			else
				*Copy_pu8State = RELEASED;
		}
		else // PULL_DOWN
		{
			if(Local_StateRead == DIO_u8PIN_HIGH)
				*Copy_pu8State = PRESSED;
			else
				*Copy_pu8State = RELEASED;
		}
	}
	else
	{
		Local_ErrorState = NOK;
	}

	return Local_ErrorState;
}
