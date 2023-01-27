/*
 * BitMath.h
 *
 *  Created on: Dec 10, 2022
 *      Author: user
 */

#ifndef BITMATH_H_
#define BITMATH_H_


#define SET_BIT(Reg, BIT_NO)            Reg |= (1<<BIT_NO)
#define CLR_BIT(Reg, BIT_NO)            Reg &= ~(1<<BIT_NO)
#define TOGGLE_BIT(Reg, BIT_NO)         Reg ^= (1<<BIT_NO)
#define GET_BIT(Reg, BIT_NO)           ((Reg >>BIT_NO) & 1)
#define ASSIGN_BIT(Reg,BIT_NO,Value)	Reg = (Reg & (~(1<<BIT_NO)))|(Value<<BIT_NO)


#endif /* BITMATH_H_ */
