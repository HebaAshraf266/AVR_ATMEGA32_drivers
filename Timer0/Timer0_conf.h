/*
 *  Name        : Timer0_conf.h
 *  Description : This file contains configurations
 *  Created on  : Jan 14, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */
#ifndef TIMER0_CONF_H_
#define TIMER0_CONF_H_

/* Timer0 Modes */
#define TIMER0_OVERFLOW_MODE                        0
#define TIMER0_COMPARE_OUTPUT_MODE                  1
#define TIMER0_FAST_PWM_MODE                        2
#define TIMER0_PHASE_CORRECT_PWM_MODE               3

/* CTC MODE */
#define TIMER0_NORMAL_PORT_OPERATION                0
#define TIMER0_CTC_TOGGLE_OC0_ON_COMPARE_MATCH      1
#define TIMER0_CTC_CLEAR_OC0_ON_COMPARE_MATCH       2
#define TIMER0_CTC_SET_OC0_ON_COMPARE_MATCH         3

/* PWM */
#define TIMER0_PWM_NON_INVERTING_MODE               1
#define TIMER0_PWM_INVERTING_MODE                   2


/* Prescaller */
#define TIMER0_PRESCALLER_1CLK                      1
#define TIMER0_PRESCALLER_8CLK                      2
#define TIMER0_PRESCALLER_64CLK                     3
#define TIMER0_PRESCALLER_256CLK                    4
#define TIMER0_PRESCALLER_1024CLK                   5
#define TIMER0_External_CLOCK_ON_FALLING_EDGE       6
#define TIMER0_External_CLOCK_ON_RISING_EDGE        7


/**************************** Registers Addresses Definition *************************
#define FOC0                            7
#define WGM00                           6
#define COM01                           5
#define COM00                           4
#define WGM01                           3
#define CS02                            2
#define CS01                            1
#define CS00                            0
*/

/* Timer/Counter Interrupt Mask Register – TIMSK
#define OCIE0                           1
#define TOIE0                           0
*/

/* Timer/Counter Interrupt Flag Register – TIFR
#define OCF0                            1
#define TOV0                            0
*/

#endif /* TIMER0_CONF_H_ */
