#include "STD_TYPE.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "stepper_config.h"
#include <util/delay.h>

// =============================
// Stepper state variables
// =============================
static u8 step1 = 0;
static u8 step2 = 0;

// =============================
// Full-step sequence (4 steps) -> more torque, no blinking
// =============================
u8 StepperFullStepSeq[4][4] = {
    {1,1,0,0},  // Coil1+2
    {0,1,1,0},  // Coil2+3
    {0,0,1,1},  // Coil3+4
    {1,0,0,1}   // Coil4+1
};

// =============================
// Initialize Stepper
// =============================
void STEPPER_voidInit(u8 motor){
    if(motor == STEPPER1){
        DIO_voidSetPinDirection(STEPPER1_PORT, STEPPER1_COIL_Blue,   DIO_u8_OUTPUT);
        DIO_voidSetPinDirection(STEPPER1_PORT, STEPPER1_COIL_Pink,   DIO_u8_OUTPUT);
        DIO_voidSetPinDirection(STEPPER1_PORT, STEPPER1_COIL_Yellow, DIO_u8_OUTPUT);
        DIO_voidSetPinDirection(STEPPER1_PORT, STEPPER1_COIL_Orange, DIO_u8_OUTPUT);
    }
    else{
        DIO_voidSetPinDirection(STEPPER2_PORT, STEPPER2_COIL_Blue,   DIO_u8_OUTPUT);
        DIO_voidSetPinDirection(STEPPER2_PORT, STEPPER2_COIL_Pink,   DIO_u8_OUTPUT);
        DIO_voidSetPinDirection(STEPPER2_PORT, STEPPER2_COIL_Yellow, DIO_u8_OUTPUT);
        DIO_voidSetPinDirection(STEPPER2_PORT, STEPPER2_COIL_Orange, DIO_u8_OUTPUT);
    }
    STEPPER_voidStop(motor);
}

// =============================
// Stop Stepper
// =============================
void STEPPER_voidStop(u8 motor){
    if(motor == STEPPER1){
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Blue,   DIO_u8_LOW);
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Pink,   DIO_u8_LOW);
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Yellow, DIO_u8_LOW);
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Orange, DIO_u8_LOW);
    } else {
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Blue,   DIO_u8_LOW);
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Pink,   DIO_u8_LOW);
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Yellow, DIO_u8_LOW);
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Orange, DIO_u8_LOW);
    }
}

// =============================
// Rotate one step CW
// =============================
void STEPPER_voidStepCW(u8 motor){
    u8 *seq;
    u8 Blue, Pink, Yellow, Orange;

    if(motor == STEPPER1){
        seq = StepperFullStepSeq[step1];
        Blue=seq[0]; Pink=seq[1]; Yellow=seq[2]; Orange=seq[3];
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Blue, Blue);
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Pink, Pink);
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Yellow, Yellow);
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Orange, Orange);
        step1 = (step1 + 1) % 4;
    } else {
        seq = StepperFullStepSeq[step2];
        Blue=seq[0]; Pink=seq[1]; Yellow=seq[2]; Orange=seq[3];
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Blue, Blue);
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Pink, Pink);
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Yellow, Yellow);
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Orange, Orange);
        step2 = (step2 + 1) % 4;
    }

    _delay_us(STEP_DELAY_US);
}

// =============================
// Rotate one step ACW
// =============================
void STEPPER_voidStepACW(u8 motor){
    u8 *seq;
    u8 Blue, Pink, Yellow, Orange;

    if(motor == STEPPER1){
        seq = StepperFullStepSeq[step1];
        Blue=seq[0]; Pink=seq[1]; Yellow=seq[2]; Orange=seq[3];
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Blue, Blue);
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Pink, Pink);
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Yellow, Yellow);
        DIO_voidSetPinValue(STEPPER1_PORT, STEPPER1_COIL_Orange, Orange);
        if(step1==0) step1=3; else step1--;
    } else {
        seq = StepperFullStepSeq[step2];
        Blue=seq[0]; Pink=seq[1]; Yellow=seq[2]; Orange=seq[3];
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Blue, Blue);
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Pink, Pink);
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Yellow, Yellow);
        DIO_voidSetPinValue(STEPPER2_PORT, STEPPER2_COIL_Orange, Orange);
        if(step2==0) step2=3; else step2--;
    }

    _delay_us(STEP_DELAY_US);
}


