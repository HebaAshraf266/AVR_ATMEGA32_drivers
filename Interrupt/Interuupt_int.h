/*
 * Interuupt_int.h
 *
 *  Created on: Jan 15, 2023
 *      Author: user
 */

#include "Interrupt_conf.h"
#ifndef MCAL_INTERRUPT_INTERUUPT_INT_H_
#define MCAL_INTERRUPT_INTERUUPT_INT_H_

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
