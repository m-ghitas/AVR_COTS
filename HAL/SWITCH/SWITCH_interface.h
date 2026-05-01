/*
 * SWITCH_interface.h
 *
 *  Created on: Apr 18, 2026
 *      Author: Mohamed Ghitas
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#define SWITCH_1	0
#define SWITCH_2	1
#define SWITCH_OK	2

#define SWITCH_MAX		3


typedef struct
{

	uint8 BUTTON_port;
	uint8 BUTTON_pin;
	uint8 BUTTON_pullState;

}SWITCH_config_t;



uint8 SWITCH_u8GetState(uint8 BUTTON_obj, uint8 *Copy_pu8State);

#endif /* SWITCH_INTERFACE_H_ */
