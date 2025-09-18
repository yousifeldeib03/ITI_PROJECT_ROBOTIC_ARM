#ifndef SERVO_CONFIG_H_
#define SERVO_CONFIG_H_

// CPU Frequency
#define F_CPU 8000000UL



// Servo connected to PD5 (OC1A)
#define SERVO_PORT   DIO_u8_PORTD
#define SERVO_PIN    DIO_u8_PIN5

// Servo PWM parameters
#define SERVO_MIN 1000      // 1 ms pulse width -> 0 degrees
#define SERVO_MAX 2000      // 2 ms pulse width -> 180 degrees
#define SERVO_PERIOD 20000  // 20 ms = 50 Hz

#endif /* SERVO_CONFIG_H_ */
