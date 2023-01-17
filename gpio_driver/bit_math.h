/*
 * bit_math.h
 *
 *  Created on: Jan 17, 2023
 *      Author: abdo-
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bit) (((reg) |= (1 << (bit))))
#define CLEAR_BIT(reg, bit) (((reg) &= ~(1 << (bit))))
#define BIT_IS_SET(reg, bit) ((reg) & (1<<bit))
#define BIT_IS_CLEAR(reg, bit) (!((reg) & (1<<bit)))


#endif /* BIT_MATH_H_ */
