#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"

#include "GIE_Register.h"
#include "GIE_Interface.h"




#include "TIM_Register.h"
#include "TIM_Interface.h"


void Timer0_init(){
    Global_Interrupt_Enable();

    CLR_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);

    CLR_BIT(TCCR0, CS02);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS00);
    
    SET_BIT(TIMSK, TOIE0);
}


void Timer0_init_CTC(){
	Global_Interrupt_Enable();
    CLR_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);

    CLR_BIT(TCCR0, CS02);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS00);

    Timer0_voidSet_CompareMatch_Value(250);
    SET_BIT(TIMSK, OCIE0);
}


void Timer0_voidSet_CompareMatch_Value(u8 u8_local_OCR_Value){
    OCR0 = u8_local_OCR_Value;
}


void Timer0_init_PWM(void) {
    SET_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);

    CLR_BIT(TCCR0, CS02);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS00);

    SET_BIT(TCCR0, COM01);
    SET_BIT(TCCR0, COM00);

    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN3,1);
}


void Timer0_init_FPWM(void){
    SET_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);

    CLR_BIT(TCCR0, CS02);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS00);

    SET_BIT(TCCR0, COM01);
    SET_BIT(TCCR0, COM00);
}


void Timer1_Init_ICR(void){
    Global_Interrupt_Enable();

    // Clear Timer1 control registers
    TCCR1A = 0;
    TCCR1B = 0;

    // Set Waveform Generation Mode to 14 (Fast PWM with ICR1 as TOP)
    SET_BIT(TCCR1A, WGM11);
    SET_BIT(TCCR1B, WGM12);
    SET_BIT(TCCR1B, WGM13);

    // Set prescaler to 8
    SET_BIT(TCCR1B, CS11);

    // Set default ICR1 value (will be overridden by Servo_Init)
    ICR1 = 2000;

    // Set default OCR values
    OCR1A = 1000;
    OCR1B = 1000;
}
