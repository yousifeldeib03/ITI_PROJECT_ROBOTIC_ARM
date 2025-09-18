#include "STD_TYPE.h"
#include "DIO_Interface.h"
#include  "DIO_register.h"
#include "Keypad_Interface.h"
#include "Keypad_Config.h"
#include <util/delay.h>

// Row and column arrays
u8 rows[4] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
u8 cols[4] = {KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN, KPD_COL3_PIN};

// Key mapping
u8 keymap[4][4] = KPD_Array;

void Keypad_Init(void){
    for(u8 i=0;i<4;i++){
        // Rows as inputs with pull-up
        DIO_voidSetPinDirection(Keypad_PORT, rows[i], DIO_u8_INPUT);
        DIO_voidSetPinValue(Keypad_PORT, rows[i], DIO_u8_HIGH);

        // Columns as outputs default HIGH
        DIO_voidSetPinDirection(Keypad_PORT, cols[i], DIO_u8_OUTPUT);
        DIO_voidSetPinValue(Keypad_PORT, cols[i], DIO_u8_HIGH);
    }
}

u8 GET_Pressed_Key(void){
    for(u8 c=0;c<4;c++){
        // Drive current column LOW
        DIO_voidSetPinValue(Keypad_PORT, cols[c], DIO_u8_LOW);

        // Scan rows
        for(u8 r=0;r<4;r++){
            if(DIO_u8GetPinValue(Keypad_PORT, rows[r]) == DIO_u8_LOW){
                // Restore column HIGH
                DIO_voidSetPinValue(Keypad_PORT, cols[c], DIO_u8_HIGH);

                // Return pressed key immediately (no waiting for release)
                return keymap[r][c];
            }
        }

        // Restore column HIGH
        DIO_voidSetPinValue(Keypad_PORT, cols[c], DIO_u8_HIGH);
    }
    return NOT_Pressed;
}

char keypad_getkey()
{
    char keymap[4][4] = KPD_Array ;

    for (uint8_t row = 0; row < 4; row++)
    {
        PORTB = (PORTB | 0x0F) & ~(1 << row); // drive one row low
        _delay_us(5);

        for (uint8_t col = 0; col < 4; col++)
        {
            if (!(PINB & (1 << (col + 4))))
            {
                return keymap[row][col]; // return immediately if key pressed
            }
        }
    }
    return 0; // no key pressed
}
