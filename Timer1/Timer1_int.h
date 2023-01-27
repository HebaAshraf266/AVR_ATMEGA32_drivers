/*
 *  Name        : Timer1_int.h
 *  Description : This file contains protoypes
 *  Created on  : Jan 25, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#ifndef TIMER1_INT_H_
#define TIMER1_INT_H_

/*
 * Function   : Timer1 initalization
 * Parameters :
 * Return     : void
 */
void TIMER1_vidInit(uint8 u8_WGM_Copy,uint8 u8_COM1A_Copy,uint8 u8_COM1B_Copy,uint8 u8_Clk_Copy);

/*
 * Function   : Timer1 Set OCRA register
 * Parameters : OCRA Copy
 * Return     : void
 */
void TIMER1_vidSetOCRA(uint16 u16_OCRACopy);

/*
 * Function   : Timer1 Set OCRB register
 * Parameters : OCRB Copy
 * Return     : void
 */
void TIMER1_vidSetOCRB(uint16 u16_OCRBCopy);


/*
 * Function   : Timer1 Set TCNT register
 * Parameters :
 * Return     : void
 */
void TIMER1_vidSetTCNT(uint16);


#endif /* TIMER1_INT_H_ */
