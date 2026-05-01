#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define KPD_au8_BUTTON_ARR  { \
		{'1','2','3','/'}, \
		{'4','5','6','*'}, \
		{'7','8','9','-'}, \
		{'C','0','=','+'}  \
}

#define KPD_u8NO_PRESSED_KEY_VAL 	0xff


uint8 KPD_u8GetPressedKey(void);

#endif
