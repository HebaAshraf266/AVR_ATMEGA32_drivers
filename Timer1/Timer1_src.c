/*
 *  Name        : Timer1_src.c
 *  Description : This file contains functions implementation
 *  Created on  : Jan 25, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#include "Timer1_int.h"
#include "Timer1_conf.h"
#include "Timer1_private.h"

void TIMER1_vidInit(uint8 u8_WGM_Copy,uint8 u8_COM1A_Copy,uint8 u8_COM1B_Copy,uint8 u8_Clk_Copy)
{
	if (u8_COM1A_Copy == TIMER1_COM1A_NORMAL) {
		CLR_BIT(TCCR1A,7);
		CLR_BIT(TCCR1A,6);
	}
	else if (u8_COM1A_Copy == TIMER1_COM1A_TOGGLE) {
		CLR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
	}
	else if (u8_COM1A_Copy == TIMER1_COM1A_CLEAR) {
		SET_BIT(TCCR1A,7);
		CLR_BIT(TCCR1A,6);
	}
	else if (u8_COM1A_Copy == TIMER1_COM1A_SET) {
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
	}
	if (u8_COM1B_Copy == TIMER1_COM1B_NORMAL) {
		CLR_BIT(TCCR1A,5);
		CLR_BIT(TCCR1A,4);
	}
	else if (u8_COM1B_Copy == TIMER1_COM1B_TOGGLE) {
		CLR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
	}
	else if (u8_COM1B_Copy == TIMER1_COM1B_CLEAR) {
		SET_BIT(TCCR1A,5);
		CLR_BIT(TCCR1A,4);
	}
	else if (u8_COM1B_Copy == TIMER1_COM1B_SET) {
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
	}

	//Configuring the mode
	if (u8_WGM_Copy == TIMER1_WGM_NORMAL) {
		CLR_BIT(TCCR1A,0); //WGM10
		CLR_BIT(TCCR1A,1); //WGM11
		CLR_BIT(TCCR1B,3); //WGM12
		CLR_BIT(TCCR1B,4); //WGM13
	}
	else if (u8_WGM_Copy == TIMER1_CTC) {
		CLR_BIT(TCCR1A,0);
		CLR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_PWM_PHASE_CORRECT_8BIT) {
		SET_BIT(TCCR1A,0);
		CLR_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_PWM_PHASE_CORRECT_9BIT) {
		CLR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_PWM_PHASE_CORRECT_10BIT) {
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_WGM_CTC_ICR) {
		CLR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_FPWM_8BIT) {
		SET_BIT(TCCR1A,0);
		CLR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_FPWM_9BIT) {
		CLR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_FPWM_10BIT) {
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_WGM_PWM_PF_ICR) {
		CLR_BIT(TCCR1A,0);
		CLR_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_WGM_PWM_PF_OCR) {
		SET_BIT(TCCR1A,0);
		CLR_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_WGM_PWM_P_ICR) {
		CLR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_WGM_PWM_P_OCR) {
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_WGM_CTC_ICR) {
		CLR_BIT(TCCR1A,0);
		CLR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_WGM_FPWM_ICR) {
		CLR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8_WGM_Copy == TIMER1_WGM_FPWM_OCR)
	{
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,3);
		SET_BIT(TCCR1A,4);
	}
	if (u8_Clk_Copy == TIMER1_CLOCK_NO_CLK ) {
		CLR_BIT(TCCR1B,0);
		CLR_BIT(TCCR1B,1);
		CLR_BIT(TCCR1B,2);
	}
	else if (u8_Clk_Copy == TIMER1_PRESCALLER_1CLK) {
		SET_BIT(TCCR1B,0);
		CLR_BIT(TCCR1B,1);
		CLR_BIT(TCCR1B,2);
	}
	else if (u8_Clk_Copy == TIMER1_PRESCALLER_8CLK) {
		CLR_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		CLR_BIT(TCCR1B,2);
	}
	else if (u8_Clk_Copy == TIMER1_PRESCALLER_64CLK) {
		SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		CLR_BIT(TCCR1B,2);
	}
	else if (u8_Clk_Copy == TIMER1_PRESCALLER_256CLK) {
		CLR_BIT(TCCR1B,0);
		CLR_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
	else if (u8_Clk_Copy == TIMER1_PRESCALLER_1024CLK) {
		SET_BIT(TCCR1B,0);
		CLR_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
	else if (u8_Clk_Copy == TIMER1_External_CLOCK_ON_FALLING_EDGE) {
		CLR_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
	else if (u8_Clk_Copy == TIMER1_External_CLOCK_ON_RISING_EDGE) {
		SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
}

void TIMER1_vidSetOCRB( uint16 u16_OCRBCopy ) {
	OCR1B = u16_OCRBCopy;
}

void TIMER1_vidSetOCRA( uint16 u16_OCRACopy ) {
	OCR1A = u16_OCRACopy;
}


