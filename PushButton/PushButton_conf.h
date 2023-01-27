/*
 * PushButton_conf.h
 *
 *  Created on: Jan 5, 2023
 *      Author: user
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_CONF_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_CONF_H_

/* INCREAMENT BUTTON */
#define BUTTON1_INC_PORT       PORT_C
#define BUTTON1_INC_PIN        PIN_0
#define BUTTON1_PULLUP           0
#define BUTTON1_PULLDOWN         0
#define BUTTON1_INTERNAL_PULLUP  1

/* DECREAMENT BUTTON */
#define BUTTON2_DEC_PORT       PORT_C
#define BUTTON2_DEC_PIN        PIN_1
#define BUTTON2_PULLUP           0
#define BUTTON2_PULLDOWN         0
#define BUTTON2_INTERNAL_PULLUP  1

/* RESET BUTTON */
#define BUTTON3_RES_PORT       PORT_C
#define BUTTON3_RES_PIN        PIN_2
#define BUTTON3_PULLUP           0
#define BUTTON3_PULLDOWN         0
#define BUTTON3_INTERNAL_PULLUP  1


#endif /* HAL_PUSHBUTTON_PUSHBUTTON_CONF_H_ */
