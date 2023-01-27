/*
 *  Name        : Interrupt_src.c
 *  Description : This file contains implementation of Interrupt functions
 *  Created on  : Jan 15, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */



/**************************************************************************************************/
/*                                            Includes                                           */
/**************************************************************************************************/
#include "../../SERV/STD_Types.h"
#include "../../SERV/BitMath.h"
#include "Interrupt_conf.h"
#include "Interuupt_int.h"
#include"Interrupt_private.h"

/***************************************External Interrupt**************************************/
void (*ptrINT0)(void);
void __vector_1(void) __attribute__((signal, used, externally_visible));
void __vector_1(void){

    	ptrINT0();
}

void (*ptrINT1)(void);
void __vector_2(void) __attribute__((signal, used, externally_visible));
void __vector_2(void){

    	ptrINT1();
}
void (*ptrINT2)(void);
void __vector_3(void) __attribute__((signal, used, externally_visible));
void __vector_3(void){

    	ptrINT2();
}


/********************************************** ADC *******************************************/
void (*ptrADC)(void);
void __vector_16(void) __attribute__((signal, used, externally_visible));
void __vector_16(void){

    	ptrADC();
}

/*****************************************Timer0*************************************************/
void (*ptrTimer0_OVF)(void);
void __vector_11(void) __attribute__((signal, used, externally_visible));
void __vector_11(void){

	  ptrTimer0_OVF();
}


void (*ptrTimer0_COMP)(void);
void __vector_10(void) __attribute__((signal, used, externally_visible));
void __vector_10(void){

	 ptrTimer0_COMP();
}

/*******************************************Timer1*********************************************/
void (*ptrTimer1_CAPT)(void);
void __vector_6(void) __attribute__((signal, used, externally_visible));
void __vector_6(void){

	 ptrTimer1_CAPT();
}

void (*ptrTimer1_COMPB)(void);
void __vector_7(void) __attribute__((signal, used, externally_visible));
void __vector_7(void){

	 ptrTimer1_COMPB();
}

void (*ptrTimer1_COMPA)(void);
void __vector_8(void) __attribute__((signal, used, externally_visible));
void __vector_8(void){

	 ptrTimer1_COMPA();
}


void (*ptrTimer1_OVF)(void);
void __vector_9(void) __attribute__((signal, used, externally_visible));
void __vector_9(void){

	  ptrTimer1_OVF();
}


/********************************************Timer2*********************************************/
void (*ptrTimer2_COMP)(void);
void __vector_4(void) __attribute__((signal, used, externally_visible));
void __vector_4(void){

	 ptrTimer2_COMP();
}

void (*ptrTimer2_OVF)(void);
void __vector_5(void) __attribute__((signal, used, externally_visible));
void __vector_5(void){

	  ptrTimer2_OVF();
}


/**************************************************************************************************/
/*                                    Functions implementation                                    */
/**************************************************************************************************/
void Interrupt_u8EnableGlobalRegister(){

	SET_BIT(GLOBAL_INTRRUPT_REG,GLOBAL_INTRRUPT_I_BIT);
}

void Interrupt_u8DisableGlobalRegister(){

	CLR_BIT(GLOBAL_INTRRUPT_REG,GLOBAL_INTRRUPT_I_BIT);
}

