/*
 * LCD_I2C_Prog.c
 *
 *  Created on: Apr 29, 2026
 *      Author: Mohamed Ghitas
 */

#include "LCD_I2C_Interface.h"
#include "TWI_Interface.h"
#include <util/delay.h>

#define LCD_ADDRESS 0x27

// Control bits
#define EN 0x04
#define RW 0x00
#define RS 0x01
#define BACKLIGHT 0x08

static void LCD_I2C_voidSendNibble(uint8 data)
{
    TWI_voidStart();
    TWI_voidWriteAddress(LCD_ADDRESS << 1);

    TWI_voidWriteData(data | EN | BACKLIGHT);
    _delay_us(1);

    TWI_voidWriteData((data & ~EN) | BACKLIGHT);
    _delay_us(50);

    TWI_voidStop();
}

static void LCD_I2C_voidSendByte(uint8 data, uint8 control)
{
    uint8 high = (data & 0xF0) | control;
    uint8 low  = ((data << 4) & 0xF0) | control;

    LCD_I2C_voidSendNibble(high);
    LCD_I2C_voidSendNibble(low);
}

void LCD_I2C_voidSendCommand(uint8 cmd)
{
    LCD_I2C_voidSendByte(cmd, 0);
}

void LCD_I2C_voidSendData(uint8 data)
{
    LCD_I2C_voidSendByte(data, RS);
}

void LCD_I2C_voidInit(void)
{
    _delay_ms(50);

    LCD_I2C_voidSendCommand(0x33);
    LCD_I2C_voidSendCommand(0x32);
    LCD_I2C_voidSendCommand(0x28); // 4-bit, 2 lines
    LCD_I2C_voidSendCommand(0x0C); // display ON
    LCD_I2C_voidSendCommand(0x06); // entry mode
    LCD_I2C_voidSendCommand(0x01); // clear

    _delay_ms(5);
}

void LCD_I2C_voidSendString(const char *str)
{
    while(*str)
    {
        LCD_I2C_voidSendData(*str++);
    }
}

void LCD_I2C_voidSetCursor(uint8 row, uint8 col)
{
    uint8 address;

    if(row == 0)
        address = 0x80 + col;
    else
        address = 0xC0 + col;

    LCD_I2C_voidSendCommand(address);
}

void LCD_I2C_voidClear(void)
{
    LCD_I2C_voidSendCommand(0x01);
    _delay_ms(2);
}

