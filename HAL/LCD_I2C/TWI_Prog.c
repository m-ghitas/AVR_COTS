/*
 * TWI_Prog.c
 *
 *  Created on: Apr 29, 2026
 *      Author: Mohamed Ghitas
 */

#include "TWI_Interface.h"
#include <avr/io.h>

void TWI_voidInit(void)
{
    // SCL frequency = 100kHz (assuming 8MHz clock)
    TWBR = 32;
}

void TWI_voidStart(void)
{
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    while(!(TWCR & (1<<TWINT)));
}

void TWI_voidStop(void)
{
    TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

void TWI_voidWriteAddress(uint8 address)
{
    TWDR = address;
    TWCR = (1<<TWINT) | (1<<TWEN);
    while(!(TWCR & (1<<TWINT)));
}

void TWI_voidWriteData(uint8 data)
{
    TWDR = data;
    TWCR = (1<<TWINT) | (1<<TWEN);
    while(!(TWCR & (1<<TWINT)));
}
