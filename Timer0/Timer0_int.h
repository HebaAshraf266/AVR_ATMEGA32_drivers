/*
 *  Name        : Timer0_int.h
 *  Description : This file contains prototypes of timer0 functions
 *  Created on  : Jan 14, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

/*
 * Function   : int Timer0
 * Parameters : Timer0 MODE
 * Return     : void
 */
void Timer0_vidintTimer(uint8 u8_TimerModeCopy);


/*
 * Function   : Select Clock
 * Parameters : Timer Clock
 * Return     : Error state
 */
uint8 TIMER0_u8SelectClock(uint8 u8_TimerClockCopy);


/*
 * Function   : Generate PWM
 * Parameters : Timer Clock
 * Return     : Error state
 */
uint8 TIMER0_u8GeneratePWM(uint8 u8_PWMModeCopy, uint8 u8_PWMStatusCopy);

#endif /* TIMER0_INT_H_ */
