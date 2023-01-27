/*
 * LCD_conf.h
 *
 *  Created on: Jan 7, 2023
 *      Author: user
 */

#ifndef HAL_LCD_LCD_CONF_H_
#define HAL_LCD_LCD_CONF_H_

/* -------------------------------------- Initial Configurations -------------------------------------*/

/* Data Bus Lenght */
#define LCD_DB_8WIRES                 1

/* Number of Display Line */
#define LCD_DL_2LINES                 1

/* Display Font */
#define LCD_FONT_5x10                 0            //using 5x7

/* Cursor Control */
#define LCD_CURSOR_ON                 0

/* Blink Control */
#define LCD_BLINK_ON                  0

/* Display Control */
#define LCD_DISPLAY_ON                1

/* Entry Mode */
#define LCD_ENTRY_MODE_AUTO_INC       1
#define LCD_ENTRY_MODE_AUTO_SHIFT     0


/* ------------------------------------- Hardware Connections ---------------------------------------*/
#define LCD_RS_PORT		   PORT_C
#define LCD_RS_PIN         PIN_0

#define LCD_RW_PORT		   PORT_C
#define LCD_RW_PIN         PIN_1

#define LCD_EN_PORT		   PORT_C
#define LCD_EN_PIN         PIN_2

#define LCD_D0_PORT        PORT_A
#define LCD_D0_PIN		   PIN_0

#define LCD_D1_PORT        PORT_A
#define LCD_D1_PIN	       PIN_1

#define LCD_D2_PORT		   PORT_A
#define LCD_D2_PIN         PIN_2

#define LCD_D3_PORT		   PORT_A
#define LCD_D3_PIN         PIN_3

#define LCD_D4_PORT		   PORT_A
#define LCD_D4_PIN         PIN_4

#define LCD_D5_PORT		   PORT_A
#define LCD_D5_PIN         PIN_5

#define LCD_D6_PORT		   PORT_A
#define LCD_D6_PIN         PIN_6

#define LCD_D7_PORT		   PORT_A
#define LCD_D7_PIN         PIN_7


#endif /* HAL_LCD_LCD_CONF_H_ */
