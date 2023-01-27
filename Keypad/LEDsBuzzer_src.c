/*
 *  Name        : LEDsBuzzer_src.c
 *  Description : This file contains implementation of LED & Buzzer functions
 *  Created on  : Dec 31, 2022
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

/**************************************************************************************************/
/*                                          Includes                                              */
/**************************************************************************************************/
#include "../../SERV/STD_Types.h"
#include "LEDsBuzzer_conf.h"
#include "LEDsBuzzer_int.h"
#include "../../MCAL/DIO/DIO_int.h"


/**************************************************************************************************/
/*                                    Functions Implementation                                    */
/**************************************************************************************************/
void LEDsBuzzer_vidInit (uint8 u8LEDIdCopy){

	uint8 LedPortList[8]= {LED1_PORT,LED2_PORT,LED3_PORT,LED4_PORT,LED5_PORT,LED6_PORT,LED7_PORT,LED8_PORT};
	uint8 LedPinList[8] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN,LED8_PIN};

	DIO_u8SetPinDir ( LedPortList [u8LEDIdCopy] ,LedPinList [u8LEDIdCopy], OUTPUT );
}

uint8 LEDsBuzzer_u8TurnON (uint8 u8LEDIdCopy){
	uint8 errStatus =E_OK;

	uint8 LedPortList[8]= {LED1_PORT,LED2_PORT,LED3_PORT,LED4_PORT,LED5_PORT,LED6_PORT,LED7_PORT,LED8_PORT};
	uint8 LedPinList[8] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN,LED8_PIN};

	DIO_u8SetPinVal(LedPortList[u8LEDIdCopy] ,LedPinList[u8LEDIdCopy], HIGH);

	return errStatus;
}


uint8 LEDsBuzzer_u8TurnOff (uint8 u8LEDIdCopy){
	uint8 errStatus =E_OK;

	uint8 LedPortList[8]= {LED1_PORT,LED2_PORT,LED3_PORT,LED4_PORT,LED5_PORT,LED6_PORT,LED7_PORT,LED8_PORT};
	uint8 LedPinList[8] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN,LED8_PIN};

	DIO_u8SetPinVal (LedPortList[u8LEDIdCopy] ,LedPinList[u8LEDIdCopy], LOW);

	return errStatus;
}


uint8 LEDsBuzzer_u8ToggleState (uint8 u8LEDIdCopy){

	uint8 errStatus =E_OK;
	uint8 LedPortList[8]= {LED1_PORT,LED2_PORT,LED3_PORT,LED4_PORT,LED5_PORT,LED6_PORT,LED7_PORT,LED8_PORT};
	uint8 LedPinList[8] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN,LED8_PIN};

	DIO_u8SetPinVal ( LedPortList [u8LEDIdCopy] ,LedPinList [u8LEDIdCopy], TOGGLE );

	return errStatus;
}


void LEDsBuzzer_u8WriteBinary (uint8 u8NumberCopy){

	DIO_u8SetPORTVal(LEDS_PORT,u8NumberCopy);
}
