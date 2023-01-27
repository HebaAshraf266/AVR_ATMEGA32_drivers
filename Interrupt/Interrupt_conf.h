/*
 * Interrupt_conf.h
 *
 *  Created on: Jan 15, 2023
 *      Author: user
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_CONF_H_
#define MCAL_INTERRUPT_INTERRUPT_CONF_H_

/* Select Interrupt Number
#define EXT_INTERRUPT_INT0                     0
#define EXT_INTERRUPT_INT1                     1
#define EXT_INTERRUPT_INT2                     2
#define ADC_INTERRUPT                          3
#define TIMER0_OVF_INTERRUPT                   4
#define TIMER0_COMP_INTERRUP                   5
*/

/* Select Interrupts Source */
typedef enum {
	INT0_EXT_INTERRUPT_LOW_LEVEL=0,
	INT0_EXT_INTERRUPT_FALLING_EDGE,
	INT0_EXT_INTERRUPT_RISING_EDGE,
	INT0_EXT_INTERRUPT_ANY_LOGICAL_CHANGE,
	INT1_EXT_INTERRUPT_LOW_LEVEL,
	INT1_EXT_INTERRUPT_FALLING_EDGE,
	INT1_EXT_INTERRUPT_RISING_EDGE,
	INT1_EXT_INTERRUPT_ANY_LOGICAL_CHANGE,
	INT2_EXT_INTERRUPT_FALLING_EDGE,
	INT2_EXT_INTERRUPT_RISING_EDGE,
	ADC_COMPLETE_CONVERSION

}t_InterruptSource;


#endif /* MCAL_INTERRUPT_INTERRUPT_CONF_H_ */
