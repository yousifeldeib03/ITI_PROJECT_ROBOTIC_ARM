#include "STD_TYPE.h"
#include "BIT_Math.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "stepper_config.h"
#include "stepper_interface.h"
#include "Servo_Interface.h"
#include <util/delay.h>
#include "DIO_interface.h"

int main(void)
{
    // ===== Init hardware =====
    LCD_Init();
    Keypad_Init();
    Servo_Init();
    STEPPER_voidInit(STEPPER1);
    STEPPER_voidInit(STEPPER2);

    Servo1_Stop();
    Servo2_Stop();
    STEPPER_voidStop(STEPPER1);
    STEPPER_voidStop(STEPPER2);

    LCD_svoidSendString("Press 1-8");
    _delay_ms(2000);
    LCD_Command(0x01);

    while(1)
    {
        u8 key = GET_Pressed_Key();

        switch(key)
        {
        case '1':
            LCD_Command(0x01);
            LCD_svoidSendString(" ACW (Right)");
            while(GET_Pressed_Key()=='1') {
                Servo1_RotateCW();
                _delay_ms(5); // small delay for stability
            }
            break;

        case '2':
            LCD_Command(0x01);
            LCD_svoidSendString("CW(LEFT)");
            while(GET_Pressed_Key()=='2') {
                Servo1_RotateCCW();
                _delay_ms(5);
            }
            break;

        case '3':
            LCD_Command(0x01);
            LCD_svoidSendString("Open Gripper");
            while(GET_Pressed_Key()=='3') {
                Servo2_RotateCW();
                _delay_ms(5);
            }
            break;

        case '4':
            LCD_Command(0x01);
            LCD_svoidSendString("close Gripper");
            while(GET_Pressed_Key()=='4') {
                Servo2_RotateCCW();
                _delay_ms(5);
            }
            break;

            case '5':
                LCD_Command(0x01);
                LCD_svoidSendString("BACKWARD");
                while(GET_Pressed_Key()=='5') {
                    STEPPER_voidStepCW(STEPPER1);
                    _delay_ms(2); // small delay to avoid bouncing
                }
                break;

            case '6':
                LCD_Command(0x01);
                LCD_svoidSendString("FORWARD");
                while(GET_Pressed_Key()=='6') {
                    STEPPER_voidStepACW(STEPPER1);
                    _delay_ms(2);
                }
                break;

            case '7':
                LCD_Command(0x01);
                LCD_svoidSendString("DOWN");
                while(GET_Pressed_Key()=='7') {
                    STEPPER_voidStepCW(STEPPER2);
                    _delay_ms(2);
                }
                break;

            case '8':
                LCD_Command(0x01);
                LCD_svoidSendString("UP");
                while(GET_Pressed_Key()=='8') {
                    STEPPER_voidStepACW(STEPPER2);
                    _delay_ms(2);
                }
                break;

            default:
                Servo1_Stop(); Servo2_Stop();
                STEPPER_voidStop(STEPPER1); STEPPER_voidStop(STEPPER2);
                LCD_Command(0x01);
                LCD_svoidSendString("All STOP");
                break;
        }

        _delay_ms(50); // debounce
    }
}
