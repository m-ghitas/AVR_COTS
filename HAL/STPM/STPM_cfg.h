/*
 * STPM_cfg.h
 *
 *  Created on: Apr 28, 2026
 *      Author: Mohamed Ghitas
 */

#ifndef STPM_CFG_H_
#define STPM_CFG_H_

#include "STD_TYPES.h"
#include "STPM_interface.h"
#include "DIO_interface.h"

#define STPM_u8MotorID0		0
#define STPM_u8MotorID1		1
#define STPM_u8MotorID2		2

#define STPM_MAX			3


static const STPM_config_t STPM_strConfig [STPM_MAX] =
{
		{DIO_u8PORTD, DIO_u8PIN0,DIO_u8PIN1,DIO_u8PIN2,DIO_u8PIN3},
		{0,0,0,0,0},
		{0,0,0,0,0}
};


#endif /* STPM_CFG_H_ */
