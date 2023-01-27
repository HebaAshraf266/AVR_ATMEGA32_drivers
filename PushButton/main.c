#include "../SERV/STD_Types.h"
#include "../SERV/BitMath.h"
#include "../MCAL/DIO/DIO_int.h"
#include"../HAL/PushButton/PushButton_int.h"
#include "../HAL/SevenSegment/SevenSegment_int.h"
#include"util/delay.h"

void main(void){

	PushButton_vidinit(INC_BUTTON1);
	PushButton_vidinit(DEC_BUTTON2);
	PushButton_vidinit(RES_BUTTON3);

	SevenSegment_vidint(UNITS_SEGMENT);
	SevenSegment_vidint(TENS_SEGMENT);
	SevenSegment_u8WriteNumber(UNITS_SEGMENT,0);
	SevenSegment_u8WriteNumber(TENS_SEGMENT,0);

	sint8 UnitsSegmentCounter=0;
	sint8 TensSegmentCounter=0;

	while (1){
		SevenSegment_u8WriteNumber(UNITS_SEGMENT,UnitsSegmentCounter);
		SevenSegment_u8WriteNumber(TENS_SEGMENT,TensSegmentCounter);

		if (1==PushButton_u8ReadState(INC_BUTTON1)){
			_delay_ms(50);

			if (1==PushButton_u8ReadState(INC_BUTTON1)){

				UnitsSegmentCounter++;
				if ( UnitsSegmentCounter==10){
					 UnitsSegmentCounter=0;
					 TensSegmentCounter++;

					 if ( TensSegmentCounter==10){
						 TensSegmentCounter=0;
					 }
				}
				while (1==PushButton_u8ReadState(INC_BUTTON1));
			}
		}

		else if  (1==PushButton_u8ReadState(DEC_BUTTON2)){

			_delay_ms(50);
			if (1==PushButton_u8ReadState(DEC_BUTTON2)){

				UnitsSegmentCounter--;
				if ( UnitsSegmentCounter == (sint8)-1 ){

					 UnitsSegmentCounter=9;
					 TensSegmentCounter--;
					 if ( TensSegmentCounter==(sint8)-1 ){
						 TensSegmentCounter=9;
					 }
				}
				while (1==PushButton_u8ReadState(DEC_BUTTON2));
			}

		}
		else if  (1==PushButton_u8ReadState(RES_BUTTON3)){

			_delay_ms(50);

			if (1==PushButton_u8ReadState(RES_BUTTON3)){
				UnitsSegmentCounter=0;
				TensSegmentCounter=0;

				while (1==PushButton_u8ReadState(RES_BUTTON3));
			}

		}
	}
}
