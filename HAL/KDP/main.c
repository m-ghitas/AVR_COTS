#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SSD_interface.h"
#include "KPD_interface.h"

#include <util/delay.h>

void main(void)
{

	uint8 value, momentary=0;

	//SSD_u8ON(uint8 SSD_u8ID);
	//SSD_u8OFF(uint8 SSD_u8ID);


	PORT_voidInit();

	SSD_u8ON(SSD_ID_0);

	while(1)
	{
		value = KPD_u8GetPressedKey();

		if(value != 0xff  && value < 10)
		{
			momentary = value;
		}



		SSD_u8OFF(SSD_ID_0);
		SSD_u8setValue(SSD_ID_1, 0);
		SSD_u8ON(SSD_ID_1);
		_delay_ms(5);

		SSD_u8OFF(SSD_ID_1);
		SSD_u8setValue(SSD_ID_0, momentary);
		SSD_u8ON(SSD_ID_0);

		_delay_ms(5);


	}
}
