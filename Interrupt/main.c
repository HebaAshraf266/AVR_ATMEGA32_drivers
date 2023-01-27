/*
 * main.c
 *
 *  Created on: Dec 31, 2022
 *      Author: user
 */
#include "../SERV/STD_Types.h"
#include "../SERV/BitMath.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/Interrupt/Interrupt_conf.h"
#include "../MCAL/Interrupt/Interuupt_int.h"
#include"util/delay.h"

/******************************************************************************************/
void Toggle_LED(){
	DIO_u8SetPinVal(PORT_D,PIN_3,TOGGLE);
}

int main(){

	//Button --> Input
	DIO_u8SetPinDir(PORT_D,PIN_2,INPUT);
	// Enable pull up
	DIO_u8SetPinVal(PORT_D,PIN_2,HIGH);

	//Led
	DIO_u8SetPinDir(PORT_D,PIN_3,OUTPUT);

	Interrupt_u8EnableInterrupt( INT0_EXT_INTERRUPT_FALLING_EDGE,Toggle_LED);

	while (1){

	}
}

