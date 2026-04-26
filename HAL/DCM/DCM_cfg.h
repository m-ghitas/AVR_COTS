/*
 * DCM_cfg.h
 *
 *  Created on: Apr 26, 2026
 *      Author: Mohamed Ghitas
 */

#ifndef DCM_CFG_H_
#define DCM_CFG_H_

#include "DCM_interface.h"
#include "DCM_prv.h"

#define DCM_MAX	1

/*
 * uint8 DCM_u8Port;
 * uint8 DCM_u8Pin1;
 * uint8 DCM_u8Pin2;
*/

static const DCM_Config_t DCM_strConfig[DCM_MAX] =
{
		{DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN3}
};

#endif /* DCM_CFG_H_ */
