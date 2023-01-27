/*
 * SevenSegment_src.h
 *
 *  Created on: Jan 1, 2023
 *      Author: user
 */

#include "../../SERV/STD_Types.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "SevenSegment_conf.h"
#include "SevenSegment_private.h"
#include "SevenSegment_int.h"


void SevenSegment_vidint (uint8 u8SevenSegmentIdCopy){

	uint8 SevenSegmentPortList [2] = {UNITS_SEGMENT_PORT,TENS_SEGMENT_PORT};
	DIO_u8SetPORTDir(SevenSegmentPortList[u8SevenSegmentIdCopy],FULL_OUTPUT);

}


uint8 SevenSegment_u8WriteNumber (uint8 u8SevenSegmentIdCopy, uint8 u8NumberCopy){
	uint8 errStatus =E_OK;
	uint8 SevenSegmentPortList [2] = {UNITS_SEGMENT_PORT,TENS_SEGMENT_PORT};

	switch(u8NumberCopy){
		case 0 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_ZERO_Val);   break;
		case 1 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_ONE_Val);    break;
		case 2 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_TWO_Val);    break;
		case 3 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_THREE_Val);  break;
		case 4 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_FOUR_Val);   break;
		case 5 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_FIVE_Val);   break;
		case 6 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_SIX_Val);    break;
		case 7 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_SEVEN_Val);  break;
		case 8 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_EIGHT_Val);  break;
		case 9 : DIO_u8SetPORTVal ( SevenSegmentPortList [u8SevenSegmentIdCopy] ,CATH_NINE_Val);   break;
		default : errStatus =E_NOK;

	}
	return errStatus;
}


uint8 SevenSegment_u8WriteBlank (uint8 u8SevenSegmentIdCopy){

	uint8 errStatus =E_OK;
	uint8 SevenSegmentPortList [2] = {UNITS_SEGMENT_PORT,TENS_SEGMENT_PORT};

	DIO_u8SetPORTVal(SevenSegmentPortList[u8SevenSegmentIdCopy],CATH_BLANK_Val);

return errStatus;
}
