/*
 * main.c
 *
 *  Created on: Dec 31, 2022
 *      Author: user
 */
#include "../SERV/STD_Types.h"
#include "../SERV/BitMath.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LED_Buzzer/LEDsBuzzer_int.h"
#include "../HAL/KeyPad/KeyPad_int.h"

#include"util/delay.h"
#include"avr/io.h"


void main(){

	uint8 Key;

	LEDsBuzzer_vidInit (LED1);
	LEDsBuzzer_vidInit (LED2);
	LEDsBuzzer_vidInit (LED3);
	LEDsBuzzer_vidInit (LED4);
	LEDsBuzzer_vidInit (LED5);
	KeyPad_vidint();

	//Intial state
	LEDsBuzzer_u8TurnOff(LED1);
	LEDsBuzzer_u8TurnOff(LED2);
	LEDsBuzzer_u8TurnOff(LED3);
	LEDsBuzzer_u8TurnOff(LED4);
	LEDsBuzzer_u8TurnOff(LED5);


	while(1)
	{
		//LEDsBuzzer_u8TurnON(LED4);
		Key = KeyPad_u8GetPressed();
		LEDsBuzzer_u8WriteBinary(Key);
	}

}
