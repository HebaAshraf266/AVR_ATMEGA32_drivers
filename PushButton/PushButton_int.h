/*
 * PushButton_int.h
 *
 *  Created on: Jan 5, 2023
 *      Author: user
 */
#include "../../SERV/STD_Types.h"

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_INT_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_INT_H_

#define INC_BUTTON1  0
#define DEC_BUTTON2  1
#define RES_BUTTON3  2


/*
 * Function   : Button initialization
 * Parameters : PushButton ID
 * Return     : void
 */
void PushButton_vidinit (uint8 PushButtonIdCopy);

/*
 * Function   : Detect Button Pressed
 * Parameters : PushButton ID
 * Return     : Error state
 */
uint8 PushButton_u8ReadState(uint8 PushButtonIdCopy);

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_INT_H_ */
