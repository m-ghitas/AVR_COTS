#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>
#include "CLCD_cfg.h"

/* =======================
   Button Update Functions
   =======================*/

uint8 Update_UP(void)
{
	uint8 current = 0;
	static uint8 prev = 0;
	uint8 temp = 0;
	uint8 pressed = 0;

	DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN2, &current);
	_delay_ms(10);
	DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN2, &temp);

	if(current == temp)
	{
		if(current == 1 && prev == 0)
			pressed = 1;
	}

	prev = current;
	return pressed;
}

uint8 Update_Down(void)
{
	uint8 current = 0;
	static uint8 prev = 0;
	uint8 temp = 0;
	uint8 pressed = 0;

	DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN6, &current);
	_delay_ms(10);
	DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN6, &temp);

	if(current == temp)
	{
		if(current == 1 && prev == 0)
			pressed = 1;
	}

	prev = current;
	return pressed;
}

uint8 Update_OK(void)
{
	uint8 current = 0;
	static uint8 prev = 0;
	uint8 temp = 0;
	uint8 pressed = 0;

	DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN7, &current);
	_delay_ms(10);
	DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN7, &temp);

	if(current == temp)
	{
		if(current == 1 && prev == 0)
			pressed = 1;
	}

	prev = current;
	return pressed;
}

/* =======================
         Main
   =======================*/

void main(void)
{
	/* Initialization */
	DIO_u8SetPortDirection(DIO_u8PORTC, DIO_u8PORT_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_INPUT); // UP
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN6, DIO_u8PIN_INPUT); // DOWN
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_INPUT); // OK

	CLCD_voidInit();

	/* Variables */
	sint8 digit = 0;
	uint8 digit1 = 0;
	uint8 digit2 = 0;
	uint8 opIndex = 0;
	sint32 result = 0;

	uint8 state = 0;

	uint8 Read_UP, Read_DOWN, Read_OK;

	uint8 ops[4] = {'+','-','*','/'};

	while(1)
	{
		/* Read Buttons */
		Read_UP   = Update_UP();
		Read_DOWN = Update_Down();
		Read_OK   = Update_OK();

		if (Read_UP) {
			if (digit > 9) digit = 0; // Wrap to 9
			else digit++;
		}

		if (Read_DOWN) {
			if (digit == 0) digit = 9; // Wrap to 9
			else digit--;
		}

		if (Read_OK){
			if (state == 255 || state > 5) state = 0;
			else state++;
		}


		/* State Machine */
		switch(state)
		{
		case 0: // DIGIT1
			CLCD_voidGoToXY(0,0);
			CLCD_voidSendNumber(digit);

			CLCD_voidGoToXY(0,1);
			CLCD_voidSendData('^');

			digit1 = digit;
			break;

		case 1: // OPERATION
			if (Read_UP) opIndex++;
			if (Read_DOWN) opIndex--;

			if (opIndex == 255 ) opIndex = 3;
			if (opIndex > 3	) opIndex = 0;

			CLCD_voidGoToXY(1,0);
			CLCD_voidSendData(ops[opIndex]);

			CLCD_voidGoToXY(0,1);
			CLCD_voidSendData(' ');

			CLCD_voidGoToXY(1,1);
			CLCD_voidSendData('^');
			break;

		case 2: // DIGIT2
			CLCD_voidGoToXY(2,0);
			CLCD_voidSendNumber(digit);

			CLCD_voidGoToXY(1,1);
			CLCD_voidSendData(' ');

			CLCD_voidGoToXY(2,1);
			CLCD_voidSendData('^');

			digit2 = digit;
			break;

		case 3: // Equal Sign
			CLCD_voidGoToXY(3,0);
			CLCD_voidSendData('=');

			CLCD_voidGoToXY(2,1);
			CLCD_voidSendData(' ');

			CLCD_voidGoToXY(3,1);
			CLCD_voidSendData('^');
			state++;
			break;

		case 4: // RESULT
			/* Calculate once on entering this state */
			switch(ops[opIndex])
			{
			case '+': result = digit1 + digit2; break;
			case '-': result = digit1 - digit2; break;
			case '*': result = digit1 * digit2; break;

			case '/':
				if(digit2 != 0)
					result = digit1 / digit2;
				else
					result = 0; // error case
				break;
			}
			CLCD_voidGoToXY(4,0);
			CLCD_voidSendNumber(result);

			CLCD_voidGoToXY(3,1);
			CLCD_voidSendData(' ');

			CLCD_voidGoToXY(4,1);
			CLCD_voidSendData('^');
			break;

			case 5: // Reset State
				CLCD_voidSendCmd(1);
				state=0;
				digit = digit1 = digit2 = 0;
				break;


		}
		/* =======================
           Update LCD
           =======================*/

		/* Line 1 *

		   CLCD_voidSendData(ops[opIndex]);
		   CLCD_voidSendNumber(digit2);
		   CLCD_voidSendData('=');

		   if(state == 3)
		   {
			   CLCD_voidSendNumber(result);
		   }

		   /* Line 2 (cursor)
        CLCD_voidGoToXY(0,1);
        CLCD_u8SendString("                ");

        switch(state)
        {
            case 0: CLCD_voidGoToXY(0,1); break;
            case 1: CLCD_voidGoToXY(1,1); break;
            case 2: CLCD_voidGoToXY(2,1); break;
            case 3: CLCD_voidGoToXY(4,1); break;
        }

        CLCD_voidSendData('^');

        /* Save previous state */
		//prevState = state;
	}
}
