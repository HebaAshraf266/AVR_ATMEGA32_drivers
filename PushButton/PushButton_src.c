/*
 * PushButton_src.c
 *
 *  Created on: Jan 5, 2023
 *      Author: user
 */

#include "../../SERV/STD_Types.h"
#include "../../SERV/BitMath.h"
#include "../../MCAL/DIO/DIO_int.h"
#include"PushButton_int.h"
#include"PushButton_conf.h"

void PushButton_vidinit (uint8 PushButtonIdCopy ){

	uint8 u8PushButtonPortList[3]={BUTTON1_INC_PORT, BUTTON2_DEC_PORT, BUTTON3_RES_PORT}; //PORT_ID
	uint8 u8PushButtonPinList[3] ={BUTTON1_INC_PIN, BUTTON2_DEC_PIN, BUTTON3_RES_PIN};    //PIN_ID
	uint8 u8PushButtonInternalPullUpList[3] = {BUTTON1_INTERNAL_PULLUP,BUTTON2_INTERNAL_PULLUP,BUTTON3_INTERNAL_PULLUP};

	//Set Direction --> As INPUT
	DIO_u8SetPinDir( u8PushButtonPortList[PushButtonIdCopy], u8PushButtonPinList[PushButtonIdCopy], INPUT);

	//Enanble pull up resistor for input pin
	if ( 1==u8PushButtonInternalPullUpList [PushButtonIdCopy] ){
		DIO_u8EnablePinPullUp(u8PushButtonPortList[PushButtonIdCopy], u8PushButtonPinList[PushButtonIdCopy]);
	}
	else{
		//Nothing
	}
}

uint8 PushButton_u8ReadState ( uint8 PushButtonIdCopy ){

	uint8 u8State;

	uint8 u8PushButtonPortList[3]={BUTTON1_INC_PORT, BUTTON2_DEC_PORT, BUTTON3_RES_PORT}; //PORT_ID
	uint8 u8PushButtonPinList[3] ={BUTTON1_INC_PIN, BUTTON2_DEC_PIN, BUTTON3_RES_PIN};    //PIN_ID
	uint8 u8PushButtonPullDownList[3] = {BUTTON1_PULLDOWN,BUTTON2_PULLDOWN,BUTTON3_PULLDOWN};

	DIO_u8GetPinVal(u8PushButtonPortList[PushButtonIdCopy],u8PushButtonPinList[PushButtonIdCopy],&u8State);

	// To unificate read to return true if button is pressed even if it pull up button
	if (u8PushButtonPullDownList[PushButtonIdCopy]==0){
		u8State=!u8State;
	}
	else{
		//Nothing
	}

	return u8State ;
}






