#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

// =============================
// Basic functions
// =============================
void STEPPER_voidStepCW(u8 motor);
void STEPPER_voidStepACW(u8 motor);
void STEPPER_voidStop(u8 motor);
void STEPPER_voidInit(u8 motor);


// =============================
// Advanced movement
// =============================
void STEPPER_voidRotateSteps(u8 Copy_u8StepperID, u16 Copy_u16Steps, u8 Copy_u8Direction);


#endif /* STEPPER_INTERFACE_H_ */
