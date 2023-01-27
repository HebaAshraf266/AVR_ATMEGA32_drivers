/*
 *  Name        : Keypad_int.h
 *  Description : This file contains prototypes of Keypad functions
 *  Created on  : Jan 9, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */
#include "../../SERV/STD_Types.h"

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

#define KEYPAD_COLUMN_OUTPUT        1

#define POLLING                     1
#define PERIODIC                    2

/**************************************************************************************************/
/*                                    Functions prototypes                                        */
/**************************************************************************************************/

/*
 * Function   : Keypad intiallization
 * Parameters : void
 * Return     : void
 */

void KeyPad_vidint();

/*
 * Function   : Get pressed key
 * Parameters : void
 * Return     : Pressed key
 */
uint8 KeyPad_u8GetPressed();

#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
