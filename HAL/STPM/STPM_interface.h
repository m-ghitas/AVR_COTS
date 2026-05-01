/*
 * STPM_interface.h
 *
 *  Created on: Apr 28, 2026
 *      Author: Mohamed Ghitas
 */

#ifndef STPM_INTERFACE_H_
#define STPM_INTERFACE_H_

#include "STD_TYPES.h"
#include "STPM_prv.h"

typedef struct
{
	uint8 STPM_u8Port;
	uint8 STPM_u8Pin0;
	uint8 STPM_u8Pin1;
	uint8 STPM_u8Pin2;
	uint8 STPM_u8Pin3;
}STPM_config_t;


uint8 STPM_u8Rotate(uint8 STPM_u8MotorID ,uint8 STPM_u8Direction, uint8 STPM_u8Angle);

#endif /* STPM_INTERFACE_H_ */
