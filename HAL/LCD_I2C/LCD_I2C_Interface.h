/*
 * LCD_I2C_Interface.h
 *
 *  Created on: Apr 29, 2026
 *      Author: Mohamed Ghitas
 */

#ifndef LCD_I2C_INTERFACE_H_
#define LCD_I2C_INTERFACE_H_

#include "STD_TYPES.h"

// Init
void LCD_I2C_voidInit(void);

// Send command
void LCD_I2C_voidSendCommand(uint8 cmd);

// Send data (character)
void LCD_I2C_voidSendData(uint8 data);

// Send string
void LCD_I2C_voidSendString(const char *str);

// Set cursor (row, col)
void LCD_I2C_voidSetCursor(uint8 row, uint8 col);

// Clear display
void LCD_I2C_voidClear(void);

#endif /* LCD_I2C_INTERFACE_H_ */
