/*
 * DCM_prog.c
 *
 *  Created on: Apr 26, 2026
 *      Author: Mohamed Ghitas
 */

#include "STD_TYPES.h"

#include "ErrType.h"

#include "DIO_interface.h"

#include "DCM_interface.h"
#include "DCM_prv.h"
#include "DCM_cfg.h"


uint8 DCM_u8RotateCW(uint8 DCM_u8DCMotorID)
{
	uint8 Local_ErrorState = OK;

	if(DCM_u8DCMotorID < DCM_MAX)
		{
			const DCM_Config_t* Local_DCM = &DCM_strConfig[DCM_u8DCMotorID];
			DIO_u8SetPinDirection(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin1, DIO_u8PIN_OUTPUT);
			DIO_u8SetPinDirection(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin2, DIO_u8PIN_OUTPUT);

			DIO_u8SetPinValue(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin1, DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin2, DIO_u8PIN_LOW);
		}
		return Local_ErrorState;
}


uint8 DCM_u8RotateCCW(uint8 DCM_u8DCMotorID)
{
	uint8 Local_ErrorState = OK;

		if(DCM_u8DCMotorID < DCM_MAX)
			{
				const DCM_Config_t* Local_DCM = &DCM_strConfig[DCM_u8DCMotorID];
				DIO_u8SetPinDirection(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin1, DIO_u8PIN_OUTPUT);
				DIO_u8SetPinDirection(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin2, DIO_u8PIN_OUTPUT);

				DIO_u8SetPinValue(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin1, DIO_u8PIN_LOW);
				DIO_u8SetPinValue(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin2, DIO_u8PIN_HIGH);
			}
			return Local_ErrorState;
}


uint8 DCM_u8Stop(uint8 DCM_u8DCMotorID)
{
	uint8 Local_ErrorState = OK;

		if(DCM_u8DCMotorID < DCM_MAX)
			{
				const DCM_Config_t* Local_DCM = &DCM_strConfig[DCM_u8DCMotorID];
				DIO_u8SetPinDirection(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin1, DIO_u8PIN_OUTPUT);
				DIO_u8SetPinDirection(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin2, DIO_u8PIN_OUTPUT);

				DIO_u8SetPinValue(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin1, DIO_u8PIN_LOW);
				DIO_u8SetPinValue(Local_DCM->DCM_u8Port, Local_DCM->DCM_u8Pin2, DIO_u8PIN_LOW);
			}
			return Local_ErrorState;
}
