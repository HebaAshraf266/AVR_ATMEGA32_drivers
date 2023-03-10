/*
 *  Name        : Timer0_src.c
 *  Description : This file contains implementation of timer0 functions
 *  Created on  : Jan 14, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#include "../SERV/STD_Types.h"
#include "../SERV/BitMath.h"
#include "Timer0_int.h"
#include "Timer0_conf.h"
#include "Timer0_private.h"
#include "../Interrupt/Interuupt_int.h"

void TIMER0_vidintTimer(uint8 u8_TimerModeCopy){

	switch (u8_TimerModeCopy){
		case TIMER0_OVERFLOW_MODE:
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CONTROL_MODE_WGM00);
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CONTROL_MODE_WGM01);
			break;

		case TIMER0_COMPARE_OUTPUT_MODE:
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CONTROL_MODE_WGM00);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CONTROL_MODE_WGM01);
			break;

		case TIMER0_FAST_PWM_MODE:
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CONTROL_MODE_WGM00);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CONTROL_MODE_WGM01);
			break;

		case TIMER0_PHASE_CORRECT_PWM_MODE:
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CONTROL_MODE_WGM00);
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CONTROL_MODE_WGM01);
			break;
	}

}

uint8 TIMER0_u8SelectClock(uint8 u8_TimerClockCopy){

	uint8 ErrorState=0;
	Interrupt_u8EnableGlobalRegister();

	switch (u8_TimerClockCopy)
	{
		case TIMER0_PRESCALLER_1CLK:
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS00);
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS01);
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS02);
			break;

		case TIMER0_PRESCALLER_8CLK:
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS00);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS01);
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS02);
			break;

		case TIMER0_PRESCALLER_64CLK:
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS00);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS01);
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS02);
			break;

		case TIMER0_PRESCALLER_256CLK:
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS00);
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS01);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS02);
			break;

		case TIMER0_PRESCALLER_1024CLK:
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS00);
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS01);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS02);
			break;

		case TIMER0_External_CLOCK_ON_FALLING_EDGE:
			CLR_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS00);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS01);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS02);
			break;

		case TIMER0_External_CLOCK_ON_RISING_EDGE:
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS00);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS01);
			SET_BIT(TIMER0_CONTROL_MODE_REGISETER,TIMER0_CLOCK_SELECT_CS02);
			break;

		default:
			ErrorState=1;
			break;
	}
	return ErrorState;
}


uint8 TIMER0_u8GeneratePWM(uint8 u8_PWMModeCopy, uint8 u8_PWMStatusCopy){

	uint8 ErrorState=0;
	switch (u8_PWMModeCopy){

		case TIMER0_COMPARE_OUTPUT_MODE:
			switch (u8_PWMStatusCopy){

			case TIMER0_NORMAL_PORT_OPERATION:
				CLR_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM00);
				CLR_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM01);
				break;

			case TIMER0_CTC_TOGGLE_OC0_ON_COMPARE_MATCH:
				SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM00);
				CLR_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM01);
				break;

			case TIMER0_CTC_CLEAR_OC0_ON_COMPARE_MATCH:
				CLR_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM00);
				SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM01);
				break;

			case TIMER0_CTC_SET_OC0_ON_COMPARE_MATCH:
				SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM00);
				SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM01);
				break;

			default:
				ErrorState=1;
				break;
			}
			break;

			case TIMER0_FAST_PWM_MODE:
				switch(u8_PWMStatusCopy){
					case TIMER0_PWM_NON_INVERTING_MODE:
						CLR_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM00);
						SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM01);
						break;

					case TIMER0_PWM_NON_INVERTING_MODE:
						SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM00);
						SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM01);
						break;

					default:
						ErrorState=1;
						break;
	             }
				break;

				case TIMER0_PHASE_CORRECT_PWM_MODE:
					switch(u8_PWMStatusCopy){
						case TIMER0_PWM_NON_INVERTING_MODE:
							CLR_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM00);
							SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM01);
							break;

						case TIMER0_PWM_NON_INVERTING_MODE:
							SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM00);
							SET_BIT(TIMER0_COMPARE_OUTPUT_MODE,TIMER0_COMPARE_OUTPUT_MODE_COM01);
							break;

						default:
							ErrorState=1;
							break;
		             }
				break;
	}
	return ErrorState;
}

uint8 TIMER0_u8WriteValueInReg(uint8 u8RegNameCopy, uint8 u8Value){

	uint8 ErrorState=0;
	switch (u8RegNameCopy){
		case TCNT0:
			TCNT0=u8Value;
			break;

		case OCR0:
			OCR0=u8Value;
			break;

		default:
			ErrorState=1;
			break;
	}
return ErrorState;
}
