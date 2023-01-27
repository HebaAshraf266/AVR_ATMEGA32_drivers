/*
 *  Name        : Timer1_conf.h
 *  Description : This file contains configuration
 *  Created on  : Jan 25, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */
#ifndef MCAL_TIMER1_TIMER1_CONF_H_
#define MCAL_TIMER1_TIMER1_CONF_H_

#define TIMER1_COM1A_NORMAL                        0
#define TIMER1_COM1A_TOGGLE                        1
#define TIMER1_COM1A_CLEAR                         2
#define TIMER1_COM1A_SET                           3

#define TIMER1_COM1B_NORMAL                        0
#define TIMER1_COM1B_TOGGLE                        1
#define TIMER1_COM1B_CLEAR                         2
#define TIMER1_COM1B_SET                           3

/* Wave generation modes */
#define TIMER1_WGM_NORMAL                          0
#define TIMER1_PWM_PHASE_CORRECT_8BIT              1
#define TIMER1_PWM_PHASE_CORRECT_9BIT              2
#define TIMER1_PWM_PHASE_CORRECT_10BIT             3
#define TIMER1_CTC                                 4
#define TIMER1_FPWM_8BIT                           5
#define TIMER1_FPWM_9BIT                           6
#define TIMER1_FPWM_10BIT                          7
#define TIMER1_WGM_PWM_PF_ICR                      8
#define TIMER1_WGM_PWM_PF_OCR                      9
#define TIMER1_WGM_PWM_P_ICR                       10
#define TIMER1_WGM_PWM_P_OCR                       11
#define TIMER1_WGM_CTC_ICR                         12
#define TIMER1_WGM_FPWM_ICR                        14
#define TIMER1_WGM_FPWM_OCR                        15

/* Prescaller */
#define TIMER1_CLOCK_NO_CLK                         0
#define TIMER1_PRESCALLER_1CLK                      1
#define TIMER1_PRESCALLER_8CLK                      2
#define TIMER1_PRESCALLER_64CLK                     3
#define TIMER1_PRESCALLER_256CLK                    4
#define TIMER1_PRESCALLER_1024CLK                   5
#define TIMER1_External_CLOCK_ON_FALLING_EDGE       6
#define TIMER1_External_CLOCK_ON_RISING_EDGE        7

#endif /* MCAL_TIMER1_TIMER1_CONF_H_ */
