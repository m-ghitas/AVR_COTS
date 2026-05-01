/*
 * STPM_prog.c
 *
 *  Created on: Apr 28, 2026
 *      Author: Mohamed Ghitas
 */

#include "STD_TYPES.h"
#include "ErrType.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "STPM_interface.h"
#include "STPM_cfg.h"
#include "STPM_prv.h"

#include <util/delay.h>

//FULL-WAVE STEP
uint8 STPM_u8Rotate(uint8 STPM_u8MotorID ,uint8 STPM_u8Direction, uint8 STPM_u8Angle)
{
    uint8 Local_ErrorState = OK;

    if(STPM_u8MotorID >= STPM_MAX)
        return NOK;

    const STPM_config_t* m = &STPM_strConfig[STPM_u8MotorID];

    uint16 steps = ((uint32)STPM_u8Angle * STEPS_PER_REV) / 360UL;

    uint8 seq[4] = {0,1,2,3};

    for(uint16 i = 0; i < steps; i++)
    {
        uint8 idx;

        if(STPM_u8Direction == STPM_DIR_CCW)
            idx = seq[i % 4];
        else if(STPM_u8Direction == STPM_DIR_CW)
            idx = seq[3 - (i % 4)];
        else
            return NOK;

        switch(idx)
        {
        case 0: // 1100
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin0, DIO_u8PIN_LOW);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin1, DIO_u8PIN_LOW);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin2, DIO_u8PIN_HIGH);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin3, DIO_u8PIN_HIGH);
            break;

        case 1: // 0110
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin0, DIO_u8PIN_HIGH);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin1, DIO_u8PIN_LOW);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin2, DIO_u8PIN_LOW);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin3, DIO_u8PIN_HIGH);
            break;

        case 2: // 0011
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin0, DIO_u8PIN_HIGH);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin1, DIO_u8PIN_HIGH);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin2, DIO_u8PIN_LOW);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin3, DIO_u8PIN_LOW);
            break;

        case 3: // 1001
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin0, DIO_u8PIN_LOW);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin1, DIO_u8PIN_HIGH);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin2, DIO_u8PIN_HIGH);
            DIO_u8SetPinValue(m->STPM_u8Port, m->STPM_u8Pin3, DIO_u8PIN_LOW);
            break;
        }

        _delay_ms(2);
    }

    return Local_ErrorState;
}
