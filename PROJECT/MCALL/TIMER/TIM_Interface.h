#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_


#define COMP0_PORT      DIO_u8_PORTB
#define COMP0_PIN       DIO_u8_PIN3

#define COMP1_PORT      DIO_u8_PORTD
#define COMP1A_PIN      DIO_u8_PIN4
#define COMP1B_PIN      DIO_u8_PIN5

#define COMP2_PORT      DIO_u8_PORTD
#define COMP2_PIN       DIO_u8_PIN7


void Timer0_init(void);
void Timer0_voidSet_CompareMatch_Value(u8 u8_local_OCR_Value);
void Timer0_init_CTC(void);
void Timer0_init_PWM(void);
void Timer0_init_FPWM(void);

// void Timer1_Init(void);
// void PWM_Init(void);
// void Timer1_Set_CR(u16 local_u16_copy);
// void Timer1_Set_ChannelA_CompareMatch (u16 local_u16_C
// void Timer1_Init_Fast_PWM(void);
void Timer1_Init_ICR(void);


#define OCIE2       7
#define TOIE2       6
#define TICIE1      5
#define OCIE1A      4
#define OCIE1B      3
#define TOIE1       2
#define OCIE0       1
#define TOIE0       0

#define OCF2        7
#define TOV2        6
#define ICF1        5
#define OCF1A       4
#define OCF1B       3
#define TOV1        2
#define OCF0        1
#define TOV0        0

#define FOC0        7
#define WGM00       6
#define COM01       5
#define COM00       4
#define WGM01       3
#define CS02        2
#define CS01        1
#define CS00        0

#define COM1A1      7
#define COM1A0      6
#define COM1B1      5
#define COM1B0      4
#define FOC1A       3
#define FOC1B       2
#define WGM11       1
#define WGM10       0

#define ICNC1       7
#define ICNC0       6
#define WGM13       4
#define WGM12       3
#define CS12        2
#define CS11        1
#define CS10        0

#define FOC2        7
#define WGM20       6
#define COM21       5
#define COM20       4
#define WGM21       3
#define CS22        2
#define CS21        1
#define CS20        0


#endif
