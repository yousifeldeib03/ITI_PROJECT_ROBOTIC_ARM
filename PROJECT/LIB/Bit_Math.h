/*
 * Bit_Math.h
 *
 *  Created on: Aug 25, 2025
 *      Author: me138
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR,BITNO) (VAR) |= (1<<(BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &=~ (1<<(BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1<<(BITNO))
#define GET_BIT(reg,bit)	((reg >> bit) & 1)
#endif
