/*
 *  Name        : Keypad_conf.h
 *  Description : This file contains hardware connections
 *  Created on  : Jan 9, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#ifndef HAL_KEYPAD_KEYPAD_CONF_H_
#define HAL_KEYPAD_KEYPAD_CONF_H_

/**************************************************************************************************/
/*                                    Hardware connections                                        */
/**************************************************************************************************/

#define KEYPAD_C0_PORT            PORT_D
#define KEYPAD_C0_PIN             PIN_0

#define KEYPAD_C1_PORT            PORT_D
#define KEYPAD_C1_PIN             PIN_1

#define KEYPAD_C2_PORT            PORT_D
#define KEYPAD_C2_PIN             PIN_2

#define KEYPAD_C3_PORT            PORT_D
#define KEYPAD_C3_PIN             PIN_3

#define KEYPAD_R0_PORT            PORT_D
#define KEYPAD_R0_PIN             PIN_4

#define KEYPAD_R1_PORT            PORT_D
#define KEYPAD_R1_PIN             PIN_5

#define KEYPAD_R2_PORT            PORT_D
#define KEYPAD_R2_PIN             PIN_6

#define KEYPAD_R3_PORT            PORT_D
#define KEYPAD_R3_PIN             PIN_7

#define KEYPAD_COL_NO               4
#define KEYPAD_ROW_NO               4

#define NO_KEY_PRESSED              0

#define KEYPAD_MODE               PERIODIC

/**************************************************************************************************/
/*                                    Array of keys                                               */
/**************************************************************************************************/

extern uint8 KEYPAD_au8KeyNum[KEYPAD_ROW_NO][KEYPAD_COL_NO];



#endif /* HAL_KEYPAD_KEYPAD_CONF_H_ */
