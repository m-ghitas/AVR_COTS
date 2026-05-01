/*
 * TWI_Interface.h
 *
 *  Created on: Apr 29, 2026
 *      Author: Mohamed Ghitas
 */

#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

#include "STD_TYPES.h"

void TWI_voidInit(void);
void TWI_voidStart(void);
void TWI_voidStop(void);
void TWI_voidWriteAddress(uint8 address);
void TWI_voidWriteData(uint8 data);

#endif
