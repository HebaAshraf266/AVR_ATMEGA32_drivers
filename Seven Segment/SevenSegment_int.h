/*
 * SevenSegment_int.h
 *
 *  Created on: Jan 1, 2023
 *      Author: user
 */
#include "../../SERV/STD_Types.h"

#ifndef HAL_SEVENSEGMENT_SEVENSEGMENT_INT_H_
#define HAL_SEVENSEGMENT_SEVENSEGMENT_INT_H_

#define UNITS_SEGMENT   0
#define TENS_SEGMENT    1

/*
 * Function  : SevenSegment initialization
 * Parameter : SevenSegment Id
 * Return    : void
 */
void SevenSegment_vidint (uint8 SevenSegmentIdCopy);


/*
 * Function  : Write Number on SevenSegment
 * Parameter : SevenSegment Id, number
 * Return    : Error status
 */
uint8 SevenSegment_u8WriteNumber (uint8 u8SevenSegmentIdCopy, uint8 u8NumberCopy);


/*
 * Function  : SevenSegment Blank
 * Parameter : SevenSegment Id, number (0)
 * Return    : Error status
 */
uint8 SevenSegment_u8WriteBlank (uint8 u8SevenSegmentIdCopy);

#endif /* HAL_SEVENSEGMENT_SEVENSEGMENT_INT_H_ */
