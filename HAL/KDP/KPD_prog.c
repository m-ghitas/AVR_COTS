#include "STD_TYPES.h"
#include "ErrType.h"
#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_prv.h"
#include "KPD_cfg.h"
#include <util/delay.h>

uint8 KPD_u8GetPressedKey(void)
{
    uint8 col, row, pinState;
    uint8 key = KPD_u8NO_PRESSED_KEY_VAL;

    uint8 colPins[COL_NUM] = {
        KPD_u8COL0_PIN,
        KPD_u8COL1_PIN,
        KPD_u8COL2_PIN,
        KPD_u8COL3_PIN
    };

    uint8 rowPins[ROW_NUM] = {
        KPD_u8ROW0_PIN,
        KPD_u8ROW1_PIN,
        KPD_u8ROW2_PIN,
        KPD_u8ROW3_PIN
    };

    uint8 keyMap[ROW_NUM][COL_NUM] = KPD_au8_BUTTON_ARR;

    for(col = 0; col < COL_NUM; col++)
    {
        // Activate column (LOW)
        DIO_u8SetPinValue(KPD_u8COL_PORT, colPins[col], DIO_u8PIN_LOW);

        for(row = 0; row < ROW_NUM; row++)
        {
            DIO_u8ReadPinValue(KPD_u8ROW_PORT, rowPins[row], &pinState);

            if(pinState == DIO_u8PIN_LOW)
            {
                // debounce
                _delay_ms(20);

                DIO_u8ReadPinValue(KPD_u8ROW_PORT, rowPins[row], &pinState);
                if(pinState == DIO_u8PIN_LOW)
                {
                    key = keyMap[row][col];

                    // wait until release
                    while(pinState == DIO_u8PIN_LOW)
                    {
                        DIO_u8ReadPinValue(KPD_u8ROW_PORT, rowPins[row], &pinState);
                    }

                    // deactivate column before return
                    DIO_u8SetPinValue(KPD_u8COL_PORT, colPins[col], DIO_u8PIN_HIGH);

                    return key;
                }
            }
        }

        // Deactivate column
        DIO_u8SetPinValue(KPD_u8COL_PORT, colPins[col], DIO_u8PIN_HIGH);
    }

    return key;
}
