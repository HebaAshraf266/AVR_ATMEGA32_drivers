/*
 *  Name        : Keypad_src.c
 *  Description : This file contains implementation of Keypad functions
 *  Created on  : Jan 9, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

/**************************************************************************************************/
/*                                          Includes                                              */
/**************************************************************************************************/
#include "../../SERV/STD_Types.h"
#include "../../SERV/BitMath.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "Keypad_int.h"
#include "Keypad_conf.h"
#include"util/delay.h"


/**************************************************************************************************/
/*                                    Functions Implementation                                    */
/**************************************************************************************************/
void KeyPad_vidint(){
	uint8 i;

	uint8 Local_au8KeyPadColPort[4]={KEYPAD_C0_PORT,KEYPAD_C1_PORT,KEYPAD_C2_PORT,KEYPAD_C3_PORT};
	uint8 Local_au8KeyPadColPin[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};

	uint8 Local_au8KeyPadRowPort[4]={KEYPAD_R0_PORT,KEYPAD_R1_PORT,KEYPAD_R2_PORT,KEYPAD_R3_PORT};
	uint8 Local_au8KeyPadRowPin[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};

	#if KEYPAD_COLUMN_OUTPUT == 1
		for (i=0; i<4; i++){

			//Set DDRx of output pins
			DIO_u8SetPinDir( Local_au8KeyPadColPort[i],Local_au8KeyPadColPin[i],OUTPUT);
		    DIO_u8SetPinVal(Local_au8KeyPadColPort[i],Local_au8KeyPadColPin[i],HIGH);
			//Set DDRx of input pins
			DIO_u8SetPinDir(Local_au8KeyPadRowPort[i],Local_au8KeyPadRowPin[i],INPUT);
			//Enable internal pull up
			DIO_u8SetPinVal(Local_au8KeyPadRowPort[i],Local_au8KeyPadRowPin[i],HIGH);
		}

	#elif KEYPAD_COLUMN_OUTPUT == 0
		for (i=0; i<4; i++){
			DIO_u8SetPinDir(Local_au8KeyPadRowPort[i],Local_au8KeyPadRowPin[i],OUTPUT);
			DIO_u8SetPinVal(Local_au8KeyPadRowPort[i],Local_au8KeyPadRowPin[i],HIGH);

			DIO_u8SetPinDir( Local_au8KeyPadColPort[i],Local_au8KeyPadColPin[i],INPUT);
			//Enable internal pull up
			DIO_u8SetPinVal(Local_au8KeyPadColPort[i],Local_au8KeyPadColPin[i],HIGH);
		}
	#endif
}

uint8 KeyPad_u8GetPressed(){

	uint8 Local_u8ColCounter;
	uint8 Local_u8RowCounter;
	uint8 Local_u8RowState;
	uint8 Local_u8KeyPressed=NO_KEY_PRESSED;

	uint8 Local_au8KeyPadColPort[4]={KEYPAD_C0_PORT,KEYPAD_C1_PORT,KEYPAD_C2_PORT,KEYPAD_C3_PORT};
	uint8 Local_au8KeyPadColPin[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};

	uint8 Local_au8KeyPadRowPort[4]={KEYPAD_R0_PORT,KEYPAD_R1_PORT,KEYPAD_R2_PORT,KEYPAD_R3_PORT};
	uint8 Local_au8KeyPadRowPin[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};

	for (Local_u8ColCounter=0; Local_u8ColCounter<4; Local_u8ColCounter++){
		//Activate COL
		DIO_u8SetPinVal(Local_au8KeyPadColPort[Local_u8ColCounter],Local_au8KeyPadColPin[Local_u8ColCounter],LOW);

		for (Local_u8RowCounter=0; Local_u8RowCounter<4; Local_u8RowCounter++){

			//Get ROW value
			DIO_u8GetPinVal(Local_au8KeyPadRowPort[Local_u8RowCounter],Local_au8KeyPadRowPin[Local_u8RowCounter],&Local_u8RowState);

			//If pressed
			if (0==Local_u8RowState){

				//Action
				Local_u8KeyPressed=KEYPAD_au8KeyNum[Local_u8RowCounter][Local_u8ColCounter];

			#if KEYPAD_MODE==POLLING
				//Wait till pressed is released
				while (0==Local_u8RowState){
					DIO_u8GetPinVal(Local_au8KeyPadRowPort[Local_u8RowCounter],Local_au8KeyPadRowPin[Local_u8RowCounter],&Local_u8RowState);
				}


			#elif KEYPAD_MODE==PERIODIC

				_delay_ms(50);
				DIO_u8GetPinVal(Local_au8KeyPadRowPort[Local_u8RowCounter],Local_au8KeyPadRowPin[Local_u8RowCounter],&Local_u8RowState);
				if(0==Local_u8RowState){
					DIO_u8GetPinVal(Local_au8KeyPadRowPort[Local_u8RowCounter],Local_au8KeyPadRowPin[Local_u8RowCounter],&Local_u8RowState);
				}

			#endif

				_delay_ms(50);
			}
		}
		//Deactivate COL
		DIO_u8SetPinVal(Local_au8KeyPadColPort[Local_u8ColCounter],Local_au8KeyPadColPin[Local_u8ColCounter],HIGH);
	}
	return Local_u8KeyPressed;
}

