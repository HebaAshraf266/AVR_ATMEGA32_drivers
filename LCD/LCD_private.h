/*
 * LCD_private.h
 *
 *  Created on: Jan 7, 2023
 *      Author: user
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

/* Clear display and Return Home Instructions */
#define CLEAR_DISPLAY_INSTRUCTION                 0x01
#define RETURN_HOME_INSTRUCTION                   0x02


/* Entry Mode Set */
#define ENRTY_MODE_AUTODEC_INSTRUCTION             0x04
#define ENRTY_MODE_AUTOINC_INSTRUCTION             0x06
#define ENRTY_MODE_AUTODEC_DFLEFT_INSTRUCTION      0x05     //////////////
#define ENRTY_MODE_AUTOINC_DFRIGHT_INSTRUCTION     0x07

/* Display ON/OFF Control */
#define DOFF_COFF_BOFF_INSTRUCTION                0x08
#define DON_COFF_BOFF_INSTRUCTION                 0x0C
#define DON_COFF_BON_INSTRUCTION                  0x0D
#define DON_CON_BOFF_INSTRUCTION                  0x0E
#define DON_CON_BON_INSTRUCTION                   0x0F

/* Shift instructions */
#define ADDRESS_COUNTER_DECREAMENT_INSTRUCTION    0x10
#define ADDRESS_COUNTER_INCREAMENT_INSTRUCTION    0x14


/* Display Frame Shift */
#define DISPLAY_FRAME_RIGHT_SHIFT_INSTRUCTION     0x18 ///////////////////////////////
#define DISPLAY_FRAME_LEFT_SHIFT_INSTRUCTION      0x1C


/* Fuction Set */
#define DB4_WIRES_DL_1LINES_FONT_5x7_INSTUCTION   0x20
#define DB4_WIRES_DL_1LINES_FONT_5x10_INSTUCTION  0x24
#define DB4_WIRES_DL_2LINES_FONT_5x7_INSTUCTION   0x28
#define DB4_WIRES_DL_2LINES_FONT_5x10_INSTUCTION  0x2C
#define DB8_WIRES_DL_1LINES_FONT_5x7_INSTUCTION   0x30
#define DB8_WIRES_DL_1LINES_FONT_5x10_INSTUCTION  0x34
#define DB8_WIRES_DL_2LINES_FONT_5x7_INSTUCTION   0x38
#define DB8_WIRES_DL_2LINES_FONT_5x10_INSTUCTION  0x3C

/* Set DDRAM address */
#define POINT_AT_DDRAM_1ST_LINE_INSTRUCTION       0x80
#define POINT_AT_DDRAM_2ND_LINE_INSTRUCTION       0xC0


/* Set CGRAM address */
#define POINT_AT_CGRAM_INSTRUCTION                0x40




#endif /* HAL_LCD_LCD_PRIVATE_H_ */
