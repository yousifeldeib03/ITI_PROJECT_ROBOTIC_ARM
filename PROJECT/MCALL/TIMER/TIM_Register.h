#ifndef TIM_REGISTER_H_
#define TIM_REGISTER_H_

#include "STD_TYPE.h"

// ==========================
// Timer/Counter Interrupts
// ==========================
#define TIMSK   (*(volatile u8 *)(0x59))   // Timer/Counter Interrupt Mask Register
#define TIFR    (*(volatile u8 *)(0x58))   // Timer/Counter Interrupt Flag Register

// TIMSK bits
#define TOIE0   0   // Timer0 Overflow Interrupt Enable
#define OCIE0   1   // Timer0 Compare Match Interrupt Enable
#define TOIE1   2   // Timer1 Overflow Interrupt Enable
#define OCIE1B  3   // Timer1 Compare Match B Interrupt Enable
#define OCIE1A  4   // Timer1 Compare Match A Interrupt Enable
#define TICIE1  5   // Timer1 Input Capture Interrupt Enable
#define TOIE2   6   // Timer2 Overflow Interrupt Enable
#define OCIE2   7   // Timer2 Compare Match Interrupt Enable

// TIFR bits
#define TOV0    0   // Timer0 Overflow Flag
#define OCF0    1   // Timer0 Compare Match Flag
#define TOV1    2   // Timer1 Overflow Flag
#define OCF1B   3   // Timer1 Compare Match B Flag
#define OCF1A   4   // Timer1 Compare Match A Flag
#define ICF1    5   // Timer1 Input Capture Flag
#define TOV2    6   // Timer2 Overflow Flag
#define OCF2    7   // Timer2 Compare Match Flag

// ==========================
// Timer0
// ==========================
#define TCCR0   (*(volatile u8 *)(0x53))   // Timer/Counter0 Control Register
#define TCNT0   (*(volatile u8 *)(0x52))   // Timer/Counter0
#define OCR0    (*(volatile u8 *)(0x5C))   // Output Compare Register 0

// TCCR0 bits
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

// ==========================
// Timer1 (16-bit)
// ==========================
#define TCCR1A  (*(volatile u8 *)(0x4F))  // Timer/Counter1 Control Register A
#define TCCR1B  (*(volatile u8 *)(0x4E))  // Timer/Counter1 Control Register B

#define TCNT1H  (*(volatile u8 *)(0x4D))
#define TCNT1L  (*(volatile u8 *)(0x4C))
#define TCNT1   (*(volatile u16*)(0x4C))  // 16-bit access

#define OCR1AH  (*(volatile u8 *)(0x4B))
#define OCR1AL  (*(volatile u8 *)(0x4A))
#define OCR1A   (*(volatile u16*)(0x4A))

#define OCR1BH  (*(volatile u8 *)(0x49))
#define OCR1BL  (*(volatile u8 *)(0x48))
#define OCR1B   (*(volatile u16*)(0x48))

#define ICR1H   (*(volatile u8 *)(0x47))
#define ICR1L   (*(volatile u8 *)(0x46))
#define ICR1    (*(volatile u16*)(0x46))

// TCCR1A bits
#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

// TCCR1B bits
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

// ==========================
// Timer2
// ==========================
#define TCCR2   (*(volatile u8 *)(0x45))   // Timer/Counter2 Control Register
#define TCNT2   (*(volatile u8 *)(0x44))   // Timer/Counter2
#define OCR2    (*(volatile u8 *)(0x43))   // Output Compare Register 2

// TCCR2 bits
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7

#endif /* TIM_REGISTER_H_ */