uint8 Interrupt_u8EnableInterrupt(t_InterruptSource u8INT_NumCopy, void (*PtrToHandler)(void)){

	uint8 ErrorState=1;
	Interrupt_u8EnableGlobalRegister();
	switch (u8INT_NumCopy){

		case INT0_EXT_INTERRUPT_LOW_LEVEL:
			SET_BIT(INT0_INTERRUPT_ENABLE_REGISTER, INT0_INTERRUPT_ENABLE_BIT);
			CLR_BIT(INT0_INTERRUPT_CONTROL_REG,INT0_INTERRUPT_CONTROL_ISC00);
			CLR_BIT(INT0_INTERRUPT_CONTROL_REG,INT0_INTERRUPT_CONTROL_ISC01);
			ptrINT0=PtrToHandler;
			break;

		case INT0_EXT_INTERRUPT_ANY_LOGICAL_CHANGE:
			SET_BIT(INT0_INTERRUPT_ENABLE_REGISTER, INT0_INTERRUPT_ENABLE_BIT);
			SET_BIT(INT0_INTERRUPT_CONTROL_REG,INT0_INTERRUPT_CONTROL_ISC00);
			CLR_BIT(INT0_INTERRUPT_CONTROL_REG,INT0_INTERRUPT_CONTROL_ISC01);
			ptrINT0=PtrToHandler;
			break;


		case INT0_EXT_INTERRUPT_FALLING_EDGE:
			SET_BIT(INT0_INTERRUPT_ENABLE_REGISTER, INT0_INTERRUPT_ENABLE_BIT);
			CLR_BIT(INT0_INTERRUPT_CONTROL_REG,INT0_INTERRUPT_CONTROL_ISC00);
			SET_BIT(INT0_INTERRUPT_CONTROL_REG,INT0_INTERRUPT_CONTROL_ISC01);
			ptrINT0=PtrToHandler;
			break;

		case INT0_EXT_INTERRUPT_RISING_EDGE:
			SET_BIT(INT0_INTERRUPT_ENABLE_REGISTER, INT0_INTERRUPT_ENABLE_BIT);
			SET_BIT(INT0_INTERRUPT_CONTROL_REG,INT0_INTERRUPT_CONTROL_ISC00);
			SET_BIT(INT0_INTERRUPT_CONTROL_REG,INT0_INTERRUPT_CONTROL_ISC01);
			ptrINT0=PtrToHandler;
			break;


		case INT1_EXT_INTERRUPT_LOW_LEVEL:
			SET_BIT(INT1_INTERRUPT_ENABLE_REGISTER, INT1_INTERRUPT_ENABLE_BIT);
			CLR_BIT(INT1_INTERRUPT_CONTROL_REG,INT1_INTERRUPT_CONTROL_ISC10);
			CLR_BIT(INT1_INTERRUPT_CONTROL_REG,INT1_INTERRUPT_CONTROL_ISC11);
			ptrINT1=PtrToHandler;
			break;

		case INT1_EXT_INTERRUPT_ANY_LOGICAL_CHANGE:
			SET_BIT(INT1_INTERRUPT_ENABLE_REGISTER, INT1_INTERRUPT_ENABLE_BIT);
			SET_BIT(INT1_INTERRUPT_CONTROL_REG,INT1_INTERRUPT_CONTROL_ISC10);
			CLR_BIT(INT1_INTERRUPT_CONTROL_REG,INT1_INTERRUPT_CONTROL_ISC11);
			ptrINT1=PtrToHandler;
			break;


		case INT1_EXT_INTERRUPT_FALLING_EDGE:
			SET_BIT(INT1_INTERRUPT_ENABLE_REGISTER, INT1_INTERRUPT_ENABLE_BIT);
			CLR_BIT(INT1_INTERRUPT_CONTROL_REG,INT1_INTERRUPT_CONTROL_ISC10);
			SET_BIT(INT1_INTERRUPT_CONTROL_REG,INT1_INTERRUPT_CONTROL_ISC11);
			ptrINT1=PtrToHandler;
			break;

		case INT1_EXT_INTERRUPT_RISING_EDGE:
			SET_BIT(INT1_INTERRUPT_ENABLE_REGISTER, INT1_INTERRUPT_ENABLE_BIT);
			SET_BIT(INT1_INTERRUPT_CONTROL_REG,INT1_INTERRUPT_CONTROL_ISC10);
			SET_BIT(INT1_INTERRUPT_CONTROL_REG,INT1_INTERRUPT_CONTROL_ISC10);
			ptrINT1=PtrToHandler;
			break;


		case INT2_EXT_INTERRUPT_FALLING_EDGE:
			SET_BIT(INT2_INTERRUPT_ENABLE_REGISTER, INT2_INTERRUPT_ENABLE_BIT);
			CLR_BIT(INT2_INTERRUPT_CONTROLSTATUS_REG,INT2_INTERRUPT_CONTROLSTATUS_ISC2);
			ptrINT2=PtrToHandler;
			break;

		case INT2_EXT_INTERRUPT_RISING_EDGE:
			SET_BIT(INT2_INTERRUPT_ENABLE_REGISTER, INT2_INTERRUPT_ENABLE_BIT);
			SET_BIT(INT2_INTERRUPT_CONTROLSTATUS_REG,INT2_INTERRUPT_CONTROLSTATUS_ISC2);
			ptrINT2=PtrToHandler;
			break;

		case ADC_COMPLETE_CONVERSION:
			SET_BIT(INT2_INTERRUPT_ENABLE_REGISTER, INT2_INTERRUPT_ENABLE_BIT);
			SET_BIT(INT2_INTERRUPT_CONTROLSTATUS_REG,INT2_INTERRUPT_CONTROLSTATUS_ISC2);
			ptrADC=PtrToHandler;
			break;

		default:
			ErrorState=0;
			break;
	}
return ErrorState;
}


