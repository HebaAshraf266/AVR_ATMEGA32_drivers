/*
 *  Name        : DIO_src.c
 *  Description : This file contains functions implementation of DIO
 *  Created on  : Dec 16, 2022
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

/**************************************************************************************************/
/*                                             Includes                                           */
/**************************************************************************************************/
#include "../../SERV/STD_Types.h"
#include "../../SERV/BitMath.h"
#include "DIO_REG.h"
#include "DIO_int.h"


/**************************************************************************************************/
/*                                    Functions implementation                                    */
/**************************************************************************************************/
// Set port DIRECTION
uint8 DIO_u8SetPORTDir(uint8 u8PortIdCopy, uint8 u8DirCopy){
	uint8 errStatus =E_OK;
	switch (u8PortIdCopy){
		case PORT_A : DDRA_REG=u8DirCopy; break; //DDRA = OUTPUT,INPUT
		case PORT_B : DDRB_REG=u8DirCopy; break;
		case PORT_C : DDRC_REG=u8DirCopy; break;
		case PORT_D : DDRD_REG=u8DirCopy; break;
		default     : errStatus =E_NOK  ; break;
	}
	return errStatus;
}

// Set port PORT
// u8ValCopy --> HIGH,LOW
uint8 DIO_u8SetPORTVal(uint8 u8PortIdCopy, uint8 u8ValCopy){
	uint8 errStatus =E_OK;

	switch (u8PortIdCopy){
		case PORT_A : PORTA_REG=u8ValCopy; break; //PORTA = HIGH,LOW  | Enable pull up, disable
		case PORT_B : PORTB_REG=u8ValCopy; break;
		case PORT_C : PORTC_REG=u8ValCopy; break;
		case PORT_D : PORTD_REG=u8ValCopy; break;
		default     : errStatus =E_NOK; break;
		}

	return errStatus;
}


uint8 DIO_u8GetPORTVal(uint8 u8PortIdCopy, uint8 *u8pValCopy){
	uint8 errStatus =E_OK;
	switch (u8PortIdCopy){
		case PORT_A : *u8pValCopy = PINA_REG; break; //PINA = HIGH,LOW
		case PORT_B : *u8pValCopy = PINB_REG; break;
		case PORT_C : *u8pValCopy = PINC_REG; break;
		case PORT_D : *u8pValCopy = PIND_REG; break;
		default     : errStatus =E_NOK; break;
		}
	return errStatus;
}


uint8 DIO_u8EnablePortPullUp (uint8 u8PortIdCopy){
	uint8 errStatus =E_OK;
	uint8 u8PortDirRegAdd [4] ={DDRA_REG,DDRB_REG,DDRC_REG,DDRD_REG};
	uint8 u8PortPortRegAdd [4]={PORTA_REG,PORTB_REG,PORTC_REG,PORTD_REG};
	uint8 i;//No of bits

	if ( u8PortIdCopy >= 0 &&  u8PortIdCopy<=3 ){
		for (i=0; i<8; i++){
			if ( 0==GET_BIT(u8PortDirRegAdd[u8PortIdCopy],i )){
				SET_BIT(u8PortPortRegAdd [u8PortIdCopy],i);
			}

			else{
				//Nothing
			}
		}
	}

	else{
		errStatus =E_NOK;
	}
	return errStatus;
}

// Specific PIN (BIT level)
uint8 DIO_u8SetPinDir(uint8 u8PortIdCopy,uint8 u8PinIdCopy,uint8 u8DirCopy){
	uint8 errStatus =E_OK;
	if(u8PinIdCopy >= PIN_0 && u8PinIdCopy <= PIN_7)
		{
			if(u8DirCopy == INPUT)
			{
				switch (u8PortIdCopy)
					{
					case PORT_A : CLR_BIT(DDRA_REG ,u8PinIdCopy); break;
					case PORT_B : CLR_BIT(DDRB_REG ,u8PinIdCopy); break;
					case PORT_C : CLR_BIT(DDRC_REG ,u8PinIdCopy); break;
					case PORT_D : CLR_BIT(DDRD_REG ,u8PinIdCopy); break;
					default     : errStatus = E_NOK; break;
					}
			}
			else if(u8DirCopy == OUTPUT)
			{
				switch (u8PortIdCopy)
					{
					case PORT_A : SET_BIT(DDRA_REG ,u8PinIdCopy); break;
					case PORT_B : SET_BIT(DDRB_REG ,u8PinIdCopy); break;
					case PORT_C : SET_BIT(DDRC_REG ,u8PinIdCopy); break;
					case PORT_D : SET_BIT(DDRD_REG ,u8PinIdCopy); break;
					default     : errStatus = E_NOK; break;
					}
			}
			else
			{
				errStatus = E_NOK ;
			}

		}
	else
		{
			errStatus = E_NOK ;
		}

return errStatus ;
}

