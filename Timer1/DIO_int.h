/*
 *  Name        : DIO_int.c
 *  Description : This file contains functions prototypes of DIO
 *  Created on  : Dec 16, 2022
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

/*--------------------------------------------------Macros start--------------------------------------------------------*/
#define PORT_A		  0
#define PORT_B		  1
#define PORT_C		  2
#define PORT_D	   	  3

#define PIN_0         0
#define PIN_1         1
#define PIN_2         2
#define PIN_3         3
#define PIN_4         4
#define PIN_5         5
#define PIN_6         6
#define PIN_7         7

#define INPUT         0
#define OUTPUT        1

#define LOW           0
#define HIGH          1
#define TOGGLE        2

#define PUE			  1

#define FULL_OUTPUT  0xff
#define FULL_INPUT   0x00

#define E_OK		  0
#define E_NOK         1

/*---------------------------------------------------Macros end----------------------------------------------------------*/

/*****************************************************The whole PORT (8-bit)********************************************/
/*
 * Function   : Set port DIRECTION register
 * Parameters : PortId , value of DIRECTION (I/P, O/P)
 * Return     : Error state
 */
uint8 DIO_u8SetPORTDir(uint8 u8PortIdCopy, uint8 u8DirCopy);

/*
 * Function   : Set PORT register value
 * Parameters : PortId , value of PORT (HIGH, LOW)
 * Return     : Error state
 */
uint8 DIO_u8SetPORTVal(uint8 u8PortIdCopy, uint8 u8ValCopy); //PORT register --> HIGH,LOW or Enable,Disable Pull up resistor

/*
 * Function   : Read PIN register
 * Parameters : PortId , Address of target variable to store pin value
 * Return     : Error state
 */
uint8 DIO_u8GetPORTVal(uint8 u8PortIdCopy, uint8 *u8pValCopy); //Read PIN register


/*
 * Function  : Enable Internal pull up pins for corresponding direction bit
 * Parameter : PortId
 * Return    : error state
 */
uint8 DIO_u8EnablePortPullUp (uint8 u8PortIdCopy);


/*************************************************** Specific PIN (BIT level)*******************************************/
/*
 * Function   : Set pin DIRECTION register
 * Parameters : PortId , PinId, value of DIRECTION (I/P, O/P)
 * Return     : Error state
 */
uint8 DIO_u8SetPinDir(uint8 u8PortIdCopy,uint8 u8PinIdCopy,uint8 u8DirCopy);

/*
 * Function   : Set PORT register for pin (OUTPUT)
 * Parameters : PortId, PinId, value of PORT (HIGH, LOW)
 * Return     : Error state
 */
uint8 DIO_u8SetPinVal(uint8 u8PortIdCopy,uint8 u8PinIdCopy ,uint8 u8ValCopy); //Set specific PIN in PORT HIGH,LOW or Enable,Disable Pull up resistor


/*
 * Function   : Read value of PIN
 * Parameters : PortId, PinId, Address of target variable to store pin value
 * Return     : Error state
 */
uint8 DIO_u8GetPinVal(uint8 u8PortIdCopy,uint8 u8PinIdCopy ,uint8 *u8pValCopy); //Read specific BIT in PIN register


/*
 * Function   : Enable internal pull up for specefic pin
 * Parameters : PortId, PinId
 * Return     : Error state
 */
uint8 DIO_u8EnablePinPullUp (uint8 u8PortIdCopy,uint8 u8PinIdCopy);

#endif /* DIO_INT_H_ */