uint8 Interrupt_u8DisableInterrupt(t_InterruptSource u8INT_NumCopy){

	uint8 ErrorState=1;
	switch (u8INT_NumCopy){

		case INT0_EXT_INTERRUPT_LOW_LEVEL:
			CLR_BIT(INT0_INTERRUPT_ENABLE_REGISTER, INT0_INTERRUPT_ENABLE_BIT);
			break;

		case INT0_EXT_INTERRUPT_ANY_LOGICAL_CHANGE:
			CLR_BIT(INT0_INTERRUPT_ENABLE_REGISTER, INT0_INTERRUPT_ENABLE_BIT);
			break;

		case INT0_EXT_INTERRUPT_FALLING_EDGE:
			CLR_BIT(INT0_INTERRUPT_ENABLE_REGISTER, INT0_INTERRUPT_ENABLE_BIT);
			break;

		case INT0_EXT_INTERRUPT_RISING_EDGE:
			CLR_BIT(INT0_INTERRUPT_ENABLE_REGISTER, INT0_INTERRUPT_ENABLE_BIT);
			break;


		case INT1_EXT_INTERRUPT_LOW_LEVEL:
			CLR_BIT(INT1_INTERRUPT_ENABLE_REGISTER, INT1_INTERRUPT_ENABLE_BIT);
			break;

		case INT1_EXT_INTERRUPT_ANY_LOGICAL_CHANGE:
			CLR_BIT(INT1_INTERRUPT_ENABLE_REGISTER, INT1_INTERRUPT_ENABLE_BIT);
			break;


		case INT1_EXT_INTERRUPT_FALLING_EDGE:
			CLR_BIT(INT1_INTERRUPT_ENABLE_REGISTER, INT1_INTERRUPT_ENABLE_BIT);
			break;

		case INT1_EXT_INTERRUPT_RISING_EDGE:
			CLR_BIT(INT1_INTERRUPT_ENABLE_REGISTER, INT1_INTERRUPT_ENABLE_BIT);
			break;


		case INT2_EXT_INTERRUPT_FALLING_EDGE:
			CLR_BIT(INT2_INTERRUPT_ENABLE_REGISTER, INT2_INTERRUPT_ENABLE_BIT);
			break;

		case INT2_EXT_INTERRUPT_RISING_EDGE:
			CLR_BIT(INT2_INTERRUPT_ENABLE_REGISTER, INT2_INTERRUPT_ENABLE_BIT);
			break;

		default:
			ErrorState=0;
			break;
	}
	return ErrorState;
}

