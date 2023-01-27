#include "../SERV/STD_Types.h"
#include "../SERV/BitMath.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/SevenSegment/SevenSegment_int.h"
#include"util/delay.h"

// Counter 0-99 in seven segment
void main(void){
	SevenSegment_vidint(UNITS_SEGMENT);
	SevenSegment_vidint(TENS_SEGMENT);
	SevenSegment_u8WriteNumber(UNITS_SEGMENT,0);
	SevenSegment_u8WriteNumber(TENS_SEGMENT,0);

	uint8 UnitsSegmentCounter=0;
	uint8 TensSegmentCounter=0;

	while (1){
		SevenSegment_u8WriteNumber(UNITS_SEGMENT,UnitsSegmentCounter);
		SevenSegment_u8WriteNumber(TENS_SEGMENT,TensSegmentCounter);

		 UnitsSegmentCounter++;

		if ( UnitsSegmentCounter==10){
			 UnitsSegmentCounter=0;
			 TensSegmentCounter++;

			 if ( TensSegmentCounter==10){
				 TensSegmentCounter=0;
			 }
		}
		_delay_ms(500);

	}
}
