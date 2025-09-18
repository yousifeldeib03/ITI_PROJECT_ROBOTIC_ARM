/*
 * Keypad_Config.h
 *
 *  Created on: Aug 25, 2025
 *      Author: alhof
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define Keypad_PORT                 DIO_u8_PORTB

#define KPD_ROW0_PIN				DIO_u8_PIN0
#define KPD_ROW1_PIN				DIO_u8_PIN1
#define KPD_ROW2_PIN                DIO_u8_PIN2
#define KPD_ROW3_PIN                DIO_u8_PIN3

#define KPD_COL0_PIN				DIO_u8_PIN4
#define KPD_COL1_PIN				DIO_u8_PIN5
#define KPD_COL2_PIN                DIO_u8_PIN6
#define KPD_COL3_PIN                DIO_u8_PIN7

#define KPD_Array {{'1','2','3','A'},\
				   {'4','5','6','B'},\
				   {'7','8','9','C'},\
				   {'*','0','#','D'}}


#endif /* KEYPAD_CONFIG_H_ */
