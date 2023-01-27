/*
 * LCD_int.h
 *
 *  Created on: Jan 7, 2023
 *      Author: user
 */
#include "../../SERV/STD_Types.h"

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_


#define	AUTO_DECREAMENT            0
#define AUTO_DECREAMENT_AUTO_SHIFT 1
#define	AUTO_INCREAMENT            2
#define AUTO_INCREAMENT_AUTO_SHIFT 3

/*
 * Function   : LCD init
 * Parameters : void
 * Return     : void
 */
void LCD_vidinit();

/*
 * Function   : LCD clear display
 * Parameters : void
 * Return     : void
 */
void LCD_vidClearDisply();


/*
 * Function   : LCD return home (first address)
 * Parameters : void
 * Return     : void
 */
void LCD_vidReturnHome();


/*
 * Function   : LCD write charcters
 * Parameters : CharCopy
 * Return     : void
 */
void LCD_u8WriteChar(uint8 u8CharCopy);


/*
 * Function   : LCD display frame shift right
 * Parameters : void
 * Return     : void
 */
void LCD_vidDisplayFrameRightShift();


/*
 * Function   : LCD display frame shift left
 * Parameters : void
 * Return     : void
 */
void LCD_vidDisplayFrameLeftShift();



/*
 * Function   : LCD generate custom charcters
 * Parameters : Cahrcters , address in CGRAM
 * Return     : void
 */
void LCD_vidCutomCharcter(uint8 *u8CharPatternCopy,uint8 u8CharAddress);


/*////////////////////////////////////////////////////////////////////*/
/*
 * Function   : LCD send string
 * Parameters : string
 * Return     : void
 */
void LCD_vidSendString(uint8 *u8StringCopy);



/* Function  : Go to specific address
* Parameters : Cahrcters , x , y
* Return     : void
*/
void LCD_vidGoToXY(uint8 u8RowIdCopy,uint8 u8ColumnIdCopy);


/* Function  : Set Entry Mode
* Parameters : Specific entry mode
* Return     : void
*/
void LCD_vidSetEntryMode(uint8 u8LcdEntyModeCopy);


/* Function  : Shift writing position to right
* Parameters : void
* Return     : void
*/
void LCD_vidRightShiftWritingPosistion ();


/* Function  : Shift writing position to left
* Parameters : void
* Return     : void
*/
void LCD_vidLeftShiftWritingPosistion ();


/* Function  : Shift display frame to left
* Parameters : void
* Return     : void
*/
void LCD_vidDisplayFrameLeftShift();


/* Function  : Shift display frame to right
* Parameters : void
* Return     : void
*/
void LCD_vidDisplayFrameRightShift();

void LCD_vidSendInteger(uint16 number);

void LCD_vidSendString(uint8 *u8StringCopy);

void LCD_vidShiftRight(void);

void LCD_vidShiftLeft(void);

#endif /* HAL_LCD_LCD_INT_H_ */
