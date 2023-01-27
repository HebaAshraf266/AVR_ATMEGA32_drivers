/*
 *  Name        : Interuupt_int.h
 *  Description : This file contains prototypes of Interuupt functions
 *  Created on  : Jan 15, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

/**************************************************************************************************/
/*                                          Includes                                             */
/**************************************************************************************************/
#include "Interrupt_conf.h"

#ifndef MCAL_INTERRUPT_INTERUUPT_INT_H_
#define MCAL_INTERRUPT_INTERUUPT_INT_H_



/**************************************************************************************************/
/*                                    Functions prototypes                                        */
/**************************************************************************************************/
/*
 * Function   : Enable interrupt
 * Parameters : Interrupt number , pointr to function to store int in vector table
 * Return     : Error state
 */
uint8 Interrupt_u8EnableInterrupt(t_InterruptSource u8INT_NumCopy, void (*PtrToHandler)(void));


/*
 * Function   : Disable interrupt
 * Parameters : Interrupt number
 * Return     : Error state
 */
uint8 Interrupt_u8DisableInterrupt(t_InterruptSource u8INT_NumCopy);


/*
 * Function   : Enable GPIE
 * Parameters : void
 * Return     : void
 */
void Interrupt_u8EnableGlobalRegister();


/*
 * Function   : Disable GPIE
 * Parameters : void
 * Return     : void
 */
void Interrupt_u8DisableGlobalRegister();


#endif /* MCAL_INTERRUPT_INTERUUPT_INT_H_ */
