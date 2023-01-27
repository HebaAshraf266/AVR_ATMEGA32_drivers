/*
 * Interrupt_private.h
 *
 *  Created on: Jan 15, 2023
 *      Author: user
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_PRIVATE_H_
#define MCAL_INTERRUPT_INTERRUPT_PRIVATE_H_

/***************************************Interrupt registers addresses*****************************/

/*Global Interrupt Enable */
#define GLOBAL_INTRRUPT_REG 	              *((volatile uint8 *)0x5F)
#define GLOBAL_INTRRUPT_I_BIT                             7

/********************************************* For INT0 ******************************************/
//GICR
#define INT0_INTERRUPT_ENABLE_REGISTER         *((volatile uint8 *)0x5B)
#define INT0_INTERRUPT_ENABLE_BIT        				   6
// MCUCR
#define INT0_INTERRUPT_CONTROL_REG 	           *((volatile uint8 *)0x55)
#define INT0_INTERRUPT_CONTROL_ISC00                       0
#define INT0_INTERRUPT_CONTROL_ISC01                       1

/********************************************** For INT1 *****************************************/
//GICR
#define INT1_INTERRUPT_ENABLE_REGISTER          *((volatile uint8 *)0x5B)
#define INT1_INTERRUPT_ENABLE_BIT        				   7
// MCUCR
#define INT1_INTERRUPT_CONTROL_REG 	            *((volatile uint8 *)0x55)
#define INT1_INTERRUPT_CONTROL_ISC10                       2
#define INT1_INTERRUPT_CONTROL_ISC11                       3

/******************************************** For INT2 *****************************************/
//GICR
#define INT2_INTERRUPT_ENABLE_REGISTER           *((volatile uint8 *)0x5B)
#define INT2_INTERRUPT_ENABLE_BIT        				   5
//MCUCSR
#define INT2_INTERRUPT_CONTROLSTATUS_REG         *((volatile uint8 *)0x54)
#define INT2_INTERRUPT_CONTROLSTATUS_ISC2                  6


/********************************************** For ADC *****************************************/
//ADCSRA
#define ADC_INTERRUPT_ENABLE_REGISTER           *((volatile uint8 *)0x26)
#define ADC_INTERRUPT_ENABLE_BIT        				    3

/********************************************* For Timer0 ***************************************/


/********************************************* For Timer1 ***************************************/


/********************************************* For Timer2 ***************************************/


#endif /* MCAL_INTERRUPT_INTERRUPT_PRIVATE_H_ */