//Set specific PIN in PORT HIGH,LOW or Enable,Disable Pull up resistor
uint8 DIO_u8SetPinVal(uint8 u8PortIdCopy,uint8 u8PinIdCopy ,uint8 u8ValCopy){
	uint8 errStatus =E_OK;

	if ( u8PinIdCopy>=PIN_0 && u8PinIdCopy<=PIN_7 ){
		if( u8ValCopy == HIGH ){
			switch(u8PortIdCopy){
				case PORT_A : SET_BIT( PORTA_REG ,u8PinIdCopy ); break;
				case PORT_B : SET_BIT( PORTB_REG ,u8PinIdCopy ); break;
				case PORT_C : SET_BIT( PORTC_REG ,u8PinIdCopy ); break;
				case PORT_D : SET_BIT( PORTD_REG ,u8PinIdCopy ); break;
				default     : errStatus = E_NOK; break;
			}

		}
		else if ( u8ValCopy == LOW ){
			switch(u8PortIdCopy){
				case PORT_A : CLR_BIT( PORTA_REG ,u8PinIdCopy ) ; break;
				case PORT_B : CLR_BIT( PORTB_REG ,u8PinIdCopy ) ; break;
				case PORT_C : CLR_BIT( PORTC_REG ,u8PinIdCopy ) ; break;
				case PORT_D : CLR_BIT( PORTD_REG ,u8PinIdCopy ) ; break;
				default     : errStatus = E_NOK; break;
			}
		}

		else if (u8ValCopy==TOGGLE){
			switch(u8PortIdCopy){
				case PORT_A : TOGGLE_BIT(PORTA_REG ,u8PinIdCopy) ; break;
				case PORT_B : TOGGLE_BIT(PORTB_REG ,u8PinIdCopy) ; break;
				case PORT_C : TOGGLE_BIT(PORTC_REG ,u8PinIdCopy) ; break;
				case PORT_D : TOGGLE_BIT(PORTD_REG ,u8PinIdCopy) ; break;
				default     : errStatus = E_NOK; break;
			}
		}

		else
			errStatus =E_NOK;
	}
	else
		errStatus =E_NOK;

	return errStatus;
}

//Read specific BIT in PIN register
uint8 DIO_u8GetPinVal( uint8 u8PortIdCopy,uint8 u8PinIdCopy ,uint8 *u8pValCopy ){
	uint8 errStatus =E_OK;
	if ( u8PinIdCopy>=PIN_0 && u8PinIdCopy<=PIN_7 ){

		switch(u8PortIdCopy){
			case PORT_A : *u8pValCopy = GET_BIT(PINA_REG,u8PinIdCopy); break;
			case PORT_B : *u8pValCopy = GET_BIT(PINB_REG,u8PinIdCopy);  break;
			case PORT_C : *u8pValCopy = GET_BIT(PINC_REG,u8PinIdCopy); break;
			case PORT_D : *u8pValCopy = GET_BIT(PIND_REG,u8PinIdCopy); break;
			default : errStatus = E_NOK; break;
			}
		}
	else
		errStatus =E_NOK;

	return errStatus;
}


uint8 DIO_u8EnablePinPullUp (uint8 u8PortIdCopy,uint8 u8PinIdCopy){

	uint8 errStatus =E_OK;
	uint8 u8PortDirRegAdd [4] ={DDRA_REG,DDRB_REG,DDRC_REG,DDRD_REG};
	uint8 u8PortPortRegAdd [4]={PORTA_REG,PORTB_REG,PORTC_REG,PORTD_REG};

	if ( u8PortIdCopy >= 0 &&  u8PortIdCopy<=3 ){
		if (u8PinIdCopy >= PIN_0 && u8PinIdCopy <= PIN_7 ){

			if (0==GET_BIT(u8PortDirRegAdd [u8PortIdCopy],u8PinIdCopy)){
				SET_BIT(u8PortPortRegAdd [u8PortIdCopy],u8PinIdCopy);
			}

			else{
				//Nothing
			}
		}
		else{
				errStatus =E_NOK;
			}
	}

	else{
		errStatus =E_NOK;
	}

	return errStatus;

}


















