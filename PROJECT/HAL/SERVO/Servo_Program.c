#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "Servo_Interface.h"
#include "DIO_Interface.h"
#include "TIM_Interface.h"
#include "TIM_Register.h"
#include "DIO_Register.h"

void Servo_Init(void)
{
    // Set PD4 (OC1B) and PD5 (OC1A) as outputs using DIO driver
    DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN4, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN5, DIO_u8_OUTPUT);

    // Initialize Timer1 for Fast PWM mode 14 (ICR1 as TOP)
    Timer1_Init_ICR();

    // Configure additional Timer1 settings for servo control
    // Fast PWM, mode 14 (ICR1 as TOP), non-inverting
    SET_BIT(TCCR1A, COM1A1);  // Non-inverting mode for OC1A
    SET_BIT(TCCR1A, COM1B1);  // Non-inverting mode for OC1B
    CLR_BIT(TCCR1A, COM1A0);
    CLR_BIT(TCCR1A, COM1B0);

    SET_BIT(TCCR1A, WGM11);   // Mode 14: WGM13:0 = 1110
    SET_BIT(TCCR1B, WGM13);
    SET_BIT(TCCR1B, WGM12);

    // Set prescaler to 8
    CLR_BIT(TCCR1B, CS12);
    SET_BIT(TCCR1B, CS11);
    CLR_BIT(TCCR1B, CS10);

    // Set period for 20ms (50Hz) with 8MHz clock and prescaler 8
    // ICR1 = (F_CPU / (prescaler * frequency)) - 1
    // ICR1 = (8000000 / (8 * 50)) - 1 = 20000 - 1 = 19999
    ICR1 = 19999;
}

// Servo 1 (PD4 → OC1B)
void Servo1_RotateCW(void)   { OCR1B = 2000; }  // ~2 ms pulse (180 degrees)
void Servo1_RotateCCW(void)  { OCR1B = 1000; }  // ~1 ms pulse (0 degrees)
void Servo1_Stop(void)       { OCR1B = 1500; }  // ~1.5 ms pulse (90 degrees)

// Servo 2 (PD5 → OC1A)
void Servo2_RotateCW(void)   { OCR1A = 2000; }
void Servo2_RotateCCW(void)  { OCR1A = 1000; }
void Servo2_Stop(void)       { OCR1A = 1500; }
