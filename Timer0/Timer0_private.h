/*
 *  Name        : Timer0_private.h
 *  Description : This file contains registers of timer0
 *  Created on  : Jan 14, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

/************************************************************************************************/
/*                                           TCCR0                                              */
/************************************************************************************************/
#define TIMER0_CONTROL_MODE_REGISETER          *( (volatile uint8*) 0x53)
#define TIMER0_CONTROL_MODE_WGM00                         6
#define TIMER0_CONTROL_MODE_WGM01                         3

//FAST PWM, PHASE, CTC
#define TIMER0_COMPARE_OUTPUT_MODE_COM00                  4
#define TIMER0_COMPARE_OUTPUT_MODE_COM01			            5

//Prescaller
#define TIMER0_CLOCK_SELECT_CS00                          0
#define TIMER0_CLOCK_SELECT_CS01                          1
#define TIMER0_CLOCK_SELECT_CS02                          2

/************************************************************************************************/
/*                                            TCNT0                                             */
/************************************************************************************************/
#define TCNT0                                     TIMER0_COUNTER_REGISTER
#define TIMER0_COUNTER_REGISTER                  *( (volatile uint8*) 0x52)

/************************************************************************************************/
/*                                            OCR0                                              */
/************************************************************************************************/
#define OCR0                                      TIMER0_OUTPUT_COMPARE_REGISTER
#define TIMER0_OUTPUT_COMPARE_REGISTER             *( (volatile uint8*) 0x5C)

/************************************************************************************************/
/*                                         TIMSK--> Interrupt                                   */
/************************************************************************************************/

#define TIMER0_COMPARE_MATCH_INTERRUPT_ENABLE       *( (volatile uint8*) 0x59)

//OVF
#define TIMER0_COMPARE_MATCH_INTERRUPT_TOIE0                0

//CTC
#define TIMER0_COMPARE_MATCH_INTERRUPT_OCIE0                1

#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
