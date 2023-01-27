/*
 *  Name        : Keypad_conf.c
 *  Description : This file contains array of keys
 *  Created on  : Jan 12, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#include "../../SERV/STD_Types.h"
#include "KeyPad_conf.h"

uint8 KEYPAD_au8KeyNum[KEYPAD_ROW_NO][KEYPAD_COL_NO]=
{
		{
				1, //Row 0 Col 0
				2, //Row 0 Col 1
				3, //Row 0 Col 2
				4  //Row 0 Col 3
		},

		{
				5, //Row 1 Col 0
				6, //Row 1 Col 1
				7, //Row 1 Col 2
				8  //Row 1 Col 3
		},

		{
				9,  //Row 2 Col 0
				10, //Row 2 Col 1
				11, //Row 2 Col 2
				12  //Row 2 Col 3
		},

		{
				13, //Row 3 Col 0
				14, //Row 3 Col 1
				15, //Row 3 Col 2
				16  //Row 3 Col 3
		},

};
