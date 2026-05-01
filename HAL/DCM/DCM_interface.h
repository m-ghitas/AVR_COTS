/*
 * DCM_interface.h
 *
 *  Created on: Apr 26, 2026
 *      Author: Mohamed Ghitas
 */

#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#include "SWITCH_prv.h"

typedef struct
{
	uint8 DCM_u8Port;
	uint8 DCM_u8Pin1;
	uint8 DCM_u8Pin2;
}DCM_Config_t;

uint8 DCM_u8RotateCW(uint8 DCM_u8DCMotorID);
uint8 DCM_u8RotateCCW(uint8 DCM_u8DCMotorID);
uint8 DCM_u8Stop(uint8 DCM_u8DCMotorID);

#endif /* DCM_INTERFACE_H_ */
