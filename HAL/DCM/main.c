#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "DCM_interface.h"
#include <util/delay.h>

#include "PORT_interface.h"


void main(void)
{

	PORT_voidInit();

	while(1)
	{
		DCM_u8RotateCW(0);
		_delay_ms(500);

		DCM_u8RotateCCW(0);
		_delay_ms(1000);

		DCM_u8Stop(0);
		_delay_ms(1000);

	}

}
