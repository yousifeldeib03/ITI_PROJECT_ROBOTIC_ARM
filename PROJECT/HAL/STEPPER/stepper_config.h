#ifndef STEPPER_CONFIG_H_
#define STEPPER_CONFIG_H_

// =============================
// Stepper 1 (Forward/Back) -> PORTA (0–3)
// =============================
#define STEPPER1_PORT         DIO_u8_PORTA
#define STEPPER1_COIL_Blue    DIO_u8_PIN0
#define STEPPER1_COIL_Pink    DIO_u8_PIN1
#define STEPPER1_COIL_Yellow  DIO_u8_PIN2
#define STEPPER1_COIL_Orange  DIO_u8_PIN3

// =============================
// Stepper 2 (Up/Down) -> PORTA (4–7)
// =============================
#define STEPPER2_PORT         DIO_u8_PORTA
#define STEPPER2_COIL_Blue    DIO_u8_PIN4
#define STEPPER2_COIL_Pink    DIO_u8_PIN5
#define STEPPER2_COIL_Yellow  DIO_u8_PIN6
#define STEPPER2_COIL_Orange  DIO_u8_PIN7

// =============================
// Direction
// =============================
#define CW   1
#define ACW  0

// =============================
// Motor parameters
// =============================
// Steps per revolution (28BYJ-48 with gearbox)
#define STEPS_PER_REV   2048
// Delay between steps (speed control)
#define STEP_DELAY_US   2000

// =============================
// Stepper IDs
// =============================
#define STEPPER1   1
#define STEPPER2   2
#define DIO_pin_HIGH 1
#define DIO_pin_LOW  0

// =============================
// Disable coils after movement?
// =============================
#define STEPPER_DISABLE_AFTER_MOVE   0

#endif /* STEPPER_CONFIG_H_ */
