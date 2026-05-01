/*
 * SWITCHE_cfg.h
 *
 *  Created on: Apr 18, 2026
 *      Author: Mohamed Ghitas
 */

#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

#include "DIO_interface.h"
#include "SWITCH_prv.h"
#include "SWITCH_interface.h"

/*
 *  uint8 BUTTON_port;
	uint8 BUTTON_pin;
	uint8 BUTTON_pullState;
 */

static const SWITCH_config_t SWITCH_strConfig[SWITCH_MAX]=
{
		/* LED_POWER */
		{DIO_u8PORTD, DIO_u8PIN4, PULL_DOWN},

		/* LED_STATUS */
		{DIO_u8PORTB, DIO_u8PIN6, PULL_DOWN},

		/* LED_ERROR */
		{DIO_u8PORTB, DIO_u8PIN7, PULL_DOWN}
};

#endif /* SWITCH_CFG_H_ */
