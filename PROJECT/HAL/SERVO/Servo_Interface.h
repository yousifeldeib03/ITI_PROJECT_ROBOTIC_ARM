#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

void Servo_Init(void);

// Servo 1 on OC1B (PD4)
void Servo1_RotateCW(void);
void Servo1_RotateCCW(void);
void Servo1_Stop(void);

// Servo 2 on OC1A (PD5)
void Servo2_RotateCW(void);
void Servo2_RotateCCW(void);
void Servo2_Stop(void);

#endif /* SERVO_INTERFACE_H_ */
